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
    // constructor functions
    Noun(Word* word);
    Noun(QString word, Gender gender, QString translation)
        : Word(NOUN, translation, word), gender(gender) {}

    // utility functions
    QString genderAsString();

    // word variables, these go in dtw files
    Gender gender;
    PartOS partOfSpeech = NOUN;

    // data variables, these go in wda files
    int genderCorrects = 0;
    int genderIncorrects = 0;
};
