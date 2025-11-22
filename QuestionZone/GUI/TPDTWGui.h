#ifndef TPDTWGui_H
#define TPDTWGui_H

#include <QWidget>
#include "../Logic/TPDTWLogic.h"

namespace Ui {
class TPDTWGui;
}

class TPDTWGui : public QWidget
{
    Q_OBJECT

public:
    explicit TPDTWGui(TPDTWLogic* logic, QWidget *parent = nullptr);
    void processCorrectAnswer();
    void processIncorrectAnswer();
    ~TPDTWGui();

signals:
    void questionCompleted();

public slots:
    void processAnswer();

private:
    Ui::TPDTWGui *ui;
    TPDTWLogic* logic;
    void closeQuestion();
};

#endif // TPDTWGui_H
