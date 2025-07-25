import sys
from PyQt5 import QtWidgets, uic
from PyQt5.QtGui import QFont

questions = [
    {
        "text": "1. 자주 어지럽나요?",
        "options": [
            "1주일에 5번 이상",
            "1주일에 3~4번",
            "1주일에 1~2번",
            "어지럽지 않다"
        ],
        "deduct": {
            "1주일에 5번 이상": (10, "빈혈일 수 있으니 병원 검진을 권장합니다."),
            "1주일에 3~4번": (7, "자주 어지럽다면 철분 섭취를 늘려보세요."),
            "1주일에 1~2번": (3, "가끔 어지럼증이 있다면 수분 섭취를 늘려보세요.")
        }
    },
    {
        "text": "2. 식사는 하루 몇 끼 하시나요?",
        "options": ["1끼 이하", "2끼", "3끼", "4끼 이상"],
        "deduct": {
            "1끼 이하": (10, "너무 적은 식사는 건강에 해롭습니다. 규칙적인 식사를 하세요."),
            "2끼": (3, "가능하면 3끼를 고르게 섭취하는 것이 좋습니다."),
            "4끼 이상": (2, "과식은 피하는 것이 좋습니다.")
        }
    },
    {
        "text": "3. 하루 평균 수면 시간은?",
        "options": ["4시간 이하", "5~6시간", "7~8시간", "9시간 이상"],
        "deduct": {
            "4시간 이하": (10, "수면이 부족하면 면역력이 저하될 수 있습니다."),
            "5~6시간": (5, "적절한 수면 시간을 유지해보세요."),
            "9시간 이상": (3, "과도한 수면은 건강에 해로울 수 있습니다.")
        }
    },
    {
        "text": "4. 평소 운동을 자주 하나요?",
        "options": ["거의 안 함", "주 1~2회", "주 3~4회", "주 5회 이상"],
        "deduct": {
            "거의 안 함": (10, "운동 부족은 만성질환 위험을 높입니다."),
            "주 1~2회": (5, "조금 더 자주 운동해보세요.")
        }
    },
    {
        "text": "5. 스트레스를 자주 받나요?",
        "options": ["항상 그렇다", "자주 그렇다", "가끔 그렇다", "거의 없다"],
        "deduct": {
            "항상 그렇다": (10, "스트레스 관리를 위해 취미 활동을 해보세요."),
            "자주 그렇다": (7, "마음을 편하게 할 방법을 찾아보세요."),
            "가끔 그렇다": (3, "가벼운 명상이나 산책이 도움이 됩니다.")
        }
    },
    {
        "text": "6. 평소에 아침 식사를 하시나요?",
        "options": ["예", "아니오"],
        "deduct": {
            "아니오": (5, "아침 식사는 신진대사와 집중력을 높이는 데 중요합니다.")
        }
    },
    {
        "text": "7. 인스턴트 식품을 얼마나 자주 드시나요?",
        "options": ["매일", "주 4~5회", "주 1~2회", "거의 안 먹음"],
        "deduct": {
            "매일": (10, "인스턴트 식품은 나트륨과 지방 함량이 높아 건강에 해롭습니다."),
            "주 4~5회": (7, "인스턴트 섭취를 줄이면 건강에 도움이 됩니다."),
            "주 1~2회": (3, "섭취 빈도를 조금 더 줄여보세요.")
        }
    },
    {
        "text": "8. 하루에 물을 얼마나 마시나요?",
        "options": ["1컵 이하", "2~3컵", "4~6컵", "7컵 이상"],
        "deduct": {
            "1컵 이하": (10, "수분 부족은 피로와 두통의 원인이 됩니다."),
            "2~3컵": (5, "물을 더 자주 마셔보세요."),
            "4~6컵": (2, "조금만 더 마시면 좋습니다.")
        }
    },
    {
        "text": "9. 과일이나 채소를 자주 드시나요?",
        "options": ["예", "아니오"],
        "deduct": {
            "아니오": (5, "비타민과 섬유소를 위해 채소와 과일을 충분히 섭취하세요.")
        }
    },
    {
        "text": "10. 평소 자세가 바르신가요?",
        "options": ["예", "아니오"],
        "deduct": {
            "아니오": (5, "나쁜 자세는 척추 건강에 악영향을 미칩니다. 올바른 자세를 유지하세요.")
        }
    },
    {
        "text": "11. 패스트푸드나 탄산음료를 얼마나 섭취하나요?",
        "options": ["1", "2", "3", "4"],
        "deduct": {
            "1": (10, "매일 섭취는 고혈압, 당뇨병 위험이 큽니다. 줄여보세요."),
            "2": (8, "섭취 간격을 더 늘리고 식단을 조절하세요."),
            "3": (4, "섭취 조절을 잘하고 계십니다."),
            "4": (0, "패스트푸드 섭취를 잘 조절하고 계십니다.")
        }
    },
    {
        "text": "12. 등 푸른 생선을 얼마나 자주 먹나요?",
        "options": ["1", "2", "3", "4"],
        "deduct": {
            "1": (4, "오메가-3가 풍부해 지금처럼 유지하면 좋습니다."),
            "2": (0, "지금처럼 주기적으로 섭취하면 좋습니다."),
            "3": (6, "섭취량이 약간 부족할 수 있습니다. 늘려보세요."),
            "4": (10, "생선 섭취를 늘려보세요. 오메가-3가 중요합니다.")
        }
    },
    {
        "text": "13. 하루 스마트폰 사용 시간은?",
        "options": ["1", "2", "3", "4"],
        "deduct": {
            "1": (0, "스마트폰 사용을 잘 관리하고 계십니다."),
            "2": (4, "눈 피로를 줄이는 설정을 사용해보세요."),
            "3": (8, "스마트폰 사용 시간을 줄이는 것이 좋습니다."),
            "4": (10, "디지털 디톡스를 시도해보세요.")
        }
    },
    {
        "text": "14. 하루 중 스트레스를 얼마나 받나요?",
        "options": ["1", "2", "3", "4"],
        "deduct": {
            "1": (0, "스트레스 관리를 잘 하고 계시네요."),
            "2": (4, "운동이나 취미 활동을 통해 관리하세요."),
            "3": (8, "스트레스 해소 루틴이 필요합니다."),
            "4": (10, "명상이나 산책을 적극 활용해보세요.")
        }
    },
    {
        "text": "15. 하루 평균 운동 빈도는?",
        "options": ["1", "2", "3", "4"],
        "deduct": {
            "1": (10, "운동 부족입니다. 걷기부터 시작해보세요."),
            "2": (8, "주 2~3회 근력운동을 추가해보세요."),
            "3": (4, "좋은 습관입니다. 계속 유지하세요."),
            "4": (0, "매우 좋은 운동 습관입니다.")
        }
    }
]

class SurveyApp(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        uic.loadUi("sample.ui", self)
        self.current = 0
        self.score = 100
        self.selected_answers = [None] * len(questions)
        self.option_buttons = [self.option1, self.option2, self.option3, self.option4]
        self.submit_button.setVisible(False)

        self.prev_button.clicked.connect(self.prev_question)
        self.next_button.clicked.connect(self.next_question)
        self.submit_button.clicked.connect(self.show_results)

        self.show_question()

    def show_question(self):
        q = questions[self.current]
        self.question_number_label.setText(f"문제 {self.current + 1}")
        self.question_text_label.setText(q["text"])
        for i, btn in enumerate(self.option_buttons):
            if i < len(q["options"]):
                btn.setText(q["options"][i])
                btn.setVisible(True)
                btn.setChecked(False)
            else:
                btn.setVisible(False)

        selected = self.selected_answers[self.current]
        if selected is not None:
            for btn in self.option_buttons:
                if btn.text() == selected:
                    btn.setChecked(True)

        self.prev_button.setEnabled(self.current > 0)
        self.next_button.setVisible(self.current < len(questions) - 1)
        self.submit_button.setVisible(self.current == len(questions) - 1)

    def save_answer(self):
        for btn in self.option_buttons:
            if btn.isVisible() and btn.isChecked():
                self.selected_answers[self.current] = btn.text()
                return True
        return False

    def next_question(self):
        if not self.save_answer():
            QtWidgets.QMessageBox.warning(self, "알림", "답변을 선택해주세요.")
            return
        self.current += 1
        self.show_question()

    def prev_question(self):
        self.current -= 1
        self.show_question()

    def show_results(self):
        if not self.save_answer():
            QtWidgets.QMessageBox.warning(self, "알림", "답변을 선택해주세요.")
            return

        total_deduction = 0
        advices = []
        for i, ans in enumerate(self.selected_answers):
            q = questions[i]
            if "deduct" in q and ans in q["deduct"]:
                deduct, advice = q["deduct"][ans]
                total_deduction += deduct
                advices.append(f"{q['text']}: {advice}")

        final_score = self.score - total_deduction
        message = f"총점: {final_score}점\n\n"
        if advices:
            message += "조언:\n" + "\n".join(advices)
        else:
            message += "건강을 잘 관리하고 계시네요!"

        QtWidgets.QMessageBox.information(self, "결과", message)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    font = QFont("Malgun Gothic")
    app.setFont(font)
    window = SurveyApp()
    window.show()
    sys.exit(app.exec_())
    
    
