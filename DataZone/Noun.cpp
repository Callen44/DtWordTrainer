#include "Noun.h"

Noun::Noun(Word* word)
    : Word(NOUN, "", "") { // start with dummy values, since we have to call the base constructor even though this data doesn't matter
    // if this is called with a Noun pointer, we will initialize this noun to become the word it was passed.
    // check if the passed word is already a noun, if so we set this class to be equal to it.
    // Otherwise we leave it as a base word and build a new noun off of it. The new noun will be a copy of the original, no pointers used
    if (word->partOfSpeech == NOUN) {
        Noun* heapNoun = reinterpret_cast<Noun*>(word);
        *this = *heapNoun;
    } else {
        *this = Noun(word->word, DER, word->translation); // fill in the missing blank with a der gender, the user can fix this later.
    }
}

QString Noun::genderAsString() {
    // basic function to get the current gender in a string form
    if (gender == DIE)
        return "Die";
    else if (gender == DER)
        return "Der";
    else if (gender == DAS)
        return "Das";

    // fallback
    return "Der";
}
