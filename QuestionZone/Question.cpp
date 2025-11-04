#include "Question.h"
#include <QDebug>

// Define the virtual functions with default implementations
int Question::timesCorrect() {
    qDebug() << "ERROR! default timesCorrect for Question has been called!";
    return 0; // Default implementation
}

int Question::timesIncorrect() {
    qDebug() << "ERROR! default timesIncorrect for Question has been called!";
    return 0; // Default implementation
}
