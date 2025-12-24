#include "MainScreen.h"

MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainScreen)
{
    ui->setupUi(this);

    // setup signals and slots to start questions
    QObject::connect(ui->startButton, &QPushButton::pressed, this, &MainScreen::startQuestions);
    QObject::connect(ui->addNewWord, &QPushButton::pressed, this, &MainScreen::addNewWord);
}

void MainScreen::addQuestions(WordSet* rootWordSet) {
    /*
    * Add all question words to the list of questions on the homescreen of the app
    */
    for (int i = 0; i < rootWordSet->allWords.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(rootWordSet->allWords[i]->word);
        ui->wordList->insertItem(i, newItem);
    }
}

MainScreen::~MainScreen()
{
    delete ui;
}
