/********************************************************************************
** Form generated from reading UI file 'TPDTWGui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPDTWGUI_H
#define UI_TPDTWGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TPDTWGui
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *TPDTWGui)
    {
        if (TPDTWGui->objectName().isEmpty())
            TPDTWGui->setObjectName("TPDTWGui");
        TPDTWGui->resize(400, 300);
        gridLayout = new QGridLayout(TPDTWGui);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit = new QLineEdit(TPDTWGui);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(TPDTWGui);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 3, 0, 1, 1);


        retranslateUi(TPDTWGui);

        QMetaObject::connectSlotsByName(TPDTWGui);
    } // setupUi

    void retranslateUi(QWidget *TPDTWGui)
    {
        TPDTWGui->setWindowTitle(QCoreApplication::translate("TPDTWGui", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("TPDTWGui", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TPDTWGui: public Ui_TPDTWGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPDTWGUI_H
