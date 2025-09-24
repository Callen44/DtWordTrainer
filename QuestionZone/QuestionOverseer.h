#ifndef QUESTIONOVERSEER_H
#define QUESTIONOVERSEER_H

#include "ui_4ChoiceQuestion.h"
#include "../DataZone/Algorithm.h"
#include "../DataZone/Question.h"

namespace Ui {
class QuestionOverseer;
}

class QuestionOverseer : public QWidget
{
    Q_OBJECT

public:
    QuestionOverseer(QWidget *parent, Algorithm* algorithm);
    ~QuestionOverseer();

    QVariety cQVariety;

public slots:
    void nextQuestion();

private:
    Ui::QuestionOverseer *ui;
    Algorithm* algorithm;

};

#endif 
