/********************************************************************************
** Form generated from reading UI file 'MainScreen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QListWidget *wordList;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName("MainScreen");
        MainScreen->resize(883, 586);
        gridLayout = new QGridLayout(MainScreen);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        wordList = new QListWidget(MainScreen);
        wordList->setObjectName("wordList");

        gridLayout_2->addWidget(wordList, 1, 0, 1, 1);

        label = new QLabel(MainScreen);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        startButton = new QPushButton(MainScreen);
        startButton->setObjectName("startButton");
        startButton->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(startButton, 2, 0, 1, 1);


        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        MainScreen->setWindowTitle(QCoreApplication::translate("MainScreen", "DtWordTrainer", nullptr));
        label->setText(QCoreApplication::translate("MainScreen", "Questions", nullptr));
        startButton->setText(QCoreApplication::translate("MainScreen", "Start Questions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
