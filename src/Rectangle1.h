#ifndef RECTANGLE1_H
#define RECTANGLE1_H
#include <string>
#include <Point.h>
#include <Color.h>
#include <BBox.h>
#include <GL/gl.h>
using namespace std;
struct Image {
	unsigned long sizeX;
	unsigned long sizeY;
	unsigned char *data;
};
typedef struct Image Image;
class Rectangle1{
 public:
	/**
	* @author SchooGL
	* 
	* creates a default rectangle.
	*/
	Rectangle1();
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
	Rectangle1(float h, float w, Point p, Color c, string s);
	Rectangle1(float h, float w, Point p, string s);
	Rectangle1(float h, float w, Point p, string s,Color c);
	/**
	* @author SchooGL
	* 
	* creates a rectangle copy of rhs.
	* 
	* @param rhs a rectangle to copy.
	*/
	Rectangle1(const Rectangle1& rhs);
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
	void setString(string s);
	void setColor(Color c);
	void setPoint(Point* p);
	Color getColor();
private:
	float height;
	float width;
	string text;
	Point point;
	Color color;
	void colorRecDraw();
	void textRecDraw();
	void textureRecDraw();
	int ImageLoad(const char* filename, Image *image, bool colro);
	void LoadGLTextures(string filename, bool color);
	GLuint texture[4];
	Image* texture_image[4];
};
#endif
