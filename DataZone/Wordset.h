#ifndef WORDSET_H
#define WORDSET_H

#include "Noun.h"
#include "Verb.h"

class WordSet
{
public:
    // variables
    QList<Noun*> nouns;
    QList<Verb*> verbs;
    QList<Word*> allWords; // this list keeps the programmer from redundently searching both arrays when the kind of word is not needed.
    
    // variables for handling dtw files
    QString dtwName;

    // variables for handling wda files
    QString wdaName;

    // functions
    WordSet();
    ~WordSet();

    // functions for handling word files
    // TODO add handling for bad files
    bool parseWordFile(QString filePath);
    void parseWordLine(QString line);

    // functions for handling wissen files
    bool parseWissenFile(QString filePath);
    QString calcWDAName(QString dtwName); // calculates the name of the wissen data file.
    bool writeWissenFile(); // writes to a wissen file, returns false if not possible.
    void parseWissenLine(QString line);

    Word* findWordObject(QString word); // returns nullptr when word cannot be found
};

#endif // WORDSET_H
