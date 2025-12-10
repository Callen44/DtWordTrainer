#include "Algorithm.h"
#include <random>

Algorithm::Algorithm() {
    // -------- initialize data ---------

    // fill both batches with nullptrs to stop memory leaks
    for (int i = 0; i < 10; i++) {
        currentBatch[i] = nullptr;
        nextBatch[i] = nullptr;
    }
}

bool Algorithm::readFiles(QString fileName) {
    // ---------- actually read the files ------------

    // TODO, this should not be a fatal error
    if (!words.parseWordFile(fileName)){
        qDebug() << "Files failed to open, are they writable?\nThis is a fatal error.";
        exit(1);
    }

    if (!words.parseWissenFile(words.produceWDAName()))
        qDebug() << "Failed to open wissen file, data will be filled with blank info.";

    // --------- prep step, make every possible question ----------
    for (int i = 0; i < words.allWords.size(); i++) {
        if (words.allWords[i]->partOfSpeech == NOUN) {
            // Questions that only nouns can have
            Noun* wordIQ = reinterpret_cast<Noun*>(words.allWords[i]); // stands for word in question

            // choose gender question
            CHGNDLogic* newCHGND = new CHGNDLogic(wordIQ);
            questionPool.append(newCHGND);

        } else if (words.allWords[i]->partOfSpeech == VERB) {
            // Questions that only verbs can have
            Verb* wordIQ = reinterpret_cast<Verb*>(words.allWords[i]); // stands for word in question
            // TODO Make some!
        }
        // Questions that all words can have

        // the classic multiple choice definition question
        MCFDLogic* newMCFD = new MCFDLogic(words.allWords[i], &words);
        questionPool.append(newMCFD);

        // type the word in German
        TPDTWLogic* newTPDTW = new TPDTWLogic(words.allWords[i], &words);
        questionPool.append(newTPDTW);
    }
    // run initial data calculation for the first questions
    recalculateData();

    return true;
}

Question* Algorithm::nextQuestion() {
    // begin with an autosave to keep things up to date
    words.writeWissenFile();

    // set lastAsked
    if (batchIndex != 0)
        lastAsked = currentBatch[batchIndex-1];
    else
        lastAsked = nullptr;

    // ------- Handle cleanup steps from last question -------
    if (batchIndex > 1 && lastAsked->correctLast == false)
        nextBatch[batchIndex-1] = lastAsked; // if the last question was answered wrongly, then we reschedule it to be asked again

    // -------- Handle this question --------
    // fill a question if it is not already filled (in the event that a new one hasn't been scheduled)
    Question* chosenQuestion;
    
    if (currentBatch[batchIndex] == nullptr) { // check for a scheduled question
        // prevent the annoying situation where the same question is repeatedly asked over and over
        if (lastAsked == nullptr) {
            chosenQuestion = produceQuestion();
            currentBatch[batchIndex] = chosenQuestion;
        } else {
            chosenQuestion = produceQuestion();
            currentBatch[batchIndex] = chosenQuestion;
            while (chosenQuestion->associatedWord == lastAsked->associatedWord) {
                chosenQuestion = produceQuestion();
                currentBatch[batchIndex] = chosenQuestion;
            }
        }
    } else {
        chosenQuestion = currentBatch[batchIndex];
    }

    // extract our question from the batch before incermenting the index
    batchIndex++;

    // move up batches in case we need to
    if (batchIndex >= 10)
        moveBatchUp();

    return chosenQuestion;
}

Question* Algorithm::produceQuestion() {
    // --------- the lottery program -----------

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
    Question* chosenQuestion = livePool[currentQuestionIndex];

    // return the questions we've chosen
    if (chosenQuestion == nullptr) // TODO for some reason it's possible for this statment to be true, I don't know why
        return livePool[1];    

    return chosenQuestion;
}

void Algorithm::recalculateData() {
    // run through each word's specific information, then recalculate the overall data of the question set.
    allEntries.clear(); // clear out all old information

    // on the lists below we store our data, questions are identified by their indexes on the questionPool list
    QList<double> scores; // a list that aligns with questionPool, keeps track of the percentage of times that user has gotten that question correct.
    QList<int> timesAsked; // keeps track of the number of times a question has been asked
    QList<int> unseen; // a list of the indexes of questions that have never been asked before
    QList<int> seen; // the opposite of unseen
    QList<int> known; // questions that have a score (from scores list) of over 93% and three askings
    QList<int> mostlyLearnt; // questions that the user has been asked at least 3 times, with a score between 80% and 90%
    QList<int> learning; // questions that the user is actively learning, been asked at least thrice, but with under 80% score
    QList<int> struggling; // these are questions from either the learning or mostlyLearnt lists that the user has been asked 6 or more times
    QList<int> inFocus; // a combination of mostlyLearnt, learning, and struggling, this is the bulk of the questions we're learning
    // generate scores list and timesAsked
    for (int i = 0; i < questionPool.size(); i++) {
        // figure out the number of times the questions has been asked
        int asks = questionPool[i]->timesCorrect() + questionPool[i]->timesIncorrect();
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
            double score = questionPool[i]->timesCorrect() / asks;
            scores.append(score);

            // the known list
            if (score >= 0.93 && asks >= 4) {
                known.append(i);

            // the mostlyLearnt list
            } else if (score >= 0.80 && asks >= 4) {
                mostlyLearnt.append(i);
                inFocus.append(i);

            // the learning list
            } else if (score < 0.7 && asks <= 3) {
                learning.append(i);
                inFocus.append(i);
            }

            // the struggling list
            if (score < 0.7 && asks >= 6) {
                struggling.append(i);
                inFocus.append(i);
            }
        }
    }

    // ----------- create livePool ----------
    double compoundedScores = 0; // get the average score of the inFocus questions
    for (int i = 0; i < inFocus.size(); i++) {
        compoundedScores += scores[inFocus[i]];
        qDebug() << scores[inFocus[i]];
    }
    
    double averageInFocusScore;
    if (inFocus.size() > 0)
        averageInFocusScore = compoundedScores / inFocus.size();
    else
        averageInFocusScore = 0.0;

    // clear out livePool, re-add questions that have been seen, and then add our new questions (if applicable)
    livePool.clear();
    livePoolIndexes.clear();
    for (int i = 0; i < inFocus.size(); i++) {
        livePool.append(questionPool[inFocus[i]]);
        livePoolIndexes.append(inFocus[i]);
    }

    // don't add new questions if the user isn't ready for them
    if (averageInFocusScore >= 0.8 && livePool.size() < 45) {
        for (int i = 0; i < 5; i++) { // add five new words
            introduceAnyWord();
        }
    }

    // last but not least, let's make sure that if there are at least 20 questions in livePool at all times
    while (livePool.size() < 20) {
        introduceAnyWord();
    }

    // ----------- the final step, calculating entries in the lottery ---------
    for (int i = 0; i < livePoolIndexes.size(); i++) {
        // let's calculate entries!
        int entriesCount = 5; // all questions start with 5 entries

        // award entries for being on the mostlyLearnt list
        if (mostlyLearnt.contains(livePoolIndexes[i]))
            entriesCount += 10;

        // award entries for being on the learning list
        if (learning.contains(livePoolIndexes[i]))
            entriesCount += 25;

        // award entries for being on the struggling list
        if (struggling.contains(livePoolIndexes[i]))
            entriesCount += 35; // this is in addition to learning, so total we have 15

        // award entries for being on the known list
        if (known.contains(livePoolIndexes[i]))
            entriesCount += 1;

        if (unseen.contains(livePoolIndexes[i]))
            entriesCount += 10;

        allEntries.append(entriesCount);
    }
    qDebug() << "-----------------------------------------------------";
    qDebug() << "known: " << known.size();
    qDebug() << "mostlyLearnt: " << mostlyLearnt.size();
    qDebug() << "learning: " << learning.size();
    qDebug() << "struggling: " << struggling.size();
    qDebug() << "";
    qDebug() << "seen: " << seen.size();
    qDebug() << "unseen: " << unseen.size();
    qDebug() << "";
    qDebug() << "livePool: " << livePool.size();
    qDebug() << "average inFocus score: " << averageInFocusScore;
    qDebug() << "compounded scores: " << compoundedScores;
}

void Algorithm::moveBatchUp() {
    // since these are arrays, it's more complicated to move them up
    for (int i = 0; i < 10; i++) {
        currentBatch[i] = nextBatch[i];
        nextBatch[i] = nullptr;
    }

    batchIndex = 0;
    recalculateData();
}

void Algorithm::introduceWord(Word* word) {
    for (int i = 0; i < questionPool.size(); i++) {
        if (questionPool[i]->associatedWord == word) {
            livePool.append(questionPool[i]);
            livePoolIndexes.append(i);
        }
    }
}

void Algorithm::introduceAnyWord() {
    int a = std::rand() % words.allWords.size();
    introduceWord(words.allWords[a]);
}

Algorithm::~Algorithm() {
    for (int i = 0; i < questionPool.size(); i++) {
        Question* nq = questionPool[i];
        questionPool.remove(i);
        delete nq;
    }
}
