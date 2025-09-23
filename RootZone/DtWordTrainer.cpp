#include "DtWordTrainer.h"
#include "MainScreen.h"
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

    MainScreen* mainScreen = new MainScreen(this);
    mainScreen->addQuestions(&algorithm.words);
    setCentralWidget(mainScreen);

    // setup signals and slots to start questions
    QObject::connect(mainScreen, &MainScreen::startQuestions, this, &DtWordTrainer::startQuestions);
}

void DtWordTrainer::startQuestions() {
    // to start the next question, we need to make a new question widget to display, and then replace the current one
    QuestionOverseer* questionScreen = new QuestionOverseer(this, &algorithm);
    setCentralWidget(questionScreen);

    QWidget* oldCentralWidget = takeCentralWidget();
    delete oldCentralWidget;
}

DtWordTrainer::~DtWordTrainer()
{}

