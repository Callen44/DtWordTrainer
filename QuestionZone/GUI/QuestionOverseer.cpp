#include "QuestionOverseer.h"
#include "MCFDGui.h"
#include "TPDTWGui.h"

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

    // remove the old question widget
    QLayout* myLayout = layout();
    myLayout->removeWidget(currentWidget);
    delete currentWidget;

    // add the next question widget
    if (nQ->questionType == MCFD) {
        MCFDLogic* nQpf = reinterpret_cast<MCFDLogic*>(nQ);
        MCFDGui* nextWidget = new MCFDGui(this, nQpf);
        currentWidget = nextWidget;
        myLayout->addWidget(nextWidget);

        // ensure that the next question will be asked when the user finishes this one
        QObject::connect(nextWidget, &MCFDGui::questionCompleted, this, &QuestionOverseer::nextQuestion);
    } else if (nQ->questionType == TPDTW) {
        TPDTWLogic* realQuestion = reinterpret_cast<TPDTWLogic*>(nQ);
        TPDTWGui* nextWidget = new TPDTWGui(realQuestion, this);
        currentWidget = nextWidget;
        myLayout->addWidget(currentWidget);
        
        // ensure that the next question will be asked when... you get the point
        QObject::connect(nextWidget, &TPDTWGui::questionCompleted, this, &QuestionOverseer::nextQuestion);
    }
}
