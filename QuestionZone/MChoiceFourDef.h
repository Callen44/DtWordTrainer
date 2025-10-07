#include "Question.h"

class MChoiceFourDef : public Question {
public:
	/*
	Functions
	*/

    MChoiceFourDef(Word* associatedWord, WordSet* words);
    QString createDistractor(); // this function is implemented seperately for each subclass.

    // funcitons for handling correct or incorrect answers
    void answeredCorrectly();
    void answeredIncorrectly();

    /*
     * Variables
    */
    QString questionPrompt;
    QString distractor0;
    QString distractor1;
    QString distractor2;
    QString correctAns;

    WordSet* words;
};
