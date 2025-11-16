#ifndef FChoiceQuestion_H
#define FChoiceQuestion_H

#include "ui_MCFDGui.h"
#include "../Logic/Question.h"
#include "../Logic/MCFDLogic.h"

namespace Ui {
class FChoiceQuestion;
}

class FChoiceQuestion : public QWidget
{
    Q_OBJECT
public:
    FChoiceQuestion(QWidget *parent, MCFDLogic* question);
    ~FChoiceQuestion();

signals:
    void questionCompleted();

public slots:
    void processCorrectAnswer();
    void processIncorrectAnswer();

private:
    Ui::FChoiceQuestion *ui;
    MCFDLogic* question;
    void closeQuestion();
};

#endif 
