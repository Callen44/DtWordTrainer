#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DtWordTrainer.h"

class DtWordTrainer : public QMainWindow
{
    Q_OBJECT

public:
    DtWordTrainer(QWidget *parent = nullptr);
    ~DtWordTrainer();

private:
    Ui::DtWordTrainerClass ui;
};

