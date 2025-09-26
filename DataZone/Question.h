#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include "Word.h"
#include "Wordset.h"

enum QVariety {
    MCHOICEFOURDEF, // a four answer multiple choice question
    TYPEWORD, // a question where there is a prompt and the user is meant to type an answer
};

/*
 * To deal with the struggles of having a million classes that are varieties of question (mostly the header file complications), we do things a little different when it comes to diferent kinds of
 * questions. The solution we use is that the question class will be assigned a QVariety (Question, not Qt) and different member funcitons will be associated with that variety. It is a wierder way
 * of doing things, but it keeps the enormous datazone from becoming innavicable.
*/

class Question
{
public:
    Question(QVariety questionType, Word* associatedWord);
    const QVariety questionType; // stores what type of question this
    const Word* associatedWord; // a pointer back to the word this is a question for, allows for the question to log it's correcness itself, the UI is not responsible for managing such data
    bool processMChoiceAnswer(int answer); // processes multiple choice answer to question, returns if it was correct
    bool processTypeWordAnswer(QString answer); // processes typeword answer to question, returns if it was correct

private:

};

#endif // QUESTION_H
