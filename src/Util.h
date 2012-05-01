#include <iostream>
#include <Point.h>
#include <Subject.h>
#include <Difficulty.h>

using namespace std;

//converts an types into a string
string to_string(int val);
string to_string(double val);
string to_string(Subject s);
string to_string(Difficulty d);
//converts string to int
int    to_int(string s);
double to_double(string s);
//converts a screen x,y to an object x,y,z
Point screen_to_obj(double x, double y);
