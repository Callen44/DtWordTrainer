#include "Verb.h"

Verb::Verb(QString paramInfinitive, QString paramTranslation) {
    this->partOfSpeech = VERB;
    this->word = paramInfinitive;
    this->translation = paramTranslation;
}
