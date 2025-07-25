import sys
from PyQt5 import QtWidgets, uic

questions = [
    {
        "text": "자주 어지럽나요?",
        "options": [
            "1주일에 5번 이상",
            "1주일에 3~4번",
            "1주일에 1~2번",
            "어지럽지 않다"
        ],
        "deduct": {
            "1주일에 5번 이상": 10,
            "1주일에 3~4번": 8,
            "1주일에 1~2번": 4,
            "어지럽지 않다": 0
        },
        "advice": {
            "1주일에 5번 이상": "어지럼증이 자주 있다면, 철분이 부족할 수 있어요! 철분이 풍부한 음식(시금치, 소고기, 달걀노른자 등)을 자주 먹고, 필요하다면 어린이용 철분 영양제를 부모님과 상의해보세요. 물도 충분히 마시고, 아침을 꼭 챙겨 먹는 습관을 들이면 좋아요!",
            "1주일에 3~4번": "어지럼증이 종종 있다면, 식사와 수분 섭취를 잘 챙기고, 규칙적으로 운동해보세요! 철분, 비타민C가 풍부한 과일(딸기, 오렌지 등)도 함께 먹으면 도움이 돼요.",
            "1주일에 1~2번": "가끔 어지럽다면, 너무 걱정하지 않아도 돼요! 하지만 식사를 거르지 않고, 다양한 음식을 골고루 먹는 습관을 들이면 더 건강해질 수 있어요",
            "어지럽지 않다": "정말 훌륭해요! 건강관리가 아주 잘 되고 있어요. 지금처럼 규칙적인 식사와 운동을 계속하면 멋진 건강을 유지할 수 있어요!"
        }
    },
    {
        "text": "평소에 눈이 흔들리나요?",
        "options": ["예", "아니오"],
        "deduct": {
            "예": 10,
            "아니오": 0
        },
        "advice": {
            "예": "눈이 흔들린다면, 눈 건강을 위해 비타민A와 오메가-3가 풍부한 음식을 먹어보세요! 당근, 연어, 고등어, 시금치 등이 좋아요. 눈이 피로하지 않도록 스마트폰이나 TV를 오래 보지 않도록 주의해요. 필요하다면 부모님과 함께 영양제도 상담해보세요.",
            "아니오": "눈이 흔들리지 않는다면 아주 좋아요! 지금처럼 눈 건강을 잘 지키고, 밝은 곳에서 책을 읽고, 눈을 자주 쉬게 해주세요. 당근, 달걀, 우유 등도 꾸준히 먹으면 더 좋아요!"
        }
    },
    {
        "text": "감기에 자주 걸리십니까?",
        "options": [
            "1달에 2번 이하",
            "1달에 3번 이상 5번 이하",
            "1달에 6번 이상"
        ],
        "deduct": {
            "1달에 2번 이하": 0,
            "1달에 3번 이상 5번 이하": 5,
            "1달에 6번 이상": 10
        },
        "advice": {
            "1달에 2번 이하": "면역력이 아주 좋아요! 지금처럼 과일, 채소, 단백질을 골고루 먹고, 손을 자주 씻는 습관을 계속 유지하세요.",
            "1달에 3번 이상 5번 이하": "감기에 자주 걸린다면, 비타민C와 아연이 풍부한 음식을 더 챙겨 먹어보세요! 귤, 딸기, 키위, 견과류, 해산물 등이 도움이 돼요. 필요하다면 어린이용 종합비타민도 부모님과 상의해볼 수 있어요.",
            "1달에 6번 이상": "감기에 너무 자주 걸린다면, 면역력을 키우는 것이 중요해요! 비타민C, 아연, 프로바이오틱스가 들어있는 음식(요거트, 김치, 과일 등)을 자주 먹고, 충분한 수면과 손 씻기를 꼭 실천하세요. 필요하다면 영양제도 고려해보세요."
        }
    },
    {
        "text": "피부가 건조하거나 손톱이 자주 부러지나요?",
        "options": ["예", "아니오"],
        "deduct": {
            "예": 10,
            "아니오": 0
        },
        "advice": {
            "예": "피부와 손톱 건강을 위해 비타민A, 비타민E, 오메가-3가 풍부한 음식을 먹어보세요! 견과류, 연어, 아보카도, 당근, 달걀 등이 좋아요. 물도 충분히 마시고, 손톱을 깨물지 않도록 주의해요. 필요하다면 어린이용 종합비타민도 도움이 될 수 있어요.",
            "아니오": "피부와 손톱이 건강하다니 정말 멋져요! 지금처럼 다양한 음식을 골고루 먹고, 손을 깨끗이 씻는 습관을 계속 유지하세요."
        }
    },
    {
        "text": "변비에 자주 걸리시나요?",
        "options": [
            "2주에 2번 이하",
            "2주에 3~4번",
            "2주에 5번",
            "2주에 6번 이상"
        ],
        "deduct": {
            "2주에 2번 이하": 0,
            "2주에 3~4번": 4,
            "2주에 5번": 8,
            "2주에 6번 이상": 10
        },
        "advice": {
            "2주에 2번 이하": "배변 습관이 아주 좋아요! 지금처럼 물을 자주 마시고, 채소와 과일을 꾸준히 먹으면 건강한 장을 유지할 수 있어요.",
            "2주에 3~4번": "가끔 변비가 있다면, 식이섬유가 풍부한 음식(고구마, 바나나, 사과, 현미 등)을 더 챙겨 먹어보세요! 물을 충분히 마시고, 규칙적으로 운동하면 더 좋아요.",
            "2주에 5번": "변비가 자주 있다면, 식이섬유와 유산균이 풍부한 음식을 꼭 챙겨 먹고, 화장실에 가고 싶을 때 참지 마세요! 요거트, 김치, 바나나, 오트밀 등이 도움이 돼요. 필요하다면 어린이용 유산균 영양제도 고려해보세요.",
            "2주에 6번 이상": "변비가 너무 자주 있다면, 식습관을 꼭 바꿔야 해요! 채소, 과일, 통곡물, 유산균이 풍부한 음식을 많이 먹고, 물을 자주 마시세요. 운동도 꾸준히 하면 장 건강에 큰 도움이 돼요. 필요하다면 부모님과 함께 유산균을 비롯한 영양제도 상담해보세요."
        }
    }
]

class HealthSurveyApp(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        uic.loadUi("sample.ui", self)

        self.questions = questions
        self.total_score = 100
        self.current_index = 0
        self.answers = [None] * len(self.questions)

        self.labelQnum = self.findChild(QtWidgets.QLabel, 'labelQnum')
        self.labelQuestion = self.findChild(QtWidgets.QLabel, 'labelQuestion')

        self.optionButtons = []
        for i in range(1, 5):
            btn = self.findChild(QtWidgets.QRadioButton, f'radioButton{i}')
            if btn:
                self.optionButtons.append(btn)

        self.btnPrev = self.findChild(QtWidgets.QPushButton, 'btnPrev')
        self.btnNext = self.findChild(QtWidgets.QPushButton, 'btnNext')

        self.btnPrev.clicked.connect(self.go_prev)
        self.btnNext.clicked.connect(self.go_next)

        self.load_question()

    def load_question(self):
        q = self.questions[self.current_index]
        self.labelQnum.setText(f"문제 {self.current_index + 1} / {len(self.questions)}")
        self.labelQuestion.setText(q['text'])

        options = q['options']
        for i, btn in enumerate(self.optionButtons):
            if i < len(options):
                btn.setText(options[i])
                btn.show()
                btn.setChecked(False)
            else:
                btn.hide()

        prev_answer = self.answers[self.current_index]
        if prev_answer:
            for btn in self.optionButtons:
                if btn.text() == prev_answer:
                    btn.setChecked(True)
                    break

        self.btnPrev.setEnabled(self.current_index > 0)
        if self.current_index == len(self.questions) - 1:
            self.btnNext.setText("결과 보기")
        else:
            self.btnNext.setText("다음 문제")

    def go_prev(self):
        if self.current_index > 0:
            self.current_index -= 1
            self.load_question()

    def go_next(self):
        selected = None
        for btn in self.optionButtons:
            if btn.isVisible() and btn.isChecked():
                selected = btn.text()
                break

        if not selected:
            QtWidgets.QMessageBox.warning(self, "경고", "답변을 선택해 주세요.")
            return

        self.answers[self.current_index] = selected

        if self.current_index < len(self.questions) - 1:
            self.current_index += 1
            self.load_question()
        else:
            self.show_result()

    def show_result(self):
        score = 100
        advices = []
        for i, answer in enumerate(self.answers):
            q = self.questions[i]
            deduct = q['deduct'].get(answer, 0)
            if deduct > 0:
                score -= deduct
                advices.append(f"문제 {i+1}: {q['advice'][answer]} (감점 {deduct}점)")

        if score < 0:
            score = 0

        advice_text = "\n\n".join(advices) if advices else "감점된 항목이 없습니다. 매우 건강합니다!"

        QtWidgets.QMessageBox.information(self, "결과", f"최종 점수: {score}점\n\n조언:\n{advice_text}")

        # 초기화 후 첫 문제로 돌아가기
        self.current_index = 0
        self.answers = [None] * len(self.questions)
        self.load_question()

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    window = HealthSurveyApp()
    window.show()
    sys.exit(app.exec_())