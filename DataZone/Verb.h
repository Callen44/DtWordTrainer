#pragma once

#include "Word.h"

enum HSCode {
    HABEN,
    SEIN
};

enum StrengthCode {
    STARK,
    SCHWACH
};

enum ModalCode {
    MODAL,
    NOTMODAL
};

class Verb : public Word
{
public:
	PartOS partOfSpeech = VERB;

	QString ichConj;
	QString duConj;
    QString erConj;
	QString wirConj;
	QString ihrConj;
	QString sieConj;

    HSCode HabenSein;
    StrengthCode SchwachStark;
    ModalCode modal;

    // TODO, much later, add seperable verb support
    QString pratetitumIch;

    QString PartizipII;

    // knowledge information
    int ichCorrects = 0;
    int ichIncorrects = 0;
    int duCorrects = 0;
    int duIncorrects = 0;
    int erCorrects = 0;
    int erIncorrects = 0;
    int wirCorrects = 0;
    int wirIncorrects = 0;
    int ihrCorrects = 0;
    int ihrIncorrects = 0;
    int sieCorrects = 0;
    int sieIncorrects = 0;
    int HSCorrects = 0;
    int HSIncorrects = 0;

    Verb(Word* word);
    Verb(QString infinitive, QString translation)
        :Word(VERB, translation, infinitive) {}
};
