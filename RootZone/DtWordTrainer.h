#pragma once

#include <QtWidgets/QMainWindow>
#include "../DataZone/Algorithm.h"
#include "../QuestionZone/GUI/QuestionOverseer.h"

class DtWordTrainer : public QMainWindow
{
    Q_OBJECT

public:
    DtWordTrainer(QWidget *parent = nullptr);
    ~DtWordTrainer();

public slots:
    void startQuestions();
    void addNewWord();
    void showMainScreen();

private:
    Algorithm algorithm;
};

