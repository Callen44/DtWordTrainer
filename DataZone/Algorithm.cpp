#include "Algorithm.h"

Algorithm::Algorithm() {

}

bool Algorithm::readFiles(QString fileName) {
    words.parseWordFile(fileName);
    firstQuestion = !words.parseWissenFile(words.calcWDAName(fileName)); // if parseWissenFile returns false, that menas there simply is no wissen file

    return true; // return code indicates success or failure, TODO.
}

Question* Algorithm::nextQuestion() {
    // pick a question type
    // TODO, this is very temporary as this is the only implemented question type
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
}

Algorithm::~Algorithm() {

}
