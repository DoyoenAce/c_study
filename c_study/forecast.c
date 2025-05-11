#include <WiFi.h>
#include <HTTPClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>

// Wi-Fi 네트워크 정보
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// NTP 서버를 설정합니다.
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 9 * 3600, 60000); // 한국 시간대는 UTC+9, 60초마다 업데이트

// API 정보
const char* serverNameBase1 = "https://apihub.kma.go.kr/api/typ02/openApi/HealthWthrIdxServiceV2/getOakPollenRiskIdxV2";
const char* serverNameBase2 = "https://apihub.kma.go.kr/api/typ02/openApi/HealthWthrIdxServiceV2/getPinePollenRiskIdxV2";
const char* serverNameBase3 = "https://apihub.kma.go.kr/api/typ02/openApi/HealthWthrIdxServiceV2/getWeedsPollenRiskndxV2";

const char* serverNameBase4 = "http://api.openweathermap.org/data/2.5/air_pollution/forecast";

const char* authKey = "your_auth_key"; // 기상청 API 키
const char* apiKeyOpenWeather = "your_openweather_api_key";  // OpenWeatherMap API 키

const char* areaNo = "1100000000"; // 서울 지역코드(기상청api)

// 서울 위도, 경도(Openweathermap)
const char* lat = "37.5683";
const char* lon = "126.9778";


void setup() {
  // 시리얼 통신을 시작합니다.
  Serial.begin(115200);
  
  // Wi-Fi 연결을 시작합니다.
  WiFi.begin(ssid, password);
  
  // Wi-Fi가 연결될 때까지 기다립니다.
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  // NTP 클라이언트를 시작합니다.
  timeClient.begin();
}

void loop() {
  // 네트워크 시간 업데이트
  timeClient.update();
  
  // 현재 시간을 얻습니다.
  unsigned long epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  int year = ptm->tm_year + 1900;
  int month = ptm->tm_mon + 1;
  int day = ptm->tm_mday;
  int hour = ptm->tm_hour;

  // time 변수 형식 설정 (예: 2024061914)
  char timeBuffer[13];
  snprintf(timeBuffer, sizeof(timeBuffer), "%04d%02d%02d%02d", year, month, day, hour);

  // 각 API 호출 및 출력 함수
  callAndPrintAPI(serverNameBase1, "꽃가루농도위험지수(참나무)", timeBuffer);
  callAndPrintAPI(serverNameBase2, "꽃가루농도위험지수(소나무)", timeBuffer);
  callAndPrintAPI(serverNameBase3, "꽃가루농도위험지수(잡초)", timeBuffer);
  callAndPrintAirPollutionAPI(serverNameBase4, "공기 오염 지수", lat, lon, apiKeyOpenWeather);
  
  // 주기적으로 호출 (예: 1시간마다)
  delay(3600000); // 1시간 (3600초) 지연
}

void callAndPrintAPI(const char* serverNameBase, const char* apiName, const char* timeBuffer) {
  // 전체 서버 URL을 구성합니다.
  char serverName[512];
  snprintf(serverName, sizeof(serverName), "%s?numOfRows=10&pageNo=1&dataType=JSON&areaNo=%s&time=%s&authKey=%s",
           serverNameBase, areaNo, timeBuffer, authKey);
  
  // HTTP 요청을 보냅니다.
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // 요청 URL을 설정합니다.
    http.begin(serverName);
    
    // HTTP GET 요청을 보냅니다.
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      // 응답을 읽습니다.
      String payload = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(payload);
      
      // JSON 파싱
      DynamicJsonDocument doc(4096);
      deserializeJson(doc, payload);

      // 출력 데이터
      Serial.printf("\nAPI: %s\n", apiName);
      Serial.println("출력 결과:");
      Serial.printf("numOfRows: %s (한 페이지 결과 수)\n", doc["response"]["body"]["numOfRows"].as<String>().c_str());
      Serial.printf("pageNo: %s (페이지 번호)\n", doc["response"]["body"]["pageNo"].as<String>().c_str());
      Serial.printf("totalCount: %s (데이터 총 개수)\n", doc["response"]["body"]["totalCount"].as<String>().c_str());
      Serial.printf("resultCode: %s (응답메시지 코드)\n", doc["response"]["header"]["resultCode"].as<String>().c_str());
      Serial.printf("resultMsg: %s (응답메시지 내용)\n", doc["response"]["header"]["resultMsg"].as<String>().c_str());
      Serial.printf("dataType: %s (데이터 타입)\n", doc["response"]["body"]["dataType"].as<String>().c_str());
      Serial.printf("areaNo: %s (지점코드)\n", doc["response"]["body"]["items"]["item"][0]["areaNo"].as<String>().c_str());
      Serial.printf("date: %s (발표시간)\n", doc["response"]["body"]["items"]["item"][0]["date"].as<String>().c_str());
      Serial.printf("today: %s (오늘 예측값)\n", doc["response"]["body"]["items"]["item"][0]["today"].as<String>().c_str());
      Serial.printf("tomorrow: %s (내일 예측값)\n", doc["response"]["body"]["items"]["item"][0]["tomorrow"].as<String>().c_str());
      Serial.printf("todayaftertomorrow: %s (모레 예측값)\n", doc["response"]["body"]["items"]["item"][0]["todayaftertomorrow"].as<String>().c_str());
      
    } else {
      Serial.print("Error on HTTP request: ");
      Serial.println(httpResponseCode);
    }
    
    // HTTP 연결을 종료합니다.
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}

void callAndPrintAirPollutionAPI(const char* serverNameBase, const char* apiName, const char* lat, const char* lon, const char* apiKey) {
  // 전체 서버 URL을 구성합니다.
  char serverName[512];
  snprintf(serverName, sizeof(serverName), "%s?lat=%s&lon=%s&appid=%s",
           serverNameBase, lat, lon, apiKey);
  
  // HTTP 요청을 보냅니다.
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // 요청 URL을 설정합니다.
    http.begin(serverName);
    
    // HTTP GET 요청을 보냅니다.
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      // 응답을 읽습니다.
      String payload = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(payload);
      
      // JSON 파싱
      DynamicJsonDocument doc(4096);
      deserializeJson(doc, payload);

      // 출력 데이터
      Serial.printf("\nAPI: %s\n", apiName);
      Serial.println("출력 결과:");
      for (JsonObject obj : doc["list"].as<JsonArray>()) {
        unsigned long dt = obj["dt"];
        time_t t = dt;
        struct tm *timeinfo = localtime(&t);
        char buffer[25];
        strftime(buffer, 25, "%Y-%m-%d %H:%M:%S", timeinfo);
        
        Serial.printf("Time: %s\n", buffer);
        Serial.printf("AQI: %s\n", getAQIExplanation(obj["main"]["aqi"].as<int>()));
        Serial.printf("CO: %.2f\n", obj["components"]["co"].as<float>());
        Serial.printf("NO: %.2f\n", obj["components"]["no"].as<float>());
        Serial.printf("NO2: %.2f\n", obj["components"]["no2"].as<float>());
        Serial.printf("O3: %.2f\n", obj["components"]["o3"].as<float>());
        Serial.printf("SO2: %.2f\n", obj["components"]["so2"].as<float>());
        Serial.printf("PM2.5: %.2f\n", obj["components"]["pm2_5"].as<float>());
        Serial.printf("PM10: %.2f\n", obj["components"]["pm10"].as<float>());
        Serial.printf("NH3: %.2f\n", obj["components"]["nh3"].as<float>());
        Serial.println();
      }
      
    } else {
      Serial.print("Error on HTTP request: ");
      Serial.println(httpResponseCode);
    }
    
    // HTTP 연결을 종료합니다.
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}

const char* getAQIExplanation(int aqi) {
  switch (aqi) {
    case 1: return "Good";
    case 2: return "Fair";
    case 3: return "Moderate";
    case 4: return "Poor";
    case 5: return "Very Poor";
    default: return "Unknown";
  }
}