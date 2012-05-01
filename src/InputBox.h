#ifndef INPUTBOX_H
#define INPUTBOX_H 1
#include <string>
#include "Point.h"
#include <BBox.h>

using namespace std;

class InputBox{
 public:
	 /*
	 * a default input box
	 */
	InputBox();
	 /*
	 * a inputbox of width w and height h around point p
	 * 
	 * @param w width of a input box
	 * @param h height of a input box
	 * @param p point around which the box is drawn
	 */
	InputBox(double w, double h, Point p);
	 /*
	 * creates a copy of an input box
	 * 
	 * @param rhs a current input box that is to be copied.
	 */
	InputBox(InputBox& rhs);
	 /*
	 * adds a char to input_string
	 * 
	 * @param c a pointer to a character
	 */
	void addChar(char* c);
	 /*
	 * deletes a char from input_string
	 * 
	 * 
	 */
	void deleteChar();
	 /*
	 * gets the input_string and returns it
	 * 
	 * @return a char pointer to input_string
	 */
	string getString();
	 /*
	 * gets the focus
	 * 
	 * @return bool that represents ture or false
	 */
	bool getFocus();
	 /*
	 * sets the focus
	 * 
	 * @param b a bool that represents ture or false
	 */
	void setFocus(bool b);
	 /*
	 * sets the title of the input box
	 * 
	 * @param s a pointer to a char
	 */
	void setTitle(char* s);
	 /*
	 * draws a box with lines
	 */
	void drawBox();
	 /*
	 * draws a line
	 */
	void drawLine();
	 /*
	 * draws the title of the box
	 */
	void drawTitle();
	/*
	 * draws the input string in the box
	 */
	void drawInputString();
	/**
	 * sets this input box to be a password input box
	 */
	void setTypeToPassword(){is_password = true;}
	void setInput(string s);
 private:
	 double width;
	 double height;
	 char* title;
	 string input_string;
	 bool focus;
	 unsigned int blink_line;	 
	 Point point;
	 bool is_password;
};
#endif //INPUTBOX_H
