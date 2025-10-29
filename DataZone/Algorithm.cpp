#include "Algorithm.h"

Algorithm::Algorithm() {

}

bool Algorithm::readFiles(QString fileName) {
    if (!words.parseWordFile(fileName) || !words.parseWissenFile(words.calcWDAName(fileName))){
        qDebug() << "Files failed to open, are they writable?\nThis is a fatal error.";
        exit(1);
    }

    // prep step, make every possible question
    for (int i = 0; i < words.allWords.size(); i++) {
        PartOS pos = words.allWords[i]->partOfSpeech;
    }
}

Question* Algorithm::nextQuestion() {

    /* ======== The old system ========
    QVariety questionVariety = MCHOICEFOURDEF;

    double worstScore = 0.0;
    Word* worstWord;

    // pick the word where the user is the worst at the definition
    for (int i = 0; i < words.allWords.size(); i++) {
        double score = 0.0;

        Word* wordInQuestion = words.allWords[i];
        if (wordInQuestion->defIncorrects + wordInQuestion->defCorrects != 0) {
            score = wordInQuestion->defCorrects / (wordInQuestion->defIncorrects + wordInQuestion->defCorrects);
        } else {
            worstWord = wordInQuestion;
            break;
        }

        if (score < worstScore) {
            worstScore = score;
            worstWord = wordInQuestion;
        }
    }

    MChoiceFourDef* nq = new MChoiceFourDef(worstWord, &words);
    return nq;
    */

    return new MChoiceFourDef(words.nouns[0], &words);
}

void Algorithm::recalculateData() {
    // run through each word's specific information, then recalculate the overall data of the question set.

}

void Algorithm::moveBatchUp() {

}

Algorithm::~Algorithm() {

}
