#include "Wordset.h"

#include <QFile>
#include <QDebug>

WordSet::WordSet() {}

Verb WordSet::parseVerb(QString verbDat) {
    QStringList sections = verbDat.split('\n')[0].split(' '); // split the word and chop off the newline

    Verb newVerb(sections[0].toLower(), sections[7].toLower(), sections[1].toLower(), sections[2].toLower(), sections[3].toLower(), sections[4].toLower(), sections[5].toLower(), sections[6].toLower());
    return newVerb;
}

Noun WordSet::parseNoun(QString nounDat) {
    QStringList sections = nounDat.split(" ");

    Gender wordGender;
    if (sections[1].toLower() == "der")
        wordGender = DER;
    else if (sections[1].toLower() == "die")
        wordGender = DIE;
    else if (sections[1].toLower() == "das")
        wordGender = DAS;

    Noun newNoun(sections[0].toLower(), wordGender, sections[2].toLower());
    return newNoun;
}

void WordSet::parseWordFile(QString filePath) {
    qDebug() << "Parsing word file: " << filePath;
    QFile questionFile(filePath);
    PartOS cpos = NOUN;


    if (!questionFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while(!questionFile.atEnd()) {
        QString line = questionFile.readLine();

        if (line == "[Verbs]\n")
            cpos = VERB;
        else if (line == "[Nouns]\n")
            cpos = NOUN;
        // in this case we have a word, not one of the lines as shown above
        else {
            if (cpos == NOUN) {
                Noun noun = parseNoun(line);
                nouns.append(noun);
            } else if (cpos == VERB) {
                Verb verb = parseVerb(line);
                verbs.append(verb);
            }
        }
    }
}

QString WordSet::calcWDAName(QString dtwFileName) {
/*
 * finding the wissen data file (contains how well the user knows the words) is harder
 * this data file is a hidden file so that the user doesn't need to know it's there.
 * because the user doesn't know about it, we have to be creative with finding it's location
*/

    // calculate the wissen data file filename.
    QStringList fileNameParts = dtwFileName.split("/");
    QString actualFileName = fileNameParts.back();
    QString newFileName = "." + actualFileName.split(".")[0] + ".wda"; // will return .[filename before extension].wda

    // generate the full path
    fileNameParts.back() = newFileName;
    return fileNameParts.join("/");

}

Word* WordSet::findWordObject(QString word) {
    for (int i = 0; i < nouns.length(); i++) {
        if (nouns[i].word == word)
            return &nouns[i];
    }
    for (int i = 0; i < verbs.length(); i++) {
        if (verbs[i].word == word)
            return &verbs[i];
    }

    // if the word cannot be found, avoid undefined behavior with a nullptr
    return nullptr;
}

void WordSet::parseWissenFile(QString filePath) {
    qDebug() << "Parsing word Wissen data file: " << filePath;
    PartOS cpos;

    QFile wissenFile(filePath);
    if (!wissenFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    while (!wissenFile.atEnd()) {
        QString line = wissenFile.readLine();

        if (line == "[Verbs]\n")
            cpos = VERB;
        else if (line == "[Nouns]\n")
            cpos = NOUN;
        // in this case we have a word, not one of the lines as shown above
        else {
            if (cpos == NOUN) {
                Word* word = findWordObject(line.split(" ")[0]);
                word->
            }
            else if (cpos == VERB) {

            }
        }
    }
}

WordSet::~WordSet() {
    
}