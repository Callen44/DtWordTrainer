#include "TPDTWGui.h"
#include "ui_TPDTWGui.h"

TPDTWGui::TPDTWGui(TPDTWLogic* logic, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TPDTWGui)
{
    ui->setupUi(this);
}

TPDTWGui::~TPDTWGui()
{
    delete ui;
}
