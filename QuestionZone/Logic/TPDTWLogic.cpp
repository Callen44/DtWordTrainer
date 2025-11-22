#include "TPDTWLogic.h"

TPDTWLogic::TPDTWLogic(Word* associatedWord, WordSet* words)
    : Question(TPDTW, associatedWord), words(words) {

}

bool TPDTWLogic::answer(QString answer) {
    if (associatedWord->word.toLower().trimmed() == answer.toLower().trimmed()) {
        associatedWord->defCorrects++;
        return true;
    } else {
        associatedWord->defIncorrects++;
        return false;
    }
}

int TPDTWLogic::timesCorrect() {
    return associatedWord->defCorrects;
}

int TPDTWLogic::timesIncorrect() {
    return associatedWord->defIncorrects;
}
