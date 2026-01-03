#pragma once
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QRadioButton>
#include "../DataZone/Wordset.h"

#ifdef __ANDROID__ // android specific dependencies
#include <QButtonGroup>
#endif

/*
* This class is the widget that allows the user to add new words to the dictionary
*/

class newWordScreen : public QWidget
{
    Q_OBJECT

public:
    explicit newWordScreen(WordSet* words, QWidget *parent = nullptr);
    ~newWordScreen();

signals:
    void done();

public slots:
    void addWord();
#ifndef __ANDROID__ // on android, we need radio buttons instead of combo boxes, this code is android specific, see source file for more details
    void posChosen(QString newItem);
#else
    void subChosen();
    void verbChosen();
#endif

private:
    WordSet* words;

    // the widgets, so their data can be accessed from other member functions of this class (I'm not a skilled enough programmer to use QObject's get child features);
    QFormLayout* formLayout;
    QLineEdit* wortBox;
    QLineEdit* definitionBox;
    QPushButton* submitBtn;

#ifndef __ANDROID__ // same as above, android specific code
    QComboBox* wortartBox;
    QComboBox* genderBox;
#else
    QButtonGroup* wortArt; // a group for both wortArt options
    QButtonGroup* genderBox; // a group for both gender options

    // android specific buttons
    QRadioButton* subButton;
    QRadioButton* verbButton;
    QRadioButton* derButton;
    QRadioButton* dieButton;
    QRadioButton* dasButton;

    // check if sub or verb has been chose
    bool subSelectedNow; // just keep it simple
#endif
};
