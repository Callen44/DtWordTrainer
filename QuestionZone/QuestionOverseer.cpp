#include "QuestionOverseer.h"

QuestionOverseer::QuestionOverseer(QWidget *parent, Algorithm* algorithm)
    : ui(new Ui::QuestionOverseer)
{
    ui->setupUi(this);
    this->algorithm = algorithm;

    nextQuestion(); // trigger the next question slot early, bypasses the signal and slot system, yes this is legal
}

void QuestionOverseer::nextQuestion() {
    // this function creates the question, we begin by requesting a question object from the algorithm
    Question nQuestion = algorithm->nextQuestion();

    // check the variety of the question, set the ui file, and fill it out
    cQVariety = nQuestion.questionType;
    if (cQVariety == MCHOICEFOURDEF) {
        // setup the ui

        ui->questionLabel->setText(nQuestion.questionPrompt);
        
        // place the correct 
    }
}

QuestionOverseer::~QuestionOverseer() {

}
