#include "Algorithm.h"

Algorithm::Algorithm() {

}

bool Algorithm::readFiles(QString fileName) {
    words.parseWordFile(fileName);
    firstQuestion = !words.parseWissenFile(words.calcWDAName(fileName)); // if parseWissenFile returns false, that menas there simply is no wissen file

    return true; // return code indicates success or failure, TODO.
}

Question* Algorithm::nextQuestion() {
    // this function determines the best next question and will return it, it does so by evaluating what words have been seen recently and which ones haven't, and how well the user knows what words.

    // at the moment, we have a rather temoprary solution in place (always returning the same word).
    MChoiceFourDef* nq = new MChoiceFourDef(&words.nouns[0], &words);
    return nq;
}

Algorithm::~Algorithm() {

}
