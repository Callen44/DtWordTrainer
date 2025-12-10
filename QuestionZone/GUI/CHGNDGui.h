#pragma once

#include <QWidget>
#include "../Logic/CHGNDLogic.h"

namespace Ui {
class CHGNDGui;
}

class CHGNDGui : public QWidget
{
    Q_OBJECT

public:
    explicit CHGNDGui(CHGNDLogic* logic, QWidget *parent = nullptr);
    ~CHGNDGui();

signals:
    void questionCompleted();

public slots:
    void processCorrectAnswer();
    void processIncorrectAnswer();

private:
    Ui::CHGNDGui *ui;
    CHGNDLogic* logic;
    void closeQuestion(bool correct);
};
