def get_score_and_advice():
    total_deduction = 0
    print("===== 건강 설문을 시작합니다! =====\n")

    # 어지럼증
    dizzy = input("자주 어지럽나요?\n1) 1주일에 5번 이상\n2) 1주일에 3~4번\n3) 1주일에 1~2번\n4) 어지럽지 않다\n선택 (1~4): ")
    dizzy_scores = [10, 8, 4, 0]
    total_deduction += dizzy_scores[int(dizzy)-1]

    # 눈 흔들림
    eye = input("평소에 눈이 흔들리나요? (예/아니오): ").strip()
    if eye == "예":
        total_deduction += 10

    # 감기
    cold = input("감기에 자주 걸리십니까?\n1) 1달에 2번 이하\n2) 1달에 3~5번\n3) 1달에 6번 이상\n선택 (1~3): ")
    cold_scores = [0, 5, 10]
    total_deduction += cold_scores[int(cold)-1]

    # 피부/손톱
    skin = input("피부가 건조하거나 손톱이 자주 부러지나요? (예/아니오): ").strip()
    if skin == "예":
        total_deduction += 10

    # 변비
    constipation = input("변비에 자주 걸리시나요?\n1) 2주에 2번 이하\n2) 2주에 3~4번\n3) 2주에 5번\n4) 2주에 6번 이상\n선택 (1~4): ")
    constipation_scores = [0, 4, 8, 10]
    total_deduction += constipation_scores[int(constipation)-1]

    # 수면
    sleep = input("하루에 평균 몇 시간을 자나요?\n1) 5시간 미만\n2) 5~7시간 미만\n3) 7~8시간 미만\n4) 8시간 이상\n선택 (1~4): ")
    sleep_scores = [10, 8, 6, 0]
    total_deduction += sleep_scores[int(sleep)-1]

    # 아침 식사
    breakfast = input("아침을 매일 먹나요? (예/아니오): ").strip()
    if breakfast == "아니오":
        total_deduction += 10

    # 과일/야채
    fruits = input("과일이나 야채를 얼마나 섭취하나요?\n1) 전혀 안 먹는다\n2) 하루 1회\n3) 하루 2~3회\n4) 하루 4회 이상\n선택 (1~4): ")
    fruits_scores = [10, 8, 4, 0]
    total_deduction += fruits_scores[int(fruits)-1]

    # 패스트푸드
    fastfood = input("패스트푸드나 탄산음료를 얼마나 섭취하나요?\n1) 거의 매일\n2) 주 3~4회\n3) 주 1~2회\n4) 거의 안 먹는다\n선택 (1~4): ")
    fastfood_scores = [10, 8, 4, 0]
    total_deduction += fastfood_scores[int(fastfood)-1]

    # 생선류
    fish = input("등 푸른 생선을 얼마나 자주 먹나요?\n1) 일주일에 한 번도 안 먹는다\n2) 일주일에 1번\n3) 2~3번\n4) 4번 이상\n선택 (1~4): ")
    fish_scores = [10, 6, 0, 4]
    total_deduction += fish_scores[int(fish)-1]

    # 스마트폰 사용
    phone = input("하루에 스마트폰을 얼마나 사용하나요?\n1) 1시간 이하\n2) 2~3시간\n3) 3~4시간\n4) 5시간 이상\n선택 (1~4): ")
    phone_scores = [0, 4, 8, 10]
    total_deduction += phone_scores[int(phone)-1]

    # 스트레스
    stress = input("하루 중 스트레스를 얼마나 받나요?\n1) 거의 없음\n2) 조금 받는다\n3) 많이 받는다\n4) 매우 많이 받는다\n선택 (1~4): ")
    stress_scores = [0, 4, 8, 10]
    total_deduction += stress_scores[int(stress)-1]

    # 운동
    exercise = input("일주일에 운동을 얼마나 하나요?\n1) 거의 하지 않는다\n2) 1~2회\n3) 3~4회\n4) 5회 이상\n선택 (1~4): ")
    exercise_scores = [10, 8, 4, 0]
    total_deduction += exercise_scores[int(exercise)-1]

    print("\n==== 설문 완료! ====")
    print(f"총 감점: {total_deduction}점")

    # 결과 분석
    if total_deduction <= 20:
        print("💪 건강 수준: 아주 좋아요! 지금처럼만 유지하세요!")
    elif total_deduction <= 40:
        print("😊 건강 수준: 나쁘지 않지만, 몇 가지 생활 습관을 개선해보세요!")
    elif total_deduction <= 60:
        print("⚠️ 건강 수준: 주의가 필요해요. 조언을 잘 따라보세요!")
    else:
        print("🚨 건강 수준: 건강 습관을 꼭 바꿔야 해요! 도연이의 조언을 따라보세요!")

if __name__ == "__main__":
    get_score_and_advice()
