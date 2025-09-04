#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "Noun.h"
#include "Verb.h"

Noun* parseNoun(QString nounDat);
Verb* parseVerb(QString verbDat);

void parseFile(QString filePath);

#endif // FILEPARSER_H
