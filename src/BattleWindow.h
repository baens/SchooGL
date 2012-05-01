#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H
#include "Question.h"
#include "Rectangle1.h"
#include "Point.h"
#include <GL/gl.h>

class BattleWindow {
public:
	BattleWindow();
	BattleWindow(Question* q, Rectangle1 m, Rectangle1 c, int p);
	void draw();
	void processInput(unsigned int key);
	bool processMouseDown(unsigned int x, unsigned int y);
	bool processMouseUp(unsigned int x, unsigned int y);
	bool isAnswerCorrect(){return question->isAnswerCorrect();}
	void setCorrectColor(Color c){question->setCorrectColor(c);}
	Rectangle1* back;
private:
	Question* question;
	Rectangle1 monster;
	Rectangle1 character;
	int place;
	Point* monsterpoint;
	Point* charpoint;
	Rectangle1* pexit;
	bool handleMouseDown(Point p);
	bool handleMouseUp(Point p);
	void drawLine();
};
#endif
