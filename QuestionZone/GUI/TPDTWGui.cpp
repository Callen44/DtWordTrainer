#include <QTimer>

#include "TPDTWGui.h"
#include "ui_TPDTWGui.h"

TPDTWGui::TPDTWGui(TPDTWLogic* logic, QWidget *parent)
    : QWidget(parent), logic(logic), ui(new Ui::TPDTWGui)
{
    ui->setupUi(this);
    // set the prompt
    ui->questionPrompt->setText("German Translation of: " + logic->associatedWord->translation);

    // connect the button's signal so that we can check the answer when it is clicked.
    QObject::connect(ui->enterButton, &QPushButton::clicked, this, &TPDTWGui::processAnswer);
}

void TPDTWGui::processAnswer() {
    if (logic->answer(ui->entryField->text())) {
        processCorrectAnswer();
    } else {
        processIncorrectAnswer();
    }
}

void TPDTWGui::processCorrectAnswer() {
    ui->questionPrompt->setText(ui->questionPrompt->text() + ": Correct");
    closeQuestion();
}

void TPDTWGui::processIncorrectAnswer() {
    ui->questionPrompt->setText(ui->questionPrompt->text() + ": Incorrect");
    closeQuestion();
}


// this function handles the process of closing up the question after the user has had enough time to see the confirmation screen
void TPDTWGui::closeQuestion() {
    // gray out the textBox
    ui->entryField->setReadOnly(true);
    ui->enterButton->setEnabled(false);

    // schedule a timer to destroy itself, this question, and emit the questionCompelted signal.
    QTimer* closeTimer = new QTimer(this);
    closeTimer->setInterval(700);
    QObject::connect(closeTimer, &QTimer::timeout, this, &TPDTWGui::questionCompleted);
    QObject::connect(closeTimer, &QTimer::timeout, closeTimer, &QTimer::stop);
    QObject::connect(closeTimer, &QTimer::timeout, closeTimer, &QTimer::deleteLater);
    closeTimer->start();
}

TPDTWGui::~TPDTWGui()
{
    delete ui;
}
