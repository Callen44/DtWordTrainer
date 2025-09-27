#include <cstdlib>

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
        
        // randomly select were the real answer goes
        int loc = rand() % 4;
        
        // place answers, this is a very repetitive piece of code
        if (loc == 0) {
            ui->answer0->setText(nQuestion.correctAns);

            ui->answer1->setText(nQuestion.distractor0);
            ui->answer2->setText(nQuestion.distractor1);
            ui->answer3->setText(nQuestion.distractor2);
        }
        else if (loc == 1) {
            ui->answer1->setText(nQuestion.correctAns);

            ui->answer0->setText(nQuestion.distractor0);
            ui->answer2->setText(nQuestion.distractor1);
            ui->answer3->setText(nQuestion.distractor2);
        }
        else if (loc == 2) {
            ui->answer2->setText(nQuestion.correctAns);

            ui->answer1->setText(nQuestion.distractor0);
            ui->answer0->setText(nQuestion.distractor1);
            ui->answer3->setText(nQuestion.distractor2);
        }
        else if (loc == 3) {
            ui->answer3->setText(nQuestion.correctAns);

            ui->answer1->setText(nQuestion.distractor0);
            ui->answer2->setText(nQuestion.distractor1);
            ui->answer0->setText(nQuestion.distractor2);
        }

    }
}

QuestionOverseer::~QuestionOverseer() {

}
