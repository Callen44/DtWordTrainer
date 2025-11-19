#include "TPDTWLogic.h"

TPDTWLogic::TPDTWLogic(Word* associatedWord, WordSet* words)
    : Question(TPDTW, associatedWord), words(words) {

}

void TPDTWLogic::answer(QString answer) {
    if (associatedWord->word.toLower().trimmed() == answer.toLower().trimmed()) {
        associatedWord->defCorrects++;
    } else {
        associatedWord->defIncorrects++;
    }
}

int TPDTWLogic::timesCorrect() {
    return associatedWord->defCorrects;
}

int TPDTWLogic::timesIncorrect() {
    return associatedWord->defIncorrects;
}
