#ifdef _WIN32
#include <windows.h>
#endif
#include "BattleWindow.h"
#include <QuestionManager.h>
#include <GL/glut.h>
#include "Rectangle1.h"
#include "Question.h"
#include <Util.h>
#include <BBox.h>
#include "UserManager.h"

BattleWindow::BattleWindow(){
	this->question = QuestionManager::getQuestion();
	//character.setColor(UserManager::getProfile().getColor());
}
BattleWindow::BattleWindow(Question* q, Rectangle1 m, Rectangle1 c, int p){
	this->back = new Rectangle1(20.0, 20.0, Point(0.0, 0.0), "data/background");
	this->question = q;
	this->monster = m;
	this->character = c;
	this->place = p;
	this->monsterpoint = new Point(2.5 + place, -6);
	this->charpoint = new Point(-1.25 + place, -5);
	this->pexit = new Rectangle1(0.0, 0.0, Point(7.5, -9), Color(0.5, 0.0, 1.0), "Exit");
	//character.setColor(UserManager::getProfile().getColor());
	monster.setPoint(monsterpoint);
	character.setPoint(charpoint);
}
void BattleWindow::draw(){
	back->draw();
	drawLine();
	question->drawQuestion();
	monster.draw();
	character.draw();
	pexit->draw();
}

void BattleWindow::processInput(unsigned int key)
{
}

bool BattleWindow::processMouseDown(unsigned int x, unsigned int y)
{
	return (question->handleLeftMouseDown(Point(x,y))) || handleMouseDown(Point(x,y));
}

bool BattleWindow::processMouseUp(unsigned int x, unsigned int y)
{
  return (question->handleLeftMouseUp(Point(x,y))) || handleMouseUp(Point(x,y));
}
bool BattleWindow::handleMouseDown(Point p){
	Point screen_point = screen_to_obj(p.getX(),p.getY());
	BBox currentBBox = pexit->getBBox();
	if(currentBBox.containPoint(screen_point)){
		pexit->setColor(Color(0.0,1.0, 0.0));
		return true;
	}
	return false;
}
bool BattleWindow::handleMouseUp(Point p){
	Point screen_point = screen_to_obj(p.getX(),p.getY());
	BBox currentBBox = pexit->getBBox();
	if(currentBBox.containPoint(screen_point)){
		pexit->setColor(Color(0.5, 0.0, 1.0));
		exit(0);
	}
	return false;
}
void BattleWindow::drawLine(){
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(1.0f);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-9.5, -7.5, 0);
	    glVertex3f(-9.5, -8, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(-9.5, -8, 0);
		glVertex3f(-0.05, -8, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(-0.05, -8, 0);
		glVertex3f(-0.05, -7.5, 0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.05, -7.5, 0);
		glVertex3f(0.05, -8, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.05, -8, 0);
		glVertex3f(9.5, -8, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(9.5, -8, 0);
		glVertex3f(9.5, -7.5, 0);
	glEnd();
	glPopMatrix();
}
