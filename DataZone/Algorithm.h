#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QDebug>

#include "Wordset.h"
#include "QuestionBlock.h"
#include "../QuestionZone/Logic/Question.h"
#include "../QuestionZone/Logic/MCFDLogic.h"
#include "../QuestionZone/Logic/TPDTWLogic.h"
#include "../QuestionZone/Logic/CHGNDLogic.h"

/*
The algorithm has several stages, first it generates every possible question, and it sorts the questions based off
the derrived words. Entire words are introduced at once. There are two QLists, questionPool and livePool. questionPool
is every possible question, live pool only contains questions that are "live" live questions are only from words that
have been introduced to it. Entire words and all their questions are introduced to the pool at once, so that the user
won't be asked for the conjugation of a word he's never seen before. We don't want to memorize the ich conjugation of
a word we otherwise know nothing about.
*/

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

    // -------- Functions that use the algorithm ----------
    
    // finds the question that is scheduled next and returns it (use most of the time)
    Question* nextQuestion();

    // runs a new lottery evaluation and spits out a question that is not scheduled (don't use this much)
    Question* produceQuestion();

    // ----------- QUESTION DATA ---------

    // the current and next batch
    Question* currentBatch[10];
    Question* nextBatch[10];
    int batchIndex = 0;

    QList<QuestionBlock> questionPool; // stores literally every possible questionBlock based on this wordset
    QList<QuestionBlock> livePool; // stores "live questionBlocks" those that the user is ready to see (so that we don't see everythingthing at once)
    QList<int> livePoolIndexes; // stores list of the indexes in question pool of each questionBlock in live pool
    QList<int> allEntries; // stores the number of entries into the lottery each questionBlock gets, indexes synced on livePool

    Question* lastAsked; // makes code less redundant in the implementation file

    // and last but not least, the actual questions themselves
    QList<Question*> questionObjects;

    // --------- Functions the help the algorithm work ----------
    void introduceWord(Word* word); // takes the word given in the paramater and introduces it to the livePool
    void introduceAnyWord(); // introduces one random word, useful when the exact word doesn't matter
    void createAllQuestions(); // make every possible question, needed whenever new words are added to wordset, adds them to questionsPool
private:

};

#endif
