#include "DtWordTrainer.h"
#include "MainScreen.h"
#include "newWordScreen.h"
#include <QFileDialog>
#include <cstdlib>

DtWordTrainer::DtWordTrainer(QWidget *parent)
    : QMainWindow(parent)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Questions Set"), "~", tr("*.dtw"));
    if (fileName == "") {
        exit(0);
    }

    algorithm = Algorithm();
    algorithm.readFiles(fileName);

    showMainScreen();
}

void DtWordTrainer::showMainScreen() {
    // display the main screen screen
    MainScreen* mainScreen = new MainScreen(this);
    mainScreen->addQuestions(&algorithm.words);
    setCentralWidget(mainScreen);

    // setup signals and slots to start questions
    QObject::connect(mainScreen, &MainScreen::startQuestions, this, &DtWordTrainer::startQuestions);
    QObject::connect(mainScreen, &MainScreen::addNewWord, this, &DtWordTrainer::addNewWord);
}

void DtWordTrainer::startQuestions() {
    // to start the next question, we need to make a new question widget to display, and then replace the current one
    QuestionOverseer* questionScreen = new QuestionOverseer(&algorithm, this);
    QWidget* oldCentralWidget = takeCentralWidget();
    delete oldCentralWidget;
    setCentralWidget(questionScreen);
}

void DtWordTrainer::addNewWord() {
    newWordScreen* wordScreen = new newWordScreen(&algorithm.words, this);
    QWidget* oldCentralWidget = takeCentralWidget();
    delete oldCentralWidget;
    setCentralWidget(wordScreen);
    QObject::connect(wordScreen, &newWordScreen::done, this, &DtWordTrainer::showMainScreen);
}

DtWordTrainer::~DtWordTrainer()
{}

