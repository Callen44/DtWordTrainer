#include "Noun.h"

Noun::Noun(QString paramWord, Gender paramGender, QString paramTranslation) {
    this->partOfSpeech = NOUN;
	this->gender = paramGender;
	this->word = paramWord;
	this->translation = paramTranslation;
}
