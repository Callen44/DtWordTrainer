#include "Algorithm.h"

Algorithm::Algorithm() {

}

bool Algorithm::readFiles(QString fileName) {
    words.parseWordFile(fileName);
    words.parseWissenFile(words.calcWDAName(fileName));

    return true; // return code indicates success or failure, TODO.
}

Question Algorithm::nextQuestion() {
    Question nq(MCHOICEFOUR, &words.nouns[0]); // TODO, this is very temporary
    return nq;
}

Algorithm::~Algorithm() {

}
