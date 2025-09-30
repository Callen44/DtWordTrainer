#ifndef FChoiceQuestion_H
#define FChoiceQuestion_H

#include "ui_FChoiceQuestion.h"
#include "../DataZone/Question.h"

namespace Ui {
class FChoiceQuestion;
}

class FChoiceQuestion : public QWidget
{
    Q_OBJECT
public:
    FChoiceQuestion(QWidget *parent, Question *question);
    ~FChoiceQuestion();

public slots:
    void processCorrectAnswer();
    void processIncorrectAnswer();

private:
    Ui::FChoiceQuestion *ui;
    Question* question;
};

#endif 
