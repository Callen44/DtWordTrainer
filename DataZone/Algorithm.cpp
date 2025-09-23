#include "Algorithm.h"

Algorithm::Algorithm() {

}

bool Algorithm::readFiles(QString fileName) {
    words.parseWordFile(fileName);
    firstQuestion = !words.parseWissenFile(words.calcWDAName(fileName)); // if parseWissenFile returns false, that menas there simply is no wissen file

    return true; // return code indicates success or failure, TODO.
}

Question Algorithm::nextQuestion() {
    Question nq(MCHOICEFOUR, &words.nouns[0]); // TODO, this is very temporary
    return nq;
}

Algorithm::~Algorithm() {

}
