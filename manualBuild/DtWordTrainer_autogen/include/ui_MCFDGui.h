/********************************************************************************
** Form generated from reading UI file 'MCFDGui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCFDGUI_H
#define UI_MCFDGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MCFDGui
{
public:
    QGridLayout *gridLayout;
    QWidget *sizingBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *questionPanel;
    QSpacerItem *verticalSpacer_5;
    QLabel *questionLabel;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *answerGrid;
    QPushButton *answer2;
    QPushButton *answer0;
    QPushButton *answer1;
    QPushButton *answer3;

    void setupUi(QWidget *MCFDGui)
    {
        if (MCFDGui->objectName().isEmpty())
            MCFDGui->setObjectName("MCFDGui");
        MCFDGui->resize(800, 587);
        gridLayout = new QGridLayout(MCFDGui);
        gridLayout->setObjectName("gridLayout");
        sizingBox = new QWidget(MCFDGui);
        sizingBox->setObjectName("sizingBox");
        sizingBox->setMaximumSize(QSize(800, 800));
        gridLayout_2 = new QGridLayout(sizingBox);
        gridLayout_2->setObjectName("gridLayout_2");
        questionPanel = new QVBoxLayout();
        questionPanel->setObjectName("questionPanel");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        questionPanel->addItem(verticalSpacer_5);

        questionLabel = new QLabel(sizingBox);
        questionLabel->setObjectName("questionLabel");

        questionPanel->addWidget(questionLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        questionPanel->addItem(verticalSpacer_6);

        answerGrid = new QGridLayout();
        answerGrid->setObjectName("answerGrid");
        answer2 = new QPushButton(sizingBox);
        answer2->setObjectName("answer2");

        answerGrid->addWidget(answer2, 1, 0, 1, 1);

        answer0 = new QPushButton(sizingBox);
        answer0->setObjectName("answer0");

        answerGrid->addWidget(answer0, 0, 0, 1, 1);

        answer1 = new QPushButton(sizingBox);
        answer1->setObjectName("answer1");

        answerGrid->addWidget(answer1, 0, 1, 1, 1);

        answer3 = new QPushButton(sizingBox);
        answer3->setObjectName("answer3");

        answerGrid->addWidget(answer3, 1, 1, 1, 1);


        questionPanel->addLayout(answerGrid);


        gridLayout_2->addLayout(questionPanel, 0, 0, 1, 1);


        gridLayout->addWidget(sizingBox, 0, 0, 1, 1);


        retranslateUi(MCFDGui);

        QMetaObject::connectSlotsByName(MCFDGui);
    } // setupUi

    void retranslateUi(QWidget *MCFDGui)
    {
        MCFDGui->setWindowTitle(QCoreApplication::translate("MCFDGui", "Form", nullptr));
        questionLabel->setText(QCoreApplication::translate("MCFDGui", "question Text", nullptr));
        answer2->setText(QCoreApplication::translate("MCFDGui", "blank", nullptr));
        answer0->setText(QCoreApplication::translate("MCFDGui", "blank", nullptr));
        answer1->setText(QCoreApplication::translate("MCFDGui", "blank", nullptr));
        answer3->setText(QCoreApplication::translate("MCFDGui", "blank", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MCFDGui: public Ui_MCFDGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCFDGUI_H
