#include "MainScreen.h"

MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainScreen)
{
    ui->setupUi(this);

    // setup signals and slots to start questions
    QObject::connect(ui->startButton, &QPushButton::pressed, this, &MainScreen::startQuestions);
}

void MainScreen::addQuestions(WordSet* rootWordSet) {
    /*
    * Add all question words to the list of questions on the homescreen of the app
    */
    for (int i = 0; i < rootWordSet->nouns.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(rootWordSet->nouns[i]->word);
        ui->wordList->insertItem(i, newItem);
    }
    for (int i = 0; i < rootWordSet->verbs.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(rootWordSet->verbs[i]->word);
        ui->wordList->insertItem(i, newItem);
    }
}

MainScreen::~MainScreen()
{
    delete ui;
}
