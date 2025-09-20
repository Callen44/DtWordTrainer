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

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
