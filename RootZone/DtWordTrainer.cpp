#include "DtWordTrainer.h"
#include <QFileDialog>
#include <cstdlib>

DtWordTrainer::DtWordTrainer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Questions Set"), "~", tr("*.dtw"));

    if (fileName == "") {
        exit(0);
    }

    globalWords = WordSet();
    globalWords.parseWordFile(fileName);
    globalWords.parseWissenFile(globalWords.calcWDAName(fileName));

    addQuestions();
}

void DtWordTrainer::addQuestions() {
    for (int i = 0; i < globalWords.nouns.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(globalWords.nouns[i].word);
        ui.wordList->insertItem(i, newItem);
    }
    for (int i = 0; i < globalWords.verbs.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(globalWords.verbs[i].word);
        ui.wordList->insertItem(i, newItem);
    }
}

DtWordTrainer::~DtWordTrainer()
{}

