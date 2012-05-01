#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/glut.h>

#include <iostream>

#include <QuestionManager.h>
#include <QuizScene.h>
#include <StatScene.h>
#include <Util.h>
#include <StatManager.h>
#include "Transition.h"
#include "Animation.h"

QuizScene::QuizScene()
{
  needASwitch = false;
  //Rectangle1 rec1(5.0, 2.25, Point(10,5),Color(1.0,0.0,0.0),"");
  //Rectangle1 rec1(5.0, 2.25, Point(10,5),"data/character/attack1");
  Rectangle1 rec1(5.0, 5.0, Point(10,5),"data/monster/enemy");
  Rectangle1 rec2(5.0, 5.0, Point(10.0, 5.0), "data/character/defensivestance",UserManager::getProfile().getColor());
  //Rectangle1 rec2(5.0, 2.25, Point(10,5),Color(0.0,1.0,0.0),"");
  whichAni = 0;
  oldPlace = 0;
  place = 0;
  window = new BattleWindow(QuestionManager::getQuestion(),rec1,rec2,0);
  tran = new Transition(new BattleWindow(QuestionManager::getQuestion(subject,difficulty),rec1,rec2,0), new Animation("enemy", whichAni, oldPlace, place), false);
  displayCorrect = false;
  this->displayWindow = false;
  correctRec = NULL;
  subject = Addition;
  difficulty = Easy;
  totalAnswered = 0;
  answeredCorrect = 0;
}

QuizScene::QuizScene(Subject s, Difficulty d):subject(s),difficulty(d){
  needASwitch = false;
  switch(d){
	case Easy:
		this->mon = "enemy";
		break;
	case Medium:
		this->mon = "enemy1";
		break;
	case Hard:
		this->mon = "enemy2";
		break;
	default:
		this->mon = "enemy";
		break;
  }
  //Rectangle1 rec1(5.0, 2.25, Point(10,5),"data/character/attack3");
  Rectangle1 rec1(5.0, 5.0, Point(10,5),"data/monster/" + mon);
  Rectangle1 rec2(5.0, 5.0, Point(10.0, 5.0), "data/character/defensivestance",UserManager::getProfile().getColor());
  //Rectangle1 rec2(5.0, 2.25, Point(10,5),Color(0.0,1.0,0.0),"");
  whichAni = 0;
  oldPlace = 0;
  place = 0;
  window = new BattleWindow(QuestionManager::getQuestion(subject,difficulty),rec1,rec2,0);
  tran = new Transition(new BattleWindow(QuestionManager::getQuestion(subject,difficulty),rec1,rec2,0), new Animation(mon, whichAni, oldPlace, place), false);
  displayCorrect = false;
  this->displayWindow = false;
  correctRec = NULL;
  totalAnswered = 0;
  answeredCorrect = 0;
}
void QuizScene::draw()
{
  if(displayCorrect){
    string displayString;
    if(window->isAnswerCorrect())
      displayString = "Correct!";
    else
      displayString = "Incorrect!";
    if(correctRec)
      delete correctRec;
    correctRec = new Rectangle1(20,20,Point(0,5),Color(1.0,1.0,0.0),displayString);
  }
  if(!displayWindow)
	tran->draw();
  else
	window->draw();
  if(displayCorrect && correctRec != NULL)
    correctRec->draw();
  displayWindow = tran->isDone();
}

void QuizScene::processInput(unsigned int key)
{
  if(displayCorrect)
    return;
  window->processInput(key);
}

void QuizScene::processMouseDown(unsigned int button, unsigned int x, unsigned int y)
{
  if(button == GLUT_LEFT)
    window->processMouseDown(x,y);
}

void QuizScene::processMouseUp(unsigned int button, unsigned int x, unsigned int y)
{
  if(displayCorrect){
    displayCorrect = false;
    delete window;
    //Rectangle1 rec1(5.0, 2.25, Point(10,5),Color(1.0,0.0,0.0),"");
	//Rectangle1 rec1(5.0, 2.25, Point(10,5),"data/character/attack2");
	Rectangle1 rec1(5.0, 5.0, Point(10,5),"data/monster/" + mon);
	Rectangle1 rec2(5.0, 5.0, Point(10.0, 5.0), "data/character/defensivestance",UserManager::getProfile().getColor());
    //Rectangle1 rec2(5.0, 2.25, Point(10,5),Color(0.0,1.0,0.0),"");
    window = new BattleWindow(QuestionManager::getQuestion(subject,difficulty),rec1,rec2,place);
	tran = new Transition(new BattleWindow(QuestionManager::getQuestion(subject,difficulty),rec1,rec2,place), new Animation(mon, whichAni, oldPlace, place), false);
	displayWindow = false;
    if(totalAnswered >= 10)
      needASwitch = true;
    return;
  }
  if(button == GLUT_LEFT)
    if(window->processMouseUp(x,y)){
      if(window->isAnswerCorrect()){
		oldPlace = place;
		place++;
		whichAni = 1;
		answeredCorrect++;
      }else{
		oldPlace = place;
		place--;
		whichAni = 2;
		window->setCorrectColor(Color(0.0,1.0,1.0));
      }
      displayCorrect = true;
      totalAnswered++;
    }
}
Scene* QuizScene::switchScene()
{
  StatManager::updateStats(subject,difficulty,totalAnswered-answeredCorrect,totalAnswered);
  //return new StatScene(subject,difficulty,answeredCorrect,totalAnswered-answeredCorrect);
  return new Transition(new Transition(new StatScene(subject,difficulty,answeredCorrect,totalAnswered-answeredCorrect), true), new Animation(mon, 3, oldPlace, place), false);
}
