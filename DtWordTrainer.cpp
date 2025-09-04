#include "DtWordTrainer.h"
#include "Wordset.h"
#include <QFileDialog>

DtWordTrainer::DtWordTrainer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Questions Set"), "~", tr("*.dtw"));

    WordSet globalWords = WordSet();
    globalWords.parseFile(fileName);
}

DtWordTrainer::~DtWordTrainer()
{}

