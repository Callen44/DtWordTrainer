#include "Wordset.h"

#include <QFile>
#include <QDebug>
#include <cstdlib>

WordSet::WordSet() {}

void WordSet::parseLine(QString line) {
    // the words are organized in this order, nouns, verbs, TODO add other parts of speech
    QStringList lineParts = line.split(",");

    // determine noun
    Gender wordGender;
    if (lineParts[1] == "Der") {
        wordGender = DER;
    } else if (lineParts[1] == "Die") {
        wordGender = DIE;
    } else if (lineParts[1] == "Das") {
        wordGender = DAS;
    }

    // don't parse a noun if, you know, there is one on this line (in cases where there are more verbs than nouns, there will be lines where the noun is left blank
    if (lineParts[0] != ""){
        Noun* newNoun = new Noun(lineParts[0], wordGender, lineParts[2]);
        allWords.append(newNoun);
        nouns.append(newNoun);
    }
}

void WordSet::parseWordFile(QString filePath) {
    qDebug() << "Parsing word file: " << filePath;
    QFile questionFile(filePath);

    if(!questionFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // word files are really csv files, each collum contains a different part of the information, each row contains a different word, nouns and verbs are in different rows on the csv file.

    // each line contains one noun, verb, or other words, the parseLine funciton extracts them
    while (!questionFile.atEnd())
        parseLine(questionFile.readLine());

    // if all was successful and we made it this far, mark this file as our dtw file
    dtwName = filePath;
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

bool WordSet::writeWissenFile() {
    // TODO, rewrite this for the new file format soon

    return false; // the return code indicates success or failure. TODO
}

Word* WordSet::findWordObject(QString word) {
    for (int i = 0; i < nouns.length(); i++) {
        if (nouns[i]->word.toLower() == word.toLower())
            return nouns[i];
    }
    for (int i = 0; i < verbs.length(); i++) {
        if (verbs[i]->word.toLower() == word.toLower())
            return verbs[i];
    }

    // if the word cannot be found, avoid undefined behavior with a nullptr
    return nullptr;
}

bool WordSet::parseWissenFile(QString filePath) {
    return false;
}

WordSet::~WordSet() {
    
}
