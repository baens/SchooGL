#ifndef STATWINDOW_H
#define STATWINDOW_H
#include <string>
#include "Rectangle1.h"

using namespace std;

class StatWindow{
	public:
		 /*
		 * creates a stat window with string, string, int, int
		 * 
		 * @param s string of subject
		 * @param d string of difficulty
		 * @param c double of number correct
		 * @param m double of number missed
		 */
		StatWindow(string s, string d, double c, double m);
		 /*
		 * creates a stat window that is a copy of stat window rhs
		 */
		StatWindow(StatWindow& rhs);
		 /*
		 * draws the statwindow
		 */
		void draw();
		bool handleMouseUp(Point p);
		bool handleMouseDown(Point p);
	private:
		Rectangle1* subRec;
		Rectangle1* difRec;
		Rectangle1* correctRec;
		Rectangle1* missedRec;
		Rectangle1* percentRec;
		Rectangle1* numberRec[3];
		Rectangle1* pexit;
		Rectangle1* save;
};
#endif //STATWINDOW_H
