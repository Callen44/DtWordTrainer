#pragma once

#include "Word.h"

enum Gender {
	DER,
	DIE,
	DAS
};

class Noun : public Word
{
public:
	Gender gender;
	PartOS partOfSpeech = NOUN;
    Noun(QString word, Gender gender, QString translation)
        : Word(NOUN, translation, word), gender(gender) {}
};
