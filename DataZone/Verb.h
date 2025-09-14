#pragma once

#include "Word.h"

class Verb : public Word
{
public:
	PartOS partOfSpeech = VERB;
	QString ichConj;
	QString duConj;
	QString esConj;
	QString wirConj;
	QString ihrConj;
	QString sieConj;

	Verb(QString paramInfinitive, QString paramTranslation, QString paramIchConj, QString paramDuConj, QString paramErConj, QString paramWirConj, QString paramIhrConj, QString paramSieConj);
};
