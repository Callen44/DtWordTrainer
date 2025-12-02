#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Wordset.h"
#include "../QuestionZone/Logic/Question.h"
#include "../QuestionZone/GUI/MCFDGui.h"
#include "../QuestionZone/Logic/TPDTWLogic.h"

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

    QList<Question*> questionPool; // stores literally every possible question based on this wordset
    QList<Question*> livePool; // stores "live questions" those that have been introduced to the user's question pool
    QList<int> livePoolIndexes; // stores list of the indexes in question pool of each question in live pool
    QList<int> allEntries; // stores the number of entries into the lottery each question gets, indexes synced on livePool

    Question* lastAsked; // makes code less redundant

    // --------- Functions the help the algorithm work ----------
    void introduceWord(Word* word); // takes the word given in the paramater and introduces it to the livePool
    void introduceAnyWord(); // introduces one random word, useful when the exact word doesn't matter
private:

};

#endif
