#pragma once
#include "Question.h"
#include "../../DataZone/Noun.h"
#include <exception>

class CHGNDLogic : public Question {
public:
    /*
    Functions
    */

    CHGNDLogic(Noun* associatedWord);
    void answer(bool corect);
    int timesCorrect() override;
    int timesIncorrect() override;

    /*
     * Variables
    */
    Gender correctGender;
};
