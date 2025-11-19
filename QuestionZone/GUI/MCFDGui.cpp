#include <cstdlib>
#include <QTimer>

#include "MCFDGui.h"

MCFDGui::MCFDGui(QWidget *parent, MCFDLogic* question)
    : question(question), ui(new Ui::MCFDGui)
{
    ui->setupUi(this);

    // check the variety of the question, set the ui file, and fill it out
    QVariety cQVariety = question->questionType;
    if (cQVariety == MCFD) {
        // setup the ui
        ui->questionLabel->setText(question->questionPrompt);

        // randomly select were the real answer goes
        int loc = rand() % 4;

        // place answers, this is a very repetitive piece of code
        if (loc == 0) {
            ui->answer0->setText(question->correctAns);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &MCFDGui::processCorrectAnswer);

            ui->answer1->setText(question->distractor0);
            ui->answer2->setText(question->distractor1);
            ui->answer3->setText(question->distractor2);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);

        }
        else if (loc == 1) {
            ui->answer1->setText(question->correctAns);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &MCFDGui::processCorrectAnswer);

            ui->answer0->setText(question->distractor0);
            ui->answer2->setText(question->distractor1);
            ui->answer3->setText(question->distractor2);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
        }
        else if (loc == 2) {
            ui->answer2->setText(question->correctAns);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &MCFDGui::processCorrectAnswer);

            ui->answer1->setText(question->distractor0);
            ui->answer0->setText(question->distractor1);
            ui->answer3->setText(question->distractor2);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
        }
        else if (loc == 3) {
            ui->answer3->setText(question->correctAns);
            QObject::connect(ui->answer3, &QPushButton::pressed, this, &MCFDGui::processCorrectAnswer);

            ui->answer1->setText(question->distractor0);
            ui->answer2->setText(question->distractor1);
            ui->answer0->setText(question->distractor2);
            QObject::connect(ui->answer1, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer2, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
            QObject::connect(ui->answer0, &QPushButton::pressed, this, &MCFDGui::processIncorrectAnswer);
        }
    }
}

void MCFDGui::processCorrectAnswer() {
    // show a conformation that this was correct
    ui->sizingBox->hide();
    ui->gridLayout->addWidget(new QLabel("Correct!", ui->sizingBox));
    question->answeredCorrectly();
    closeQuestion();
}

void MCFDGui::processIncorrectAnswer() {
    ui->sizingBox->hide();
    ui->gridLayout->addWidget(new QLabel("Incorrect", ui->sizingBox));
    question->answeredIncorrectly();
    closeQuestion();
}


// this function handles the process of closing up the question after the user has had enough time to see the confirmation screen
void MCFDGui::closeQuestion() {
    // schedule a timer to destroy itself, this question, and emit the questionCompelted signal.
    QTimer* closeTimer = new QTimer(this);
    closeTimer->setInterval(700);
    QObject::connect(closeTimer, &QTimer::timeout, this, &MCFDGui::questionCompleted);
    QObject::connect(closeTimer, &QTimer::timeout, closeTimer, &QTimer::stop);
    QObject::connect(closeTimer, &QTimer::timeout, closeTimer, &QTimer::deleteLater);
    closeTimer->start();
}

MCFDGui::~MCFDGui() {

}
