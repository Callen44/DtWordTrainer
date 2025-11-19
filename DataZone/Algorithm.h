#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Wordset.h"
#include "../QuestionZone/Logic/Question.h"
#include "../QuestionZone/GUI/MCFDGui.h"
#include "../QuestionZone/Logic/TPDTWLogic.h"

/*
 * How the algorithm class works - The short version
 *
 * Questions are created in rounds, questions are arranged into batches of ten questions. Batches will be constructed
 * using a set of satistics gathered from the last batches. These satistics will be recalculated every other batch,
 * the first batch will be created purely off of the dataset, while the seccond will consist primarily of reappearnces
 * of questions gotten wrong in the last batch. Blank spots will be filled in with questions from calculated satistics.
 * These satistics will still not be recalculated for the seccond batch, only the first batch gets priority this way.
 * There is no end, this process will continue until the user closes the program.
 * (I mean first batch as in the first in each cycle, not the literal first batch)
 * 
 * Before the process actually begins, a list of all possible questions is contructed.
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

    // functions that use the algorithm
    Question* nextQuestion();

    // QUESTION DATA

    // the current and next batch
    QList<Question> currentBatch;
    bool currentBatchExpended;
    QList<Question> nextBatch;
    bool nextBatchExpended;

    QList<Question*> allQuestions; // stores literally every possible question based on this wordset
    QList<int> allEntries; // stores the number of entries into the lottery each question gets

private:

};

#endif
