#include "Noun.h"
#include "Verb.h"
#include "Wordset.h"
#include "Question.h"

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
    Question nextQuestion();

};
