#pragma once
#include "Noun.h"
#include "Verb.h"

class WordSet
{
public:
    // variables
    QList<Noun*> nouns;
    QList<Verb*> verbs;
    QList<Word*> allWords; // this list keeps the programmer from redundently searching both arrays when the kind of word is not needed.
    QList<Word*> dummys; // a list of all dummy words, words that are placeholders for those we don't have the whole word definition of, not included in all words, but they are in allnouns and allverbs

    // variables for handling dtw files
    QString dtwName;

    // variables for handling wda files
    QString wdaName;
    bool wdaLess = false;

    // misc. functions
    WordSet();
    ~WordSet();
    bool save(); // saves the wordset to its file

    // three function signitures for adding different parts of speech, these functions add the word and then save it
    void addWord(Noun word);
    void addWord(Verb word);
    void addWord(Word word);

    // functions for handling word files
    // TODO add handling for bad files
    bool parseWordFile(QString filePath);
    void parseWordLine(QString line);

    // functions for handling wissen files
    bool parseWissenFile(QString filePath);
    QString produceWDAName(); // calculates the name of the wissen data file.
    bool writeWissenFile(); // writes to a wissen file, returns false if not possible.
    void parseWissenLine(QString line);

    Word* findWordObject(QString word); // returns nullptr when word cannot be found
};
