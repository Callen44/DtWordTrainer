#pragma once
#include "Question.h"

class MCFDLogic : public Question {
public:
	/*
	Functions
	*/

    MCFDLogic(Word* associatedWord, WordSet* words);
    QString createDistractor(); // this function is implemented seperately for each subclass.

    // funcitons for handling correct or incorrect answers
    void answeredCorrectly();
    void answeredIncorrectly();
    int timesCorrect() override;
    int timesIncorrect() override;

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
