#pragma once

#include "Word.h"

class Verb : public Word
{
public:
	const PartsOfSpeech partOfSpeech = VERB;
	QString ichConj;
	QString duConj;
	QString esConj;
	QString wirConj;
	QString ihrConj;
	QString sieConj;
	QString& infinitive = word;

	Verb(QString paramInfinitive, QString paramTranslation, QString paramIchConj, QString paramDuConj, QString paramErConj, QString paramWirConj, QString paramIhrConj, QString paramSieConj);
};
