#pragma once

#include <QString>
#include <QList>
#include <limits.h>

enum PartOS { // this is taked off of a list of the parts of speech on the internet, it may prove to have too many different items, I could cull some, we'll see
	NOUN,
	VERB,
	ADJECTIVE,
	ADVERB,
	PRONOUN,
	PREPOSITION,
	CONJUNCTION,
	ARTICLE,
	INTERJUINCTION,
	PARTICIPLE
};

class Word
{
public:
	QString word;
	PartOS partOfSpeech;
	QString translation;
    QString details = "";

    int defCorrects = 0; // how well the user knows the word and it's english equivelant.
    int defIncorrects = 0;
    int lastAppearance = -1; // this number states what question was this word's last appearance, 0 is the first question asked, 1 is the next, and so on, this is used so that we don't see the same question appear over and over.
};
