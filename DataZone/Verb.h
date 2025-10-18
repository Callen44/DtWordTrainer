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

    Verb(QString paramInfinitive, QString paramTranslation);
};
