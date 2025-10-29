#include "Wordset.h"

#include <QFile>
#include <QDebug>
#include <cstdlib>
#include <QMessageBox>

#define SUPPORTEDDTWVERSION 0.1

WordSet::WordSet() {}

void WordSet::parseLine(QString line) {
    // the words are organized in this order, nouns, verbs, TODO add other parts of speech
    QStringList lineParts = line.split(",");

    // don't parse a noun if, you know, there is one on this line (in cases where there are more verbs than nouns, there will be lines where the noun is left blank
    if (lineParts[4] != ""){
        // determine noun gender
        Gender wordGender;
        if (lineParts[5].toLower() == "der") {
            wordGender = DER;
        } else if (lineParts[5].toLower() == "die") {
            wordGender = DIE;
        } else if (lineParts[5].toLower() == "das") {
            wordGender = DAS;
        }

        Noun* newNoun = new Noun(lineParts[4], wordGender, lineParts[6]);
        allWords.append(newNoun);
        nouns.append(newNoun);
    }

    // same thing with the verbs, excpet they have more parts

    if (lineParts[21] != "") {
        Verb* newVerb = new Verb(lineParts[21], lineParts[22]);
        newVerb->ichConj = lineParts[23];
        newVerb->duConj = lineParts[24];
        newVerb->erConj = lineParts[25];
        newVerb->wirConj = lineParts[26];
        newVerb->ihrConj = lineParts[27];
        newVerb->sieConj = lineParts[28];

        newVerb->PartizipII = lineParts[29];
        newVerb->pratetitumIch = lineParts[33];

        // determine the values of the various codes

        // HSCode
        if (lineParts[30].toLower() == "haben")
            newVerb->HabenSein = HABEN;
        if (lineParts[30].toLower() == "sein")
            newVerb->HabenSein = SEIN;

        // StrengthCode
        if (lineParts[31].toLower() == "schwach")
            newVerb->SchwachStark = SCHWACH;
        if (lineParts[31].toLower() == "stark")
            newVerb->SchwachStark = STARK;

        // ModalCode
        if (lineParts[39].toLower() == "nein")
            newVerb->modal = NOTMODAL;
        if (lineParts[29].toLower() == "ja")
            newVerb->modal = MODAL;

        allWords.append(newVerb);
        verbs.append(newVerb);
    }
}

void WordSet::parseWordFile(QString filePath) {
    //TODO add version indicator on the file revision to dtw files.
    qDebug() << "Parsing word file: " << filePath;
    QFile questionFile(filePath);

    if(!questionFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // word files are really csv files, each collum contains a different part of the information, each row contains a different word, nouns and verbs are in different rows on the csv file.

    // each line contains one noun, verb, or other words, the parseLine funciton extracts them

    // This error should not be fatal later on.
    if (questionFile.readLine().split(',')[1].toDouble() > SUPPORTEDDTWVERSION + 0.000001) { // read the version line, QT's toDouble isn't perfectly accurate, wo we have to program in tolerance
        qDebug() << "unsupported file version used";
        QMessageBox error;
        error.setIcon(QMessageBox::Critical);
        error.setWindowTitle("Unsupported dtw file");
        error.setText("The dtw file you opened has a version that is of the wrong version, this is a fatal error. In the future, we will give you the ability to choose a new dtw file, nag Callen44 if he forgets.");
        error.setStandardButtons(QMessageBox::Ok);
        error.setDefaultButton(QMessageBox::Ok);
        error.exec();
        exit(1);
    }

    questionFile.readLine(); // removes the first line of headers
    questionFile.readLine(); // removes the second one


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
