#include "MChoiceFourDef.h"
#include <QDebug>

MChoiceFourDef::MChoiceFourDef(Word* associatedWord, WordSet* words)
    : Question(MCHOICEFOURDEF, associatedWord), words(words)
{
    this->associatedWord = associatedWord;

    // this creates the multiple choice question where there are 4 choices presented to the user, one is correct, and three are distracters
    questionPrompt = associatedWord->word;
    distractor0 = createDistractor();
    distractor1 = createDistractor();
    distractor2 = createDistractor();
    correctAns = associatedWord->translation;
}

QString MChoiceFourDef::createDistractor() {
	// create three distractors, this uses the WordSet that was passed in the constructor

    int totalWords = words->allWords.size(); // mod the random number by the total number of words
    int rint = (std::rand() % totalWords);

    QString distractorAnswer;

    while ((distractorAnswer = words->allWords[rint]->translation) == (associatedWord->translation))
        rint = (std::rand() % totalWords);
    return distractorAnswer;
}

void MChoiceFourDef::answeredCorrectly() {
    associatedWord->defCorrects++;
}

void MChoiceFourDef::answeredIncorrectly() {
    associatedWord->defIncorrects++;
}

int MChoiceFourDef::timesCorrect() {
    return associatedWord->defCorrects;
}

int MChoiceFourDef::timesIncorrect() {
    return associatedWord->defIncorrects;
}
