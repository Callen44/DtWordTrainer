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

    MainScreen mainScreen(this);
}

DtWordTrainer::~DtWordTrainer()
{}

