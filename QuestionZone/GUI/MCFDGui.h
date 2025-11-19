#ifndef MCFDGui_H
#define MCFDGui_H

#include "ui_MCFDGui.h"
#include "../Logic/Question.h"
#include "../Logic/MCFDLogic.h"

namespace Ui {
class MCFDGui;
}

class MCFDGui : public QWidget
{
    Q_OBJECT
public:
    MCFDGui(QWidget *parent, MCFDLogic* question);
    ~MCFDGui();

signals:
    void questionCompleted();

public slots:
    void processCorrectAnswer();
    void processIncorrectAnswer();

private:
    Ui::MCFDGui *ui;
    MCFDLogic* question;
    void closeQuestion();
};

#endif 
