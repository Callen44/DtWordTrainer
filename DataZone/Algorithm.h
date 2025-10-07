#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Noun.h"
#include "Verb.h"
#include "Wordset.h"
#include "../QuestionZone/FChoiceQuestion.h"

class Algorithm {

public:
    // variables
    WordSet words;

	// functions
    Algorithm();
    ~Algorithm();

    // functions that help manage the algorithm
    bool readFiles(QString fileName);

    // functions that use the algorithm
    Question* nextQuestion();

private:
    bool firstQuestion = true; // the first question will always

};

#endif
