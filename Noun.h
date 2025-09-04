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
	const PartsOfSpeech partOfSpeech = NOUN;
    Noun(QString paramWord, Gender paramGender, QString paramTranslation);
};
