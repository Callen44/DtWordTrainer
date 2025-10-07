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

    // TODO right now it is possible for the correct answer to be chosen as a distractor, two correct answers will appear, one is correct, the other is not

    int totalWords = (words->nouns.size() + words->verbs.size()); // mod the random number by the total number of words
    int rint = std::rand() % totalWords;
	
	if (rint <= words->nouns.size()) {
		return words->nouns[rint].translation;
	}
	else {
		rint -= words->nouns.size();
		return words->verbs[rint].translation;
	}
}

void MChoiceFourDef::answeredCorrectly() {
    qDebug() << "correct!";
}

void MChoiceFourDef::answeredIncorrectly() {
    qDebug() << "incorrect!";
}
