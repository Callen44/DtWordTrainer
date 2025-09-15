#include "Verb.h"

Verb::Verb(QString paramInfinitive, QString paramTranslation, QString paramIchConj, QString paramDuConj, QString paramErConj, QString paramWirConj, QString paramIhrConj, QString paramSieConj) {
    this->partOfSpeech = VERB;
    this->word = paramInfinitive;
	this->translation = paramTranslation;
	this->ichConj = paramIchConj;
	this->duConj = paramDuConj;
	this->esConj = paramErConj;
	this->wirConj = paramWirConj;
	this->ihrConj = paramIhrConj;
	this->sieConj = paramSieConj;
}
