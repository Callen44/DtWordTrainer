#include "Wordset.h"

#include <QFile>
#include <QDebug>
#include <cstdlib>

WordSet::WordSet() {}

Verb WordSet::parseVerb(QString verbDat) {
    QStringList sections = verbDat.split('\n')[0].split(' '); // split the word and chop off the newline

    Verb newVerb(sections[0].toLower(), sections[7].toLower(), sections[1].toLower(), sections[2].toLower(), sections[3].toLower(), sections[4].toLower(), sections[5].toLower(), sections[6].toLower());
    return newVerb;
}

Noun WordSet::parseNoun(QString nounDat) {
    QStringList sections = nounDat.split('\n')[0].split(" "); // split the word and chop off the newline

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

    if (!questionFile.exists()) {
        qDebug() << "Could not find file, this is a fatal error";
        exit(1);
    }

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

bool WordSet::makeWissenFile(QString wdaName) {
    qDebug() << "this function has not been implemented yet (makeWissenFile)";
    return false; // the return code indicates success or failure. TODO
}

Word* WordSet::findWordObject(QString word) {
    for (int i = 0; i < nouns.length(); i++) {
        if (nouns[i].word.toLower() == word.toLower())
            return &nouns[i];
    }
    for (int i = 0; i < verbs.length(); i++) {
        if (verbs[i].word.toLower() == word.toLower())
            return &verbs[i];
    }

    // if the word cannot be found, avoid undefined behavior with a nullptr
    return nullptr;
}

bool WordSet::parseWissenFile(QString filePath) {
    qDebug() << "Parsing word Wissen data file: " << filePath;
    PartOS cpos;

    QFile wissenFile(filePath);
    if (!wissenFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;


    while (!wissenFile.atEnd()) {
        QString line = wissenFile.readLine();

        if (line == "[Verbs]\n")
            cpos = VERB;
        else if (line == "[Nouns]\n")
            cpos = NOUN;
        // in this case we have a word, not one of the lines as shown above
        else {
            if (cpos == NOUN) {
                QStringList lineParts = line.split(" ");
                Word* word = findWordObject(lineParts[0]);

                if (!word || word->partOfSpeech == NOUN)
                    continue; // the word was listed as a different part of speech in the wissen file and the word file

                word->defCorrects = lineParts[1].split("/")[0].toInt();
                word->defIncorrects = lineParts[1].split("/")[1].toInt();
            }
            else if (cpos == VERB) {
                QStringList lineParts = line.split(" ");
                Word* word = findWordObject(lineParts[0]);

                if (!word || word->partOfSpeech == VERB)
                    continue;

                int knowledge = lineParts[1].toInt();
                word->defknowledge = knowledge;
            }
        }
    }
}

WordSet::~WordSet() {
    
}
