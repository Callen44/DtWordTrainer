#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include "../DataZone/Wordset.h"
#include "ui_MainScreen.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

    void addQuestions(WordSet* rootWordSet);

signals:
    void startQuestions(); // signal to start the questions
    void addNewWord(); // signal to add a new word

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
