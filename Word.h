#pragma once

#include <QString>
#include <QList>

enum PartsOfSpeech { // this is taked off of a list of the parts of speech on the internet, it may prove to have too many different items, I could cull some, we'll see
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
	PartsOfSpeech partOfSpeech;
	QString translation;
	QString details;
};
