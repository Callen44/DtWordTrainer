# TODO

- Add error handling system for if the input file doesn't follow syntax, currently it causes undefined behavior.
- redo all comments program-wide
- In the program, questions are chosen in a weird way. First it picks a random question, but if there are multiple question types that ask the same question different ways, then they will be filed as entirely seperate questions. Then when the program reaches the point where it is picking a question, if the question it picks is of such a variety, then it will adjust to ask the easier or harder one, this is a fairly common occurance.