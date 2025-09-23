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

    // functions for handling word files
    Noun parseNoun(QString nounDat);
    Verb parseVerb(QString verbDat);
    void parseWordFile(QString filePath);

    // functions for handling wissen files
    bool parseWissenFile(QString filePath);
    QString calcWDAName(QString dtwName); // calculates the name of the wissen data file.
    bool makeWissenFile(QString wdaName); // creates a wissen file, returns error code if not possible

    Word* findWordObject(QString word); // returns nullptr when word cannot be found
};

#endif // WORDSET_H
