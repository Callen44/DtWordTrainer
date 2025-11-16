#include "MCFDLogic.h"
#include <QDebug>

MCFDLogic::MCFDLogic(Word* associatedWord, WordSet* words)
    : Question(MCFD, associatedWord), words(words)
{
    this->associatedWord = associatedWord;

    // this creates the multiple choice question where there are 4 choices presented to the user, one is correct, and three are distracters
    questionPrompt = associatedWord->word;
    distractor0 = createDistractor();
    distractor1 = createDistractor();
    distractor2 = createDistractor();
    correctAns = associatedWord->translation;
}

QString MCFDLogic::createDistractor() {
	// create three distractors, this uses the WordSet that was passed in the constructor

    int totalWords = words->allWords.size(); // mod the random number by the total number of words
    int rint = (std::rand() % totalWords);

    QString distractorAnswer;

    while ((distractorAnswer = words->allWords[rint]->translation) == (associatedWord->translation))
        rint = (std::rand() % totalWords);
    return distractorAnswer;
}

void MCFDLogic::answeredCorrectly() {
    associatedWord->defCorrects++;
}

void MCFDLogic::answeredIncorrectly() {
    associatedWord->defIncorrects++;
}

int MCFDLogic::timesCorrect() {
    return associatedWord->defCorrects;
}

int MCFDLogic::timesIncorrect() {
    return associatedWord->defIncorrects;
}
