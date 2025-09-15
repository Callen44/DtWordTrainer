#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DtWordTrainer.h"
#include "../DataZone/Wordset.h"

class DtWordTrainer : public QMainWindow
{
    Q_OBJECT

public:
    DtWordTrainer(QWidget *parent = nullptr);
    void addQuestions(); // Add all question words to the list of questions on the homescreen of the app
    ~DtWordTrainer();

private:
    Ui::DtWordTrainerClass ui;
    WordSet globalWords;
};

