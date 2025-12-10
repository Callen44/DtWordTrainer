#include "TPDTWLogic.h"

bool TPDTWLogic::answer(QString answer) {
    if (associatedWord->word.toLower().trimmed() == answer.toLower().trimmed()) {
        associatedWord->defCorrects++;
        correctLast = true;
        return true;
    } else {
        associatedWord->defIncorrects++;
        correctLast = false;
        return false;
    }
}

int TPDTWLogic::timesCorrect() {
    return associatedWord->defCorrects;
}

int TPDTWLogic::timesIncorrect() {
    return associatedWord->defIncorrects;
}
