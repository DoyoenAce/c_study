import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QPushButton, QVBoxLayout

class HealthTest(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("건강 닥터 테스트")

        self.questions = [
            "자주 어지럽나요?", #x    pygame.cursors.load_xbm(cursorfile, maskfile)
            "피부가 갈라지거나 손톱이 부러지나요?",
            "평소에 눈 주위에서 떨림이 느껴지나요?",
            "눈이 침침하신가요?",
            "평소에 무기력한가요?",
            "감기에 자주 걸리나요?",
            "배가 자주 아픈가요?",
            "콧물이 많나요?",
            "하루에 평균 6시간 이하로 자나요?",
            "하루에 핸드폰을 2시간 이상 보나요?"
        ]

        self.score = 100
        self.current = 0

        # 위젯 생성
        self.label = QLabel("건강 테스트를 시작합니다!")
        self.btn_yes = QPushButton("네")
        self.btn_no = QPushButton("아니오")

        # 레이아웃 설정
        layout = QVBoxLayout()
        layout.addWidget(self.label)
        layout.addWidget(self.btn_yes)
        layout.addWidget(self.btn_no)
        self.setLayout(layout)

        # 버튼에 기능 연결
        self.btn_yes.clicked.connect(lambda: self.answer(True))
        self.btn_no.clicked.connect(lambda: self.answer(False))

        self.show_question()

    def show_question(self):
        if self.current < len(self.questions):
            self.label.setText(self.questions[self.current])
        else:
            self.show_result()

    def answer(self, is_yes):
        if is_yes:
            self.score -= 10
        self.current += 1
        self.show_question()

    def show_result(self):
        if self.score == 100:
            result = "딱 좋아요! 이대로만 건강 관리 하면 되요!"
        elif self.score >= 70:
            result = "지금도 나쁘지 않지만 건강점수 100점을 향해 노력해 볼까요?"
        elif self.score >= 40:
            result = "노력이 필요해요! 영양 섭취와 운동에 신경 쓰는 건 어떨까요?"
        elif self.score >= 10:
            result = "건강 상태가 안 좋아요! 병원을 방문해보는 것이 좋겠네요."
        else:
            result = "건강 상태가 심각해요. 병원을 가는 것이 좋겠네요."

        final_message = f"건강 테스트 완료!\n당신의 건강 점수는 {self.score}점 입니다.\n{result}"
        self.label.setText(final_message)
        self.btn_yes.hide()
        self.btn_no.hide()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = HealthTest()
    window.show()
    sys.exit(app.exec_())