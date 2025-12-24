#pragma once
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "../DataZone/Wordset.h"

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
    void posChosen(QString newItem);

private:
    WordSet* words;

    // the widgets, so their data can be accessed
    QFormLayout* formLayout;
    QLineEdit* wortBox;
    QLineEdit* definitionBox;
    QComboBox* wortartBox;
    QComboBox* genderBox;
    QPushButton* submitBtn;
};
