#include <QList>
#include "../QuestionZone/Logic/Question.h"

class QuestionBlock {
public:
    // This funciton adds a question you MUST use this funciton to add new questions
    void addQuestion(Question* inputQuestion);

    // this function returns the question from the block that the user is ready for
    Question* produce();

    // return the number of times that the questions in this block were gotten correct
    int timesCorrect();

    // return the number of times that the questions in this block were gotten incorrect
    int timesIncorrect();

    // questions and their information
    int highestLevel; // stores the highest level of difficulty in this block.
    QList<Question*> questions; // stores all questions in this block, these are sorted by difficulty
    Word* associatedWord; // stores the word that all these questions are based on.
};
