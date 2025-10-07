#include <cstdlib>

#include "FChoiceQuestion.h"

FChoiceQuestion::FChoiceQuestion(QWidget *parent, MChoiceFourDef* question)
    : question(question), ui(new Ui::FChoiceQuestion)
{
    ui->setupUi(this);

    // check the variety of the question, set the ui file, and fill it out
    QVariety cQVariety = question->questionType;
    if (cQVariety == MCHOICEFOURDEF) {
        // setup the ui
        ui->questionLabel->setText(question->questionPrompt);

        // randomly select were the real answer goes
        int loc = rand() % 4;

        // place answers, this is a very repetitive piece of code
        if (loc == 0) {
            ui->answer0->setText(question->correctAns);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &FChoiceQuestion::processCorrectAnswer);

            ui->answer1->setText(question->distractor0);
            ui->answer2->setText(question->distractor1);
            ui->answer3->setText(question->distractor2);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);

        }
        else if (loc == 1) {
            ui->answer1->setText(question->correctAns);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &FChoiceQuestion::processCorrectAnswer);

            ui->answer0->setText(question->distractor0);
            ui->answer2->setText(question->distractor1);
            ui->answer3->setText(question->distractor2);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
        }
        else if (loc == 2) {
            ui->answer2->setText(question->correctAns);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &FChoiceQuestion::processCorrectAnswer);

            ui->answer1->setText(question->distractor0);
            ui->answer0->setText(question->distractor1);
            ui->answer3->setText(question->distractor2);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
        }
        else if (loc == 3) {
            ui->answer3->setText(question->correctAns);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &FChoiceQuestion::processCorrectAnswer);

            ui->answer1->setText(question->distractor0);
            ui->answer2->setText(question->distractor1);
            ui->answer0->setText(question->distractor2);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &FChoiceQuestion::processIncorrectAnswer);
        }

    }
}

void FChoiceQuestion::processCorrectAnswer() {
    question->answeredCorrectly();
}

void FChoiceQuestion::processIncorrectAnswer() {
    question->answeredIncorrectly();
}

FChoiceQuestion::~FChoiceQuestion() {
    delete question;
}
