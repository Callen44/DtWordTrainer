#include "QuestionOverseer.h"

QuestionOverseer::QuestionOverseer(QWidget *parent, Algorithm* algorithm)
    : ui(new Ui::QuestionOverseer)
{
    ui->setupUi(this);
    this->algorithm = algorithm;

    const QObjectList& children = this->children();
    const QObjectList& children2 = children[0]->children();

    nextQuestion(); // trigger the next question slot early, bypasses the signal and slot system, yes this is legal
}

void QuestionOverseer::nextQuestion() {
    Question nextQuestionObj = algorithm->nextQuestion();
}

QuestionOverseer::~QuestionOverseer() {

}
