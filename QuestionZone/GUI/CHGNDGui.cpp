#include <QTimer>
#include "CHGNDGui.h"
#include "ui_CHGNDGui.h"

CHGNDGui::CHGNDGui(CHGNDLogic* logic, QWidget *parent)
    : QWidget(parent), logic(logic), ui(new Ui::CHGNDGui)
{
    ui->setupUi(this);
    // set the prompt
    ui->wordInput->setText("Gramatical Gender of: " + logic->associatedWord->word);

    // figure out which button is correct
    if (logic->correctGender == DER) {
        correctButton = ui->DerButton;
    } else if (logic->correctGender == DIE) {
        correctButton = ui->DieButton;
    } else if (logic->correctGender == DAS) {
        correctButton = ui->DasButton;
    }

    // set all buttons to the incorrect answer
    QObject::connect(ui->DerButton, &QPushButton::pressed, this, &CHGNDGui::processIncorrectAnswer);
    QObject::connect(ui->DieButton, &QPushButton::pressed, this, &CHGNDGui::processIncorrectAnswer);
    QObject::connect(ui->DasButton, &QPushButton::pressed, this, &CHGNDGui::processIncorrectAnswer);

    // make the right button right
    QObject::connect(correctButton, &QPushButton::pressed, this, &CHGNDGui::processCorrectAnswer);
}

void CHGNDGui::processCorrectAnswer() {
    closeQuestion(true);
}

void CHGNDGui::processIncorrectAnswer() {
    closeQuestion(false);
}


// this function handles the process of closing up the question after the user has had enough time to see the confirmation screen
void CHGNDGui::closeQuestion(bool correct) {
    ui->sizingBox->hide();

    QLabel* newLabel;
    if (correct == true) {
        newLabel = new QLabel("Correct!", this);
    } else {
        newLabel = new QLabel("Incorrect.", this);
    }

    logic->answer(correct);
    newLabel->setAlignment(Qt::AlignCenter);
    ui->gridLayout->addWidget(newLabel);

    // schedule a timer to destroy itself, this question, and emit the questionCompelted signal.
    QTimer* closeTimer = new QTimer(this);
    closeTimer->setInterval(700);
    QObject::connect(closeTimer, &QTimer::timeout, this, &CHGNDGui::questionCompleted);
    QObject::connect(closeTimer, &QTimer::timeout, closeTimer, &QTimer::stop);
    QObject::connect(closeTimer, &QTimer::timeout, closeTimer, &QTimer::deleteLater);
    closeTimer->start();
}

CHGNDGui::~CHGNDGui()
{
    delete ui;
}
