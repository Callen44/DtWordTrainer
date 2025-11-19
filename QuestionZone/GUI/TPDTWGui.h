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
    ~TPDTWGui();

private:
    Ui::TPDTWGui *ui;
};

#endif // TPDTWGui_H
