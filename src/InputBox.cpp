#include "InputBox.h"
#include <GL/glut.h>
#include "Point.h"
#include <BBox.h>

InputBox::InputBox(): is_password(false){
	this->width = 0.0;
	this->height = 0.0;
	focus = false;
	blink_line = 0;
}
InputBox::InputBox(double w, double h, Point p): is_password(false){
	this->width = w;
	this->height = h;
	this->point = p;
	focus = false;
	blink_line = 0;
}
InputBox::InputBox(InputBox &rhs){
	this->width = rhs.width;
	this->height = rhs.height;
	this->point = rhs.point;
}
void InputBox::addChar(char *c){
	input_string+= c;
}
void InputBox::deleteChar(){
	if(input_string.length() > 0)
		input_string.erase(input_string.length()-1);
}
string InputBox::getString(){
	return input_string;
}
bool InputBox::getFocus(){
	return focus;
}
void InputBox::setFocus(bool b){
	focus = b;
}
void InputBox::setTitle(char* s){
	title = s;
}
void InputBox::drawBox(){
	//glLineWidth(5.0f);
	glPushMatrix();
	//glTranslatef(0.0f,0.0f,-6.0f);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(1.0f);
	glBegin(GL_LINE_LOOP);
	    glVertex3f(point.getX() - width/2, point.getY() + height/2, 0.0); // top line
		glVertex3f(point.getX() + width/2, point.getY() + height/2, 0.0); // right line
		glVertex3f(point.getX() + width/2, point.getY() - height/2, 0.0); // bottom line
		glVertex3f(point.getX() - width/2, point.getY() - height/2, 0.0); // left line
    glEnd();
	glPopMatrix();
  if(focus){
	drawLine();
  }
  drawTitle();
  drawInputString();
  glPopMatrix();
}
void InputBox::drawLine(){
	//glLineWidth(5.0f);
	//on for 20 draws, off for 20 draws
	glPushMatrix();
	if(blink_line % 40 < 20){
		glColor3f(1.0, 1.0, 1.0);
		glLineWidth(1.0f);
		glBegin(GL_LINE_LOOP);
			if(input_string.length() == 0){
				glVertex3f(point.getX() - width/2 + .05, point.getY() + height/2, 0.0); // top line
				glVertex3f(point.getX() - width/2 + .05, point.getY() - height/2, 0.0); // right line
			}
			else{
				glVertex3f(point.getX() - width/2 + .32*input_string.length(), point.getY() + height/2, 0.0); // top line
				glVertex3f(point.getX() - width/2 + .32*input_string.length(), point.getY() - height/2, 0.0); // right line
			}
		glEnd();
	}
	blink_line++;
	glPopMatrix();
}
void InputBox::drawTitle(){
	glPushMatrix();
	char* c;
	glPushAttrib(GL_LINE_BIT);
		glColor3f(1.0, 1.0, 1.0);
		glLineWidth(1.5f);
		glTranslatef(point.getX() - width/2, point.getY() + height, 0);
		glScalef(0.003,0.003,0.01);
		for(c = title; *c != '\0'; c++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *c);
	glPopAttrib();
	glPopMatrix();
}

void InputBox::drawInputString(){
	glPushMatrix();
	glPushAttrib(GL_LINE_BIT);
		glColor3f(1.0, 1.0, 1.0);
		glLineWidth(1.5f);
		glTranslatef(point.getX() - width/2 + .025, point.getY() - .09, 0);
		glScalef(0.003,0.003,0.001);
		for(unsigned int a = 0; a < input_string.length(); a++){
			if(is_password)
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, '*');
			else
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, input_string[a]);
		}
	glPopAttrib();
	glPopMatrix();
}
void InputBox::setInput(string s){
	input_string = s;
}