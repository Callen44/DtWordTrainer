#ifndef TPDTWH
#define TPDTWH

#include "Question.h"

class TpDtw : public Question {
public:
    /*
    Functions
    */

    TpDtw(Word* associatedWord, WordSet* words);
    QString createDistractor(); // this function is implemented seperately for each subclass.

    // funcitons for handling correct or incorrect answers
    void answeredCorrectly();
    void answeredIncorrectly();
    int timesCorrect() override;
    int timesIncorrect() override;

    /*
     * Variables
    */
    WordSet* words;
};

#endif
