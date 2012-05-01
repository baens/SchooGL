#ifdef _WIN32
#include <windows.h>
#include <gl/glut.h>
#endif
#include "Rectangle.h"

Rectangle::Rectangle(){
	this->height = 0.0;
	this->width = 0.0;
	this->text = "";
}
Rectangle::Rectangle(float h, float w, Point p, Color c, string s){
	this->height = h;
	this->width = w;
	this->point = p;
	this->color = c;
	this->text = s;
}
Rectangle::Rectangle(Rectangle &rhs){
	this->height = rhs.height;
	this->width = rhs.width;
	this->point = rhs.point;
	this->color = rhs.color;
	this->text = rhs.text;
}
void Rectangle::draw(){
	colorRecDraw();
}
void Rectangle::colorRecDraw(){
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.1);				// Move Right 1.5 Units And Into The Screen 6.0
		glColor3f(color.getRed(), color.getGreen(), color.getBlue());							// Set The Color To Blue One Time Only
		glBegin(GL_POLYGON);									// Draw A Poly
			glVertex3f(point.getX() - width/2, point.getY() + height/2, 0);					// Top Left
			glVertex3f(point.getX() + width/2, point.getY() + height/2, 0);					// Top Right
			glVertex3f(point.getX() + width/2, point.getY() - height/2, 0);					// Bottom Left
			glVertex3f(point.getX() - width/2, point.getY() - height/2, 0);					// Bottom Right
		glEnd(); // Done Drawing The Poly
	glPopMatrix();
}
void Rectangle::textRecDraw(){
	colorRecDraw();
	glPushMatrix();
	glPushAttrib(GL_LINE_BIT);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(1.5f);
		if(text.length()%2 != 0)
			glTranslatef(point.getX() - (text.length() * .36), point.getY() - .35, 0);
		else
			glTranslatef(point.getX() - (text.length()/2)*.725, point.getY() - .35, 0);
		glScalef(0.007,0.007,0.01);
		for(unsigned int c = 0;c < text.length(); c++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[c]);
	glPopAttrib();
	glPopMatrix();
}
BBox Rectangle::getBBox(){
	Point minPoint(point.getX() - width/2, point.getY() - height/2);
	Point maxPoint(point.getX() + width/2, point.getY() + height/2);
	return BBox(minPoint,maxPoint);
}