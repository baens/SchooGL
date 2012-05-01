#ifndef DIFFICULTYWINDOW_H
#define DIFFICULTYWINDOW_H
#include <string>
#include <Point.h>
#include <Color.h>
#include <BBox.h>
#include <Difficulty.h>
#include <Subject.h>
#include "Rectangle1.h"

using namespace std;

class DifficultyWindow{
	public:
		DifficultyWindow();
		void draw();
		bool handleMouseDown(Point p);
		int handleMouseUp(Point p);
		Difficulty getLastSelectedDifficulty(){return lastSelectedDifficulty;}
		void setSubject(Subject s);
	private:
		Rectangle1* difficulties[3];
		Rectangle1* monsters[3];
		Rectangle1* pexit;
		Rectangle1* back;
		Difficulty  difficultiesCat[3];
		Difficulty  lastSelectedDifficulty;
};
#endif
