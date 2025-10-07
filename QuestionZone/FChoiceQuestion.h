#ifndef FChoiceQuestion_H
#define FChoiceQuestion_H

#include "ui_FChoiceQuestion.h"
#include "Question.h"
#include "MChoiceFourDef.h"

namespace Ui {
class FChoiceQuestion;
}

class FChoiceQuestion : public QWidget
{
    Q_OBJECT
public:
    FChoiceQuestion(QWidget *parent, MChoiceFourDef* question);
    ~FChoiceQuestion();

public slots:
    void processCorrectAnswer();
    void processIncorrectAnswer();

private:
    Ui::FChoiceQuestion *ui;
    MChoiceFourDef* question;
};

#endif 
