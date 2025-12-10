#include "CHGNDLogic.h"
#include <QDebug>

CHGNDLogic::CHGNDLogic(Noun* associatedWord)
    : Question(CHGND, associatedWord, 2) {
    if (associatedWord->partOfSpeech != NOUN) {
        qDebug() << "CHGND has been initialized with invalid data";
        delete this; // this is to prevent chgndLogic from being called on anything but a noun. This will trigger a segmentation fault if it does happen... TODO this is temporary at the moment this particular error is impossible, so a temporary fix is okay.    
    }
        correctGender = associatedWord->gender;
}

void CHGNDLogic::answer(bool correct) {
    // reinterpret cast the associatedWord as a Noun
    Noun* myNoun = reinterpret_cast<Noun*>(associatedWord);

    if (correct) {
        myNoun->genderCorrects++;
    } else {
        myNoun->genderIncorrects++;
    }
}

int CHGNDLogic::timesCorrect() {
    // reinterpret cast the associatedWord as a Noun
    Noun* myNoun = reinterpret_cast<Noun*>(associatedWord);
    return myNoun->genderCorrects;
}

int CHGNDLogic::timesIncorrect() {
    // reinterpret cast the associatedWord as a Noun
    Noun* myNoun = reinterpret_cast<Noun*>(associatedWord);
    return myNoun->genderIncorrects;
}
