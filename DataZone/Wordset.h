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
    
    QString dtwName;

    // functions
    WordSet();
    ~WordSet();

    // functions for handling word files
    // TODO add handling for bad files
    bool parseWordFile(QString filePath);
    void parseLine(QString line);

    // functions for handling wissen files
    bool parseWissenFile(QString filePath);
    QString calcWDAName(QString dtwName); // calculates the name of the wissen data file.
    bool writeWissenFile(); // creates a wissen file, returns error code if not possible

    Word* findWordObject(QString word); // returns nullptr when word cannot be found
};

#endif // WORDSET_H
