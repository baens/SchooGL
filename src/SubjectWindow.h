#ifndef SUBJECTWINDOW_H
#define SUBJECTWINDOW_H
#include <string>
#include <Point.h>
#include <Color.h>
#include <BBox.h>
#include <Subject.h>
#include "Rectangle1.h"

using namespace std;

class SubjectWindow{
	public:
		SubjectWindow(string achievement[3]);
		void draw();
		bool handleMouseDown(Point p);
		int handleMouseUp(Point p);
		Subject getLastSelectedSubject(){return lastSelectedSubject;}
	private:
		Rectangle1* title[2];
		Rectangle1* subjects[3];
		Rectangle1* achievements[3];
		Rectangle1* pexit;
		Rectangle1* edit;
		Subject     subjectCats[3];
		Subject     lastSelectedSubject;
};
#endif
