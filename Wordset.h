#ifndef WORDSET_H
#define WORDSET_H

#include "Noun.h"
#include "Verb.h"

class WordSet
{
public:
    WordSet();
    QList<Noun*> nouns;
    QList<Verb*> verbs;
    Noun* parseNoun(QString nounDat);
    Verb* parseVerb(QString verbDat);
    void parseFile(QString filePath);
};

#endif // WORDSET_H
