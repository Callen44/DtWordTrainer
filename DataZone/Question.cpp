#include "Question.h"

Question::Question(QVariety QuestionType, Word* AssociatedWord) : questionType(QuestionType), associatedWord(AssociatedWord) {
	if (QuestionType == MCHOICEFOURDEF) {
		questionPrompt = AssociatedWord->word;
	}
}
