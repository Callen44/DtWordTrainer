#include "QuestionBlock.h"

void QuestionBlock::addQuestion(Question* inputQuestion) {
    if (questions.size() > 0) {
        if (inputQuestion->associatedWord != associatedWord) {
            return; // we can't add questions of incompatible words
        } else {
            // update the highestLevel
            if (inputQuestion->questionLevel > highestLevel){
                highestLevel = inputQuestion->questionLevel;
            }
        }
    } else { // the first question
        associatedWord = inputQuestion->associatedWord;
        questions.append(inputQuestion);
        return;
    }

    // add the new question in the correct place
    int i;
    for (i = 1; i < questions.size(); i++) {
        // go through the list and drop a new question right before a questions that is less than our current one
        int behindLevel = questions[i-1]->questionLevel;
        if (behindLevel < inputQuestion->questionLevel)
            break; // we've found the right i value
    }
    questions.insert(i, inputQuestion);
}

Question* QuestionBlock::produce() {
    // since this function can't work without questions in the questions list, we need to abort immediately if that's the case.
    if (questions.size() == 0)
        return nullptr;

    float currentScore = 0.0;

    // calculate the actual score, or let it stay at 0.0 otherwise
    int corrects = timesCorrect();
    int incorrects = timesIncorrect();

    if (corrects + incorrects > 0)
        currentScore = static_cast<float>(corrects) / static_cast<float>(corrects + incorrects);

    /* 
    Figure out which percentages go to which questions. First we create a number of score bins.
    Let's say we have three questions in our block: we'll divide 1.0 by 3 + 1 and get 0.25, this will be theshold for the easiest question.
    0.5 (just 0.25 + itself) will be the threshold for the next easiest question, and we'll just keep adding 0.25 to get the theshold for each question diffuculty level.
    */
    float bottomThresh = 1.0f / (static_cast<float>(questions.size()) + 1.0f);

    // Determine which question index corresponds to the current score.
    // For n questions we have thresholds at bottomThresh, 2*bottomThresh, ..., n*bottomThresh.
    // If currentScore <= bottomThresh -> choose index 0 (easiest), if <= 2*bottomThresh -> index 1, etc.
    int selectedIndex = static_cast<int>(questions.size()) - 1; // default to hardest
    for (int j = 1; j <= questions.size(); ++j) {
        float thresh = bottomThresh * static_cast<float>(j);
        // small tolerance to avoid floating point edge cases
        thresh += 1e-8f;
        if (currentScore <= thresh) {
            selectedIndex = j - 1;
            break;
        }
    }

    if (selectedIndex < 0 || selectedIndex >= questions.size())
        return nullptr;

    return questions[selectedIndex];
}

int QuestionBlock::timesCorrect() {
    if (questions.size() == 0) // make sure we actually have questions
        return 0;
    else
        return questions[0]->timesCorrect();
}

int QuestionBlock::timesIncorrect() {
    if (questions.size() == 0) // make sure we actually have questions
        return 0;
    else
        return questions[0]->timesIncorrect();
}
