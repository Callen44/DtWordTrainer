#pragma once

#include <QtWidgets/QMainWindow>
#include "../DataZone/Algorithm.h"
#include "../QuestionZone/QuestionOverseer.h"

class DtWordTrainer : public QMainWindow
{
    Q_OBJECT

public:
    DtWordTrainer(QWidget *parent = nullptr);
    ~DtWordTrainer();

public slots:
    void startQuestions();

private:
    Algorithm algorithm;
};

