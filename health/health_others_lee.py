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
