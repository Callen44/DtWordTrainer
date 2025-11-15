#include "Wordset.h"

#include <QFile>
#include <QDebug>
#include <cstdlib>
#include <QMessageBox>

#define SUPPORTEDDTWVERSION 0.1

WordSet::WordSet() {}

void WordSet::parseWordLine(QString line) {
    // the words are organized in this order, nouns, verbs, TODO add other parts of speech
    QStringList lineParts = line.split(",");

    // don't parse a noun if, you know, there is not one on this line (in cases where there are more verbs than nouns, there will be lines where the noun is left blank
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

bool WordSet::parseWordFile(QString filePath) {
    qDebug() << "Parsing word file: " << filePath;
    QFile questionFile(filePath);

    if(!questionFile.open(QIODevice::ReadOnly | QIODevice::Text)) // if file fails to open
        return false;

    // word files are really csv files, each collum contains a different part of the information, each row contains a different word, nouns and verbs are in different rows on the csv file.

    // each line contains one noun, verb, or other words, the parseWordLine funciton extracts them

    // TODO this error should not be fatal, it should allow the user to choose a different file.
    QList<QByteArray> z = questionFile.readLine().split(',');
    if (z.length() > 2 && z[1].toDouble() > SUPPORTEDDTWVERSION + 0.000001) { // read the version line, QT's toDouble isn't perfectly accurate, so we have to program in tolerance, plus, let's avoid segmentations faults caused by opening the wrong file shall we?
        qDebug() << "unsupported wda file version used";
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
        parseWordLine(questionFile.readLine());

    // if all was successful and we made it this far, mark this file as our dtw file
    dtwName = filePath;
    questionFile.close();
    return true;
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
    QFile wdaFile(wdaName);

    // make the file if it doesn't exist, then return, the word objects themselves will worry about creating blank data
    if (!wdaFile.exists()) {
        if (wdaFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            // create a template Wissen file
            wdaFile.write("Version:, 0.1, This file is usually preceeded by a \".\" making it a hidden file. This file uses the same format as dtw except that where pieces of information about the word would normally be, we see a fraction containing the number of times the user has gotten this information right over the number of times wrong.Abstraktes Wort,,,,Nomen,,,,,,,,,,,,,,,,,Verben,,,,,,,,,,,,,,,,,,\nWort,Definition,,,Wort,Gender,Definition,Nom.,Gen.,Dat.,Akk.,Pl. Nom.,Pl. Gen.,Pl. Dat.,Pl. Akk.,,,,,,,Infinitive,Definition,Ich,Du,Er,Wir,Ihr,Sie,Partizip II,h-s,Schwach Oder Stark,Seperable Info,Präteritum Ich,Präteritum Du,Präteritum Er,Präteritum Wir,Präteritum Ihr,Präteritum Sie,Modal\n");
            wdaFile.close();
            return true;
        } else {
            qDebug() << "Failed to create Wissen file, incorrect permissions? --- Initializing with blank data";
            return false;
        }
    } else { // just open it normally if it doesn't exist
        wdaFile.open(QIODevice::ReadWrite | QIODevice::Text);
    }

    wdaFile.resize(0); // resize the file to 0 bytes ... which empties it.
    wdaFile.write("Version:, 0.1, This file is usually preceeded by a \".\" making it a hidden file. This file uses the same format as dtw except that where pieces of information about the word would normally be, we see a fraction containing the number of times the user has gotten this information right over the number of times wrong.Abstraktes Wort,,,,Nomen,,,,,,,,,,,,,,,,,Verben,,,,,,,,,,,,,,,,,,\nWort,Definition,,,Wort,Gender,Definition,Nom.,Gen.,Dat.,Akk.,Pl. Nom.,Pl. Gen.,Pl. Dat.,Pl. Akk.,,,,,,,Infinitive,Definition,Ich,Du,Er,Wir,Ihr,Sie,Partizip II,h-s,Schwach Oder Stark,Seperable Info,Präteritum Ich,Präteritum Du,Präteritum Er,Präteritum Wir,Präteritum Ihr,Präteritum Sie,Modal\n");

    // this is where the magic happens
    QList<QString> lines;
    for (int i = 0; i < nouns.size(); i++) {
        lines.append(",,,,"); // since the nouns are processed first, we need to add the commas to the beginning for proper syntax
        lines[i] += nouns[i]->word + "," + QString::number(nouns[i]->genderCorrects) + "/" + QString::number(nouns[i]->genderIncorrects) + "," + QString::number(nouns[i]->defCorrects) + "/" + QString::number(nouns[i]->defIncorrects) + ","; // construct the long line that constains this data
    }

    for (int i = 0; i < verbs.size(); i++) {
        // avoid segemntation faults when we have more verbs than nouns
        if (nouns.size() <= i) {
            lines.append(",,,,,,,,,,,,,,,,,,,,,");
        } else {
            lines[i] += ",,,,,,,,,,,,,,";
        }

        // I don't even want to think about how long it took me to write this single line of code...
        lines[i] += verbs[i]->word + "," + QString::number(verbs[i]->defCorrects) + "/" + QString::number(verbs[i]->defIncorrects) + "," + QString::number(verbs[i]->ichCorrects) + "/" + QString::number(verbs[i]->ichIncorrects) + "," + QString::number(verbs[i]->duCorrects) + "/" + QString::number(verbs[i]->duIncorrects) + "," + QString::number(verbs[i]->erCorrects) + "/" + QString::number(verbs[i]->erIncorrects) + "," + QString::number(verbs[i]->wirCorrects) + "/" + QString::number(verbs[i]->wirIncorrects) + "," + QString::number(verbs[i]->ihrCorrects) + "/" + QString::number(verbs[i]->ihrIncorrects) + "," + QString::number(verbs[i]->sieCorrects) + "/" + QString::number(verbs[i]->sieIncorrects) + ",";
    }

    // write all this junk to the file :)
    for (int i = 0; i < lines.size(); i++) {
        wdaFile.write(lines[i].toUtf8());
        wdaFile.write("\n");
    }

    wdaFile.close();
    return true;
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

void WordSet::parseWissenLine(QString line) {
    // the words are organized in this order, nouns, verbs, TODO add other parts of speech
    QStringList lineParts = line.split(",");

    // handle nouns
    if (lineParts[4] != ""){ // the word will have it's base form on section 4, but the actual data is after that section
        Word* thisWord = findWordObject(lineParts[4]); // make sure that we're getting a noun before risking a reinterpret cast
        if (thisWord->partOfSpeech != NOUN)
            return;
        Noun* thisNoun = reinterpret_cast<Noun*>(thisWord); // call me devious, I love reinterpret casts!

        thisNoun->defCorrects = lineParts[6].split("/")[0].toInt(); // fancy way to get the number of times the question was correct, little weird but compact
        thisNoun->defIncorrects = lineParts[6].split("/")[1].toInt(); // same thing, but the incorrects
        thisNoun->genderCorrects = lineParts[5].split("/")[0].toInt(); // same this with gender
        thisNoun->genderIncorrects = lineParts[5].split("/")[1].toInt();
    }

    // handle verbs
    if (lineParts[21] != "") {
        Word* thisWord = findWordObject(lineParts[21]);
        if (thisWord->partOfSpeech != VERB)
            return;
        Verb* thisVerb = reinterpret_cast<Verb*>(thisWord);

        thisVerb->defCorrects = lineParts[22].split("/")[0].toInt();
        thisVerb->defIncorrects = lineParts[22].split("/")[1].toInt();
        thisVerb->ichCorrects = lineParts[23].split("/")[0].toInt();
        thisVerb->ichIncorrects = lineParts[23].split("/")[1].toInt();
        thisVerb->duCorrects = lineParts[24].split("/")[0].toInt();
        thisVerb->duIncorrects = lineParts[24].split("/")[1].toInt();
        thisVerb->erCorrects = lineParts[25].split("/")[0].toInt();
        thisVerb->erIncorrects = lineParts[25].split("/")[1].toInt();
        thisVerb->wirCorrects = lineParts[26].split("/")[0].toInt();
        thisVerb->wirIncorrects = lineParts[26].split("/")[1].toInt();
        thisVerb->ihrCorrects = lineParts[27].split("/")[0].toInt();
        thisVerb->ihrIncorrects = lineParts[27].split("/")[1].toInt();
        thisVerb->sieCorrects = lineParts[28].split("/")[0].toInt();
        thisVerb->sieIncorrects = lineParts[28].split("/")[1].toInt();
    }
}

bool WordSet::parseWissenFile(QString filePath) {
    QFile wdaFile(filePath);

    // make the file if it doesn't exist, then return, the word objects themselves will worry about creating blank data
    if (!wdaFile.exists()) {
        if (wdaFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            // create a template Wissen file
            wdaFile.write("Version:, 0.1, This file is usually preceeded by a \".\" making it a hidden file. This file uses the same format as dtw except that where pieces of information about the word would normally be, we see a fraction containing the number of times the user has gotten this information right over the number of times wrong.Abstraktes Wort,,,,Nomen,,,,,,,,,,,,,,,,,Verben,,,,,,,,,,,,,,,,,,\nWort,Definition,,,Wort,Gender,Definition,Nom.,Gen.,Dat.,Akk.,Pl. Nom.,Pl. Gen.,Pl. Dat.,Pl. Akk.,,,,,,,Infinitive,Definition,Ich,Du,Er,Wir,Ihr,Sie,Partizip II,h-s,Schwach Oder Stark,Seperable Info,Präteritum Ich,Präteritum Du,Präteritum Er,Präteritum Wir,Präteritum Ihr,Präteritum Sie,Modal\n");
            wdaFile.close();
            wdaName = filePath;
            return true;
        } else {
            qDebug() << "Failed to create Wissen file, incorrect permissions? --- Initializing with blank data";
            return false;
        }
    } else { // just open it normally if it doesn't exist
        wdaFile.open(QIODevice::ReadWrite | QIODevice::Text);
    }

    // read the file if it does exist
    qDebug() << "Parsing wissen file: " << filePath;

    // read the wissen file version, if it fails to pass the version check then we'll return false and not open the file
    QList<QByteArray> z = wdaFile.readLine().split(',');
    if (z.length() > 2 && z[1].toDouble() > SUPPORTEDDTWVERSION + 0.000001) { // read the version line, QT's toDouble isn't perfectly accurate, so we have to program in tolerance, plus, let's avoid segmentations faults caused by opening the wrong file shall we?
        qDebug() << "Unsupported wissen file version used. --- Initializing with blank data";
        wdaFile.close();
        return false;
    }

    wdaFile.readLine(); // removes the first line of headers
    wdaFile.readLine(); // removes the second one


    while (!wdaFile.atEnd())
        parseWissenLine(wdaFile.readLine());

    // if all was successful and we made it this far, mark this file as our wda File, close it, and prepare for later
    wdaFile.close();
    wdaName = filePath;
    return true;
}

WordSet::~WordSet() {
    allWords.clear();
    for (int i = 0; i < nouns.size(); i++) {
        Word* cword = nouns[i];
        nouns.remove(i);
        delete cword;
    }
    for (int i = 0; i < verbs.size(); i++) {
        Word* cword = verbs[i];
        verbs.remove(i);
        delete cword;
    }
}
