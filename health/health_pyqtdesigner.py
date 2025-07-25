from PyQt5 import QtWidgets, uic
import sys

# 감점 매핑 (질문 번호와 선택지 번호로 감점값을 매핑)
deduction_map = {
    "dizzy": [10, 8, 4, 0],
    "eye_shake": [10, 0],
    "cold": [0, 5, 10],
    "skin": [10, 0],
    "constipation": [0, 4, 8, 10],
    "sleep": [10, 8, 6, 0],
    "breakfast": [0, 10],
    "fruits": [10, 8, 4, 0],
    "fastfood": [10, 8, 4, 0],
    "fish": [10, 6, 0, 4],
    "phone": [0, 4, 8, 10],
    "stress": [0, 4, 8, 10],
    "exercise": [10, 8, 4, 0]
}

# 조언 텍스트 매핑 (질문 이름과 선택지 인덱스로 매핑)
advice_map = {
    "dizzy": [
        "어지럼증이 자주 있다면, 철분이 부족할 수 있어요! 시금치, 소고기, 달걀노른자 등 철분이 풍부한 음식을 자주 먹고, 필요하면 어린이용 철분 영양제를 부모님과 상의해보세요.",
        "어지럼증이 종종 있다면, 식사와 수분 섭취를 잘 챙기고 규칙적으로 운동해보세요. 철분, 비타민C가 풍부한 과일도 좋습니다.",
        "가끔 어지럽다면 너무 걱정하지 않아도 돼요! 식사를 거르지 않고 다양한 음식을 먹는 습관을 들이세요.",
        "정말 훌륭해요! 건강관리가 아주 잘 되고 있어요."
    ],
    "eye_shake": [
        "눈이 흔들린다면 비타민A와 오메가-3가 풍부한 음식을 먹어보세요! 당근, 연어, 시금치가 도움이 됩니다.",
        "눈이 흔들리지 않는다면 아주 좋아요! 눈 건강을 계속 잘 지켜주세요."
    ],
    # 이하 생략... 전체 조언 내용을 동일한 방식으로 추가 가능
}

class HealthSurveyApp(QtWidgets.QMainWindow):
    def __init__(self):
        super(HealthSurveyApp, self).__init__()
        uic.loadUi("survey.ui", self)  # Qt Designer에서 만든 .ui 파일 로드

        self.pushButton_submit.clicked.connect(self.calculate_score)

    def calculate_score(self):
        score = 100
        advice_text = ""

        # 질문 항목을 UI에서 가져오기 (예시로 comboBox, radioButton 그룹 사용)
        dizzy_index = self.comboBox_dizzy.currentIndex()
        score -= deduction_map["dizzy"][dizzy_index]
        advice_text += f"\n[어지럼증] {advice_map['dizzy'][dizzy_index]}\n"

        eye_index = 0 if self.radioButton_eye_yes.isChecked() else 1
        score -= deduction_map["eye_shake"][eye_index]
        advice_text += f"\n[눈 흔들림] {advice_map['eye_shake'][eye_index]}\n"

        # 나머지 항목도 동일한 방식으로 연결 (cold, skin, constipation, ...)
        # UI 요소 이름은 Qt Designer에서 지정한 것과 동일해야 함

        # 점수와 조언 표시
        self.label_score.setText(f"총 점수: {score}점 / 100점")
        self.textBrowser_advice.setText(advice_text)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = HealthSurveyApp()
    window.show()
    sys.exit(app.exec_())