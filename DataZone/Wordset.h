#ifndef WORDSET_H
#define WORDSET_H

#include "Noun.h"
#include "Verb.h"

class WordSet
{
public:
    // variables
    QList<Noun> nouns;
    QList<Verb> verbs;
    
    // functions
    WordSet();
    ~WordSet();
    Noun parseNoun(QString nounDat);
    Verb parseVerb(QString verbDat);
    void parseWordFile(QString filePath);
    void parseWissenFile(QString filePath);
    QString calcWDAName(QString dtwName); // calculates the name of the wissen data file.
    Word* findWordObject(QString word); // returns nullptr when word cannot be found
};

#endif // WORDSET_H
