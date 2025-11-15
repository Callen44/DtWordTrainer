#include "Algorithm.h"

Algorithm::Algorithm() {
    currentBatchExpended = true;
    nextBatchExpended = true;
}

bool Algorithm::readFiles(QString fileName) {
    // TODO, this should not be a fatal error
    if (!words.parseWordFile(fileName)){
        qDebug() << "Files failed to open, are they writable?\nThis is a fatal error.";
        exit(1);
    }

    if (!words.parseWissenFile(words.calcWDAName(fileName)))
        qDebug() << "Failed to open wissen file, data will be filled with blank info.";

    // prep step, make every possible question
    for (int i = 0; i < words.allWords.size(); i++) {
        if (words.allWords[i]->partOfSpeech == NOUN) {
            // Questions that only nouns can have
            Noun* wordIQ = reinterpret_cast<Noun*>(words.allWords[i]); // stands for word in question
            // TODO Make some!
        } else if (words.allWords[i]->partOfSpeech == VERB) {
            // Questions that only verbs can have
            Verb* wordIQ = reinterpret_cast<Verb*>(words.allWords[i]); // stands for word in question
            // TODO Make some!
        }
        // Questions that all words can have

        // the classic multiple choice definition question
        MChoiceFourDef* newQuestion = new MChoiceFourDef(words.allWords[i], &words);
        allQuestions.append(newQuestion);
        allEntries.append(0);
    }

    return true;
}

Question* Algorithm::nextQuestion() {
    // begin with an autosave to keep things up to date
    words.writeWissenFile();

    // so we don't run the loterry with no data
    if (currentBatchExpended && nextBatchExpended)
        recalculateData();

    // let's pick a question!
    int totalEntries = 0;

    for (int i = 0; i < allEntries.size(); i++)
        totalEntries += allEntries[i];

    int chosenEntry = std::rand() % totalEntries;

    // find the associated question
    int currentQuestionIndex = 0; // the index of the question that we are evaluating
    int passedEntries = 0; // the number of loterry entries that have been passed by

    while (1 == 1) {
        passedEntries += allEntries[currentQuestionIndex];
        if (passedEntries >= chosenEntry)
            break;

        currentQuestionIndex++;
    }

    // return the questions we've chosen
    return allQuestions[currentQuestionIndex];
}

void Algorithm::recalculateData() {
    // run through each word's specific information, then recalculate the overall data of the question set.
    allEntries.clear(); // clear out all old information

    // on the lists below we store our data, questions are identified by their indexes on the allQuestions list
    QList<double> scores; // a list that allighns with allQuestions, keeps track of the percentage of times that user gets that question correct.
    QList<int> timesAsked; // keeps track of the number of times a questions has been asked
    QList<int> unseen; // a list of the indexes of questions that have never been asked before
    QList<int> seen; // the opposite of unseen
    QList<int> known; // questions that have a score (from scores list) of over 93% and three askings
    QList<int> mostlyLearnt; // questions that the user has been asked at least 3 times, with a score between 80% and 90%
    QList<int> learning; // questions that the user is actively learning, been asked at least thrice, but with under 80% score
    QList<int> struggling; // these are questions from either the learning or mostlyLearnt lists that the user has been asked 6 or more times

    // generate scores list and timesAsked
    for (int i = 0; i < allQuestions.size(); i++) {
        // figure out the number of times the questions has been asked
        int asks = allQuestions[i]->timesCorrect() + allQuestions[i]->timesIncorrect();
        timesAsked.append(asks);

        // sort into seen and unseen
        if (asks == 0)
            unseen.append(i);
        else
            seen.append(i);

        // add scores, known, learning, mostly learnt, and struggling lists
        if (asks == 0)
            scores.append(0);
        else {
            int score = allQuestions[i]->timesCorrect() / asks;
            scores.append(score);

            // the known list
            if (score >= 0.93 && asks >= 3)
                known.append(i);

            // the mostlyLearnt list
            else if (score >= 0.80 && asks >= 3)
                mostlyLearnt.append(i);

            // the learning list
            else if (score < 0.8 && asks >= 3)
                learning.append(i);

            // the struggling list
            if (score < 0.93 && asks >= 6)
                struggling.append(i);
        }
    }

    // the final step, calculating entries in the lottery
    for (int i = 0; i < allQuestions.size(); i++) {
        // let's calculate entries!
        int entriesCount = 1; // all questions start with 1 entry

        // award entries for being on the mostlyLearnt list
        if (mostlyLearnt.contains(i))
            entriesCount += 15;

        // award entries for being on the learning list
        if (learning.contains(i))
            entriesCount += 30;

        // award entries for being on the struggling list
        if (struggling.contains(i))
            entriesCount += 15; // this is in addition to learning, so total we have 15

        // award entries for being on the known list
        if (known.contains(i))
            entriesCount += 6;

        allEntries.append(entriesCount);
    }

}

void Algorithm::moveBatchUp() {
    currentBatch = nextBatch;
    nextBatch.clear();
}

Algorithm::~Algorithm() {
    for (int i = 0; i < allQuestions.size(); i++) {
        Question* nq = allQuestions[i];
        allQuestions.remove(i);
        delete nq;
    }
}
