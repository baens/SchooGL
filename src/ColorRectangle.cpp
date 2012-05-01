#include <GL/glut.h>
#include "ColorRectangle.h"

ColorRectangle::ColorRectangle(){
	this->height = 0.0;
	this->width = 0.0;
	this->distance = 0.0;
}
ColorRectangle::ColorRectangle(float h, float w, float d, Point p, Color c){
	this->height = h;
	this->width = w;
	this->distance = d;
	this->point = p;
	this->color = c;
}
ColorRectangle::ColorRectangle(ColorRectangle &rhs){
	this->height = rhs.height;
	this->width = rhs.width;
	this->distance = rhs.distance;
	this->point = rhs.point;
	this->color = rhs.color;
}
void ColorRectangle::setColor(Color c){
	//TODO: setup color =operator
	this->color = c;
}
void ColorRectangle::draw(){
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

BBox ColorRectangle::getBBox()
{
  Point minPoint(point.getX() - width/2, point.getY() - height/2);
  Point maxPoint(point.getX() + width/2, point.getY() + height/2);
  return BBox(minPoint,maxPoint);
}