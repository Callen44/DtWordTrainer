#include <cstdlib>

#include "Question.h"

Question::Question(QVariety QuestionType, Word* AssociatedWord, WordSet* wordSet) : questionType(QuestionType), associatedWord(AssociatedWord), words(wordSet) 
{
	if (QuestionType == MCHOICEFOURDEF) {
		// this creates the multiple choice question where there are 4 choices presented to the user, one is correct, and three are distracters
		questionPrompt = AssociatedWord->word;

		distractor0 = createDistractor();
		distractor1 = createDistractor();
		distractor2 = createDistractor();
		correctAns = AssociatedWord->translation;
	}
}

QString Question::createDistractor() {
	// create three distractors, this uses the WordSet that was passed in the constructor
	int rint = std::rand() % (words->nouns.size() + words->verbs.size()); // mod the random number by the total number of words
	
	if (rint <= words->nouns.size()) {
		return words->nouns[rint].translation;
	}
	else {
		rint -= words->nouns.size();
		return words->verbs[rint].translation;
	}
}