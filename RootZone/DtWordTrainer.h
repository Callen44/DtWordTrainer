#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DtWordTrainer.h"
#include "../DataZone/Wordset.h"

class DtWordTrainer : public QMainWindow
{
    Q_OBJECT

public:
    DtWordTrainer(QWidget *parent = nullptr);
    void addQuestions();
    ~DtWordTrainer();

private:
    Ui::DtWordTrainerClass ui;
    WordSet globalWords;
};

