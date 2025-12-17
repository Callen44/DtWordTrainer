#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include "../../DataZone/Word.h"
#include "../../DataZone/Wordset.h"

/*
* This has got to be the weirdest class in the whole project, it serves as a juction piece between the Algorithm class and the QuestionOverseer class.
* The purpouse is for it to be some kind of medium that handles the processing of a question, serving as an abstraction for the Question classes themselves,
* and allows for easily passing questions between the Algorithm and the rest of QuestionZone
*/

enum QVariety {
    MCFD, // a four answer multiple choice question
    TPDTW, // a question where there is a prompt and the user is meant to type an answer
    CHGND, // choose the gender of the noun, multiple choice
};

class Question
{
public:

    /*
    Functions
    */

    Question(QVariety questionType, Word* associatedWord, int questionLevel)
        : questionType(questionType), associatedWord(associatedWord), questionLevel(questionLevel) {}
        
    virtual ~Question() = default; // Virtual destructor to ensure proper cleanup of derived classes

    // functions for reporting data
    virtual int timesCorrect();
    virtual int timesIncorrect();

    // stores if the question was answered correctly last time.
    bool correctLast = true;

    // funcitons for handling answers are in derrived classes, since each one is slightly different

    /*
    Variables
    */

    QVariety questionType; // stores what type of question this TODO make this properly immutable
    Word* associatedWord; // a pointer back to the word this is a question for, allows for the question to log it's correcness itself, the UI is not responsible for managing such data
    WordSet* words;
    int questionLevel;  /* questionLevel is how hard a question is relative to others that quiz the same thing.
                          In other words, of all the questions that ask the user about the definition of a word, which are the easiest,
                          a multiple choice question is easier than typing the definition, so we'll consider the multiple choid question to have a lower level.
                        */
};

#endif // QUESTION_H
