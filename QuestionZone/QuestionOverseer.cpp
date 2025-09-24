#include "QuestionOverseer.h"

QuestionOverseer::QuestionOverseer(QWidget *parent, Algorithm* algorithm)
    : ui(new Ui::QuestionOverseer)
{
    ui->setupUi(this);
    this->algorithm = algorithm;

    nextQuestion(); // trigger the next question slot early, bypasses the signal and slot system, yes this is legal
}

void QuestionOverseer::nextQuestion() {
    Question nextQuestionObj = algorithm->nextQuestion();

    cQVariety = nextQuestionObj.questionType;
}

QuestionOverseer::~QuestionOverseer() {

}
