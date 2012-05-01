#ifdef _WIN32
#include <windows.h>
#endif
#include <time.h>
#include <iostream>
#include "Question.h"
#include <GL/glut.h>
#include "Point.h"
#include "Color.h"
#include "Rectangle1.h"
#include <Util.h>

Question::Question(){
	Point p(0.0, 0.0);
	Color c(1.0, 0.0, 0.0, 0.0);
	this->point = p;
	this->color = c;
	srand(time(NULL));
	this->random = rand() % 4;
	this->question = question;
	for(int a = 0; a < 4; a++)
	  this->answers[a] = "1";
	this->correctAnswer = 1;
	this->answerRec[0] = new Rectangle1(1.25,.4, Point(point.getX() - 2.5, point.getY() - 2.0), color, "");
	this->answerRec[1] = new Rectangle1(1.25,.4, Point(point.getX() - .85, point.getY() - 2.0), color, "");
	this->answerRec[2] = new Rectangle1(1.25,.4, Point(point.getX() + .85, point.getY() - 2.0), color, "");
	this->answerRec[3] = new Rectangle1(1.25,.4, Point(point.getX() + 2.5, point.getY() - 2.0), color, "");
	this->correct =  false;
	this->answered = false;
}
Question::Question(Point p, Color c, string question, string answer[4], int correct){
	this->point = p;
	this->color = c;
	srand(time(NULL));
	this->random = rand() % 4;
	this->question = question;
	for(int a = 0; a < 4; a++)
	  this->answers[a] = answer[a];
	this->correctAnswer = correct;
	this->answerRec[0] = new Rectangle1(1.25,.4, Point(point.getX() - 2.5, point.getY() - 1.5), color, "");
	this->answerRec[1] = new Rectangle1(1.25,.4, Point(point.getX() - .85, point.getY() - 1.5), color, "");
	this->answerRec[2] = new Rectangle1(1.25,.4, Point(point.getX() + .85, point.getY() - 1.5), color, "");
	this->answerRec[3] = new Rectangle1(1.25,.4, Point(point.getX() + 2.5, point.getY() - 1.5), color, "");
	this->correct =  false;
	this->answered = false;
}
Question::Question(Point p, Color c, string question, string answer[4], int correct, double ansOffset){
	this->point = p;
	this->color = c;
	srand(time(NULL));
	this->random = rand() % 4;
	this->question = question;
	for(int a = 0; a < 4; a++)
	  this->answers[a] = answer[a];
	this->correctAnswer = correct;
	this->answerRec[0] = new Rectangle1(1.25,.4, Point(point.getX() - 2.5-ansOffset, point.getY() - 1.5), color, "");
	this->answerRec[1] = new Rectangle1(1.25,.4, Point(point.getX() - .85-ansOffset/2, point.getY() - 1.5), color, "");
	this->answerRec[2] = new Rectangle1(1.25,.4, Point(point.getX() + .85+ansOffset/3, point.getY() - 1.5), color, "");
	this->answerRec[3] = new Rectangle1(1.25,.4, Point(point.getX() + 2.5+(ansOffset+0.3), point.getY() - 1.5), color, "");
	this->correct =  false;
	this->answered = false;
}
Question::Question(string question, string ans){
  int correctPlace = rand()%4;
  string answerStr[4];
  int possibleAnswers[] = {0,0,0};
  int delta = to_int(ans) *.2;
  if(delta < 10)
    delta = 4;
  int answer = 0;
  //find answers  
  for(int a = 0; a < 3; a++){	
    bool foundAnswer = false;
    while(!foundAnswer){
      answer = rand()%delta;
      for(int b = 0; b < 3; b++){
	if(answer == possibleAnswers[b])
	  break;
	if(b == 2)
	  foundAnswer = true;
      }
    }
    possibleAnswers[a] = answer;
  }
  int pos = 0;
  for(int a = 0; a < 4; a++)
    if(correctPlace == a)
      answerStr[a] = ans;
    else{
      int place = rand()%2?possibleAnswers[pos] + to_int(ans):
	abs(possibleAnswers[pos]-to_int(ans));
      answerStr[a] = to_string(place);
      pos++;
    }
  Point p(0,8);
  Color c(0.0,0.0,1.0,0.0);
  this->point = p;
  this->color = c;
  srand(time(NULL));
  this->random = rand() % 4;
  this->question = question;
  for(int a = 0; a < 4; a++)
    this->answers[a] = answerStr[a];
  this->correctAnswer = correctPlace;
  this->answerRec[0] = new Rectangle1(1.25,.4, Point(point.getX() - 2.5, point.getY() - 1.5), color, "");
  this->answerRec[1] = new Rectangle1(1.25,.4, Point(point.getX() - .85, point.getY() - 1.5), color, "");
  this->answerRec[2] = new Rectangle1(1.25,.4, Point(point.getX() + .85, point.getY() - 1.5), color, "");
  this->answerRec[3] = new Rectangle1(1.25,.4, Point(point.getX() + 2.5, point.getY() - 1.5), color, "");
  this->correct =  false;
  this->answered = false;
}
Question::Question(Question &rhs){
	this->point = rhs.point;
	this->color = rhs.color;
	this->random = rhs.random;
}
void Question::drawQuestion(){
	
  Rectangle1 questionRec(1.25, 0.0, point, color, question);
	
	glPushMatrix();
	questionRec.draw();
	glPopMatrix();
	int startPlace = random;
	for(int a = 0; a < 4; a++){
	  drawAnswer(*answerRec[a], answers[a]);
	}
}
void Question::drawAnswer(Rectangle1 r, string answer){

	r.setString(answer);

	glPushMatrix();
	r.draw();
	glPopMatrix();
}

bool Question::handleLeftMouseDown(Point p)
{
  if(answered)
    return false;
  Point mousePoint = screen_to_obj(p.getX(),p.getY());
  for(int a = 0; a < 4; a++){
    BBox currentBBox = answerRec[a]->getBBox();
    if(currentBBox.containPoint(mousePoint)){
      answerRec[a]->setColor(Color(1.0,0.0,0.0,0.0));
      if(a == correctAnswer)
		correct = true;
      return true;
    }
  }
  return false;
}

bool Question::handleLeftMouseUp(Point p)
{
  if(answered)
    return false;
  Point mousePoint = screen_to_obj(p.getX(),p.getY());
  for(int a = 0; a < 4; a++){
    BBox currentBBox = answerRec[a]->getBBox();
    if(currentBBox.containPoint(mousePoint)){
	  answerRec[a]->setColor(this->color);
	  answered = true;
	  if(a == correctAnswer)
		correct = true;
      return true;
    }
  }
  return false;
}
