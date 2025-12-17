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
    PARTICIPLE,
    ABSTRACT // allows the part of speech to be unspecified used by DummyWord
};

class Word
{
public:
	QString word;
    const PartOS partOfSpeech;
	QString translation;
    QString details = "";

    int defCorrects = 0; // how well the user knows the word and it's english equivelant.
    int defIncorrects = 0;

    Word(PartOS partOfSpeech, QString translation, QString word)
        : partOfSpeech(partOfSpeech), translation(translation), word(word) {}
};
