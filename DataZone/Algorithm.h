#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Wordset.h"
#include "../QuestionZone/Logic/Question.h"
#include "../QuestionZone/GUI/MCFDGui.h"
#include "../QuestionZone/Logic/TPDTWLogic.h"

class Algorithm {

public:
    // variables
    WordSet words;

	// functions
    Algorithm();
    ~Algorithm();

    // The Stages of The Algorithm's Processing
    void recalculateData();
    void moveBatchUp();

    // functions that help manage the algorithm
    bool readFiles(QString fileName);

    // -------- functions that use the algorithm ----------
    
    // finds the question that is scheduled next and returns it (use most of the time)
    Question* nextQuestion();

    // runs a new lottery evaluation and spits out a question that is not scheduled (don't use this much)
    Question* produceQuestion();

    // ----------- QUESTION DATA ---------

    // the current and next batch
    Question* currentBatch[10];
    Question* nextBatch[10];
    int batchIndex = 0;

    QList<Question*> allQuestions; // stores literally every possible question based on this wordset
    QList<int> allEntries; // stores the number of entries into the lottery each question gets

private:

};

#endif
