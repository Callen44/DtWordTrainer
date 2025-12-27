#include "Verb.h"

Verb::Verb(Word* word)
    : Word(VERB, "", "") { // start with dummy values, since we have to call the base constructor even though this data doesn't matter
    // if this is called with a Verb pointer, we will initialize this Verb to become the word it was passed.
    // check if the passed word is already a Verb, if so we set this class to be equal to it.
    // Otherwise we leave it as a base word and build a new Verb off of it
    if (word->partOfSpeech == VERB) {
        Verb* heapVerb = reinterpret_cast<Verb*>(word);
        *this = *heapVerb;
    } else {
        *this = Verb(word->translation, word->word);
    }
}
