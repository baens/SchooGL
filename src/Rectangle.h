#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include <Point.h>
#include <Color.h>
#include <BBox.h>

using namespace std;

class Rectangle{
 public:
	/**
	* @author SchooGL
	* 
	* creates a default rectangle.
	*/
	Rectangle();
	/**
	* @author SchooGL
	* 
	* creates a rectangle.
	* 
	* @param h the height of a rectangle.
	* @param w the width of a rectangle.
	* @param d the distance of a rectangle.
	* @param p the Point location of a rectangle.
	* @param c the color of a rectangle.
	*/
	Rectangle(float h, float w, Point p, Color c, string s);
	/**
	* @author SchooGL
	* 
	* creates a rectangle copy of rhs.
	* 
	* @param rhs a rectangle to copy.
	*/
	Rectangle(Rectangle& rhs);
	/**
	* @author SchooGL
	* 
	* sets the color of the rectangle.
	* 
	* @param c the color of the rectangle.
	*/
	//void setColor(Color c);
	/*
	* @author SchooGL
	* 
	* draws the rectangle.
	*/
	void draw();
	Point getPoint(){return point;}
	BBox getBBox();
private:
	float height;
	float width;
	string text;
	Point point;
	Color color;
	void colorRecDraw();
	void textRecDraw();
};
#endif