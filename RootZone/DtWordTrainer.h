#pragma once

#include <QtWidgets/QMainWindow>
#include "../DataZone/Algorithm.h"
#include "../QuestionZone/QuestionOverseer.h"

class DtWordTrainer : public QMainWindow
{
    Q_OBJECT

public:
    DtWordTrainer(QWidget *parent = nullptr);
    void addQuestions(); // Add all question words to the list of questions on the homescreen of the app
    ~DtWordTrainer();

public slots:
    void startQuestions();

private:
    Algorithm algorithm;
};

