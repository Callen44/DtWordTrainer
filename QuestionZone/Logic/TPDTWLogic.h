#ifndef TPDTWH
#define TPDTWH

#include "Question.h"

/*
 * This question has the user type the word in german, at the moment it doesn't have any mistake tolerence, not sure if it needs it.
 * This question is simple in its implementation.
*/

class TPDTWLogic : public Question {
public:
    /*
    Functions
    */

    TPDTWLogic(Word* associatedWord, WordSet* words);

    // funcitons for handling correct or incorrect answers
    void answer(QString answer);
    int timesCorrect() override;
    int timesIncorrect() override;

    /*
     * Variables
    */
    WordSet* words;
};

#endif
