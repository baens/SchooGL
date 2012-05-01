#ifndef QUESTIONMANAGER_H
#define QUESTIONMANAGER_H
#include <Question.h>
#include <Subject.h>
#include <Difficulty.h>

class QuestionManager{
public:
	static Question* getQuestion();
	static Question* getQuestion(Subject s, Difficulty d);
};

#endif
