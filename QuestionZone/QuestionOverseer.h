#ifndef QUESTIONOVERSEER_H
#define QUESTIONOVERSEER_H

#include "../DataZone/Algorithm.h"
#include "../DataZone/Question.h"
#include "FChoiceQuestion.h"

#include <QWidget>

class QuestionOverseer : public QWidget
{
    Q_OBJECT
public:
    explicit QuestionOverseer(Algorithm* algorithm, QWidget *parent = nullptr);

public slots:
    void nextQuestion();

private:
    QWidget* currentWidget;
    Algorithm* algorithm;
};

#endif // QUESTIONOVERSEER_H
