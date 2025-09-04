#include "FileParser.h"

#include <QDebug>
#include <QFile>

QList<Noun*> nouns;
QList<Verb*> verbs;

Verb* parseVerb(QString verbDat) {
    QStringList sections = verbDat.split('\n')[0].split(' '); // split the word and chop off the newline

    Verb* verb = new Verb(sections[0].toLower(), sections[7].toLower(), sections[1].toLower(), sections[2].toLower(), sections[3].toLower(), sections[4].toLower(), sections[5].toLower(), sections[6].toLower());
    return verb;
}

Noun* parseNoun(QString nounDat) {
    QStringList sections = nounDat.split(" ");

    Gender wordGender;
    if (sections[1].toLower() == "der")
        wordGender = DER;
    else if (sections[1].toLower() == "die")
        wordGender = DIE;
    else if (sections[1].toLower() == "das")
        wordGender = DAS;

    Noun* noun = new Noun(sections[0].toLower(), wordGender, sections[2].toLower());
    return noun;
}

void parseFile(QString filePath) {
    QFile questionFile(filePath);
    PartsOfSpeech cpos = NOUN;


    if (!questionFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while(!questionFile.atEnd()) {
        QString line = questionFile.readLine();

        if (line == "[Verbs]\n")
            cpos = VERB;
        else if (line == "[Nouns]\n")
            cpos = NOUN;
        else {
            if (cpos == NOUN) {
                Noun* noun = parseNoun(line);
                nouns.append(noun);
                qDebug() << noun->word;
            } else if (cpos == VERB) {
                Verb* verb = parseVerb(line);
                verbs.append(verb);
                qDebug() << verb->word;
            }
        }
    }
}
