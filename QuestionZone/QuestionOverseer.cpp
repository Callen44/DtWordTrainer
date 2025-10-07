#include "QuestionOverseer.h"

#include <QVBoxLayout>

QuestionOverseer::QuestionOverseer(Algorithm* algorithm, QWidget *parent)
    : algorithm(algorithm), QWidget{parent}
{
    // set the layout and prepare the class for recieving questions
    setLayout(new QVBoxLayout());
    currentWidget = nullptr;

    // initialize the first question
    nextQuestion();
}

void QuestionOverseer::nextQuestion() {
    // get the next question
    Question* nQ = algorithm->nextQuestion();

    // TODO Temporary solution!!!
    MChoiceFourDef* nQpf = reinterpret_cast<MChoiceFourDef*>(nQ);

    // remove the old question widget
    QLayout* myLayout = layout();
    myLayout->removeWidget(currentWidget);
    delete currentWidget;

    // add the next question widget
    FChoiceQuestion* nextWidget = new FChoiceQuestion(this, nQpf);
    currentWidget = nextWidget;
    myLayout->addWidget(nextWidget);
}
