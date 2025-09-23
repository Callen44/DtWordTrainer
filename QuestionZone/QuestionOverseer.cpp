#include "QuestionOverseer.h"

QuestionOverseer::QuestionOverseer(QObject *parent, Algorithm* algorithm)
    : ui(new Ui::Form)
{
    ui->setupUi(this);
    this->algorithm = algorithm;

    nextQuestion(); // trigger the next question slot early, bypasses the signal and slot system, yes this is legal
}

void QuestionOverseer::nextQuestion() {
    Question nextQuestionObj = algorithm->nextQuestion();
}

QuestionOverseer::~QuestionOverseer() {

}
