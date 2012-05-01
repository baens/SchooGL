#ifdef _WIN32
#include <windows.h>
#endif
#include <SelectionScene.h>
#include <string>
#include <GL/glut.h>
#include <QuizScene.h>
#include <StatManager.h>
#include <iostream>
#include "Transition.h"
using namespace std;

SelectionScene::SelectionScene()
{
  string* s = StatManager::getStats(UserManager::getID());
  //string s[3] = {"0","0","0"};
  subWindow = new SubjectWindow(s);
  diffWindow = new DifficultyWindow();
  profile = new ProfileWindow();
  needASwitch = false;
  displaySubject = true;
  displayProfile = false;
}

void SelectionScene::processInput(unsigned int key)
{
	if(displayProfile)
		profile->processInput(key);
}

void SelectionScene::processMouseDown(unsigned int button, unsigned int x, unsigned int y)
{
  if(button == GLUT_LEFT){
	  if(displayProfile){
		  profile->handleMouseDown(Point(x,y));
	  }
	  else{
		if(displaySubject)
			subWindow->handleMouseDown(Point(x,y));
		else
			diffWindow->handleMouseDown(Point(x,y));
	  }
  }
}

void SelectionScene::processMouseUp(unsigned int button, unsigned int x, unsigned int y)
{
  if(button == GLUT_LEFT){
	  if(displayProfile){
		  if(profile->handleMouseUp(Point(x,y))){
		    displayProfile = false;
		    displaySubject = true;
		  }
	  }
	  else{
		if(displaySubject){
		  int ret = subWindow->handleMouseUp(Point(x,y));
		  if(0 == ret){
		    displaySubject = false;
		    displayProfile = false;
		    diffWindow->setSubject(subWindow->getLastSelectedSubject());
		  }
		  else if(1 == ret){
		    displaySubject = false;
		    displayProfile = true;
		  }
		}
		else{
			int dret = diffWindow->handleMouseUp(Point(x,y));
			if(0 == dret)
				needASwitch = true;
			if(1 == dret)
				displaySubject = true;
		}
	  }
  }
}

void SelectionScene::draw()
{
	if(displayProfile){
		profile->draw();
	}
	else{
		if(displaySubject)
			subWindow->draw();
		else
			diffWindow->draw();
	}
}

Scene* SelectionScene::switchScene()
{
  //return new QuizScene(subWindow->getLastSelectedSubject(), diffWindow->getLastSelectedDifficulty());
  return new Transition(new QuizScene(subWindow->getLastSelectedSubject(), diffWindow->getLastSelectedDifficulty()), true);
}
