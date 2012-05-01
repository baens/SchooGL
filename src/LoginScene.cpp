#ifdef _WIN32
#include <windows.h>
#endif
#include <LoginScene.h>
#include <LoginManager.h>
#include <QuizScene.h>
#include <Point.h>
#include <SelectionScene.h>
#include <GL/glut.h>
#include <Util.h>
#include <BBox.h>
#include "Transition.h"

LoginScene::LoginScene(){
	username = new InputBox(10,1,Point(-0.3,1.7));
	password = new InputBox(10,1,Point(-0.3,-.3));
	username->setTitle("User Name");
	password->setTitle("Password");
	focus_set = 1;
	username->setFocus(true);
	password->setFocus(false);
	password->setTypeToPassword();
	needASwitch=false;
	drawS=false;
	drawF=false;
	pexit = new Rectangle1(0.0,0.0,Point(7.5, -9), Color(0.5,0.0,1.0), "Exit");
	ok = new Rectangle1(0.0,0.0,Point(-4.0, -2.0), Color(0.5,0.0,1.0), "Ok");
	cancel = new Rectangle1(0.0,0.0,Point(2.0, -2.0), Color(0.5,0.0,1.0), "Cancel");
	user = new Rectangle1(1.0, 10.0, Point(-0.3,1.7), Color(0.0, 0.0, 0.0), "");
	pass = new Rectangle1(1.0, 10.0, Point(-0.3,-0.3), Color(0.0, 0.0, 0.0), "");
}

bool LoginScene::needSwitch(){
	return needASwitch;
}

void LoginScene::draw(){
	user->draw();
	pass->draw();
	username->drawBox();
	password->drawBox();
	pexit->draw();
	ok->draw();
	cancel->draw();
	if(drawS)
		drawSucess();
	if(drawF)
		drawFailure();
}

void LoginScene::processInput(unsigned int key){
	drawS = drawF = false;
	if(key == 9){
		switch(focus_set++%2){
		case 0:
			username->setFocus(true);
			password->setFocus(false);
			break;
		case 1:
			username->setFocus(false);
			password->setFocus(true);
			break;
		}
	}
	if(key == 8){
		switch(focus_set%2){
		case 0:
			password->deleteChar();
			break;
		case 1:
			username->deleteChar();
			break;
		}
	}
	if(key == 13){
		if(username->getString().length() > 0 && password->getString().length()){
			if(LoginManager::tryLogin(username->getString(),password->getString())){
				needASwitch = true;
			}else{
				drawF = true;
			}
		}
	}
	if(isalpha(key) || isalnum(key)){
		switch(focus_set%2){
		case 0:
			password->addChar((char*)&key);
			break;
		case 1:
			username->addChar((char*)&key);
			break;
		}
	}

}
void LoginScene::processMouseDown(unsigned int button, unsigned int x, unsigned int y)
{
  if(button == GLUT_LEFT){
	  handleMouseDown(Point(x,y));
  }
}

void LoginScene::processMouseUp(unsigned int button, unsigned int x, unsigned int y)
{
  if(button == GLUT_LEFT){
	  handleMouseUp(Point(x,y));
  }
}

Scene* LoginScene::switchScene(){
	//return new SelectionScene();
	return new Transition(new SelectionScene(), true);
}

void LoginScene::drawSucess(){
	glPushMatrix();
		glColor3f(0.0,1.0,0.0);
		glTranslatef(-2.6,-1.0,-6);
		glLineWidth(1.5f);
		glScalef(0.002,0.0015,0.001);
		string board = "You are now logged in!";
		for(unsigned int a = 0; a < board.length(); a++){
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, board[a]);
		}
	glPopMatrix();
}

void LoginScene::drawFailure(){
	glPushMatrix();
		glColor3f(1.0,0.0,0.0);
		glTranslatef(-4.0,5.0,0);
		glLineWidth(1.5f);
		glScalef(0.005,0.015,0.000);
		string board = "Incorrect Login!";
		for(unsigned int a = 0; a < board.length(); a++){
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, board[a]);
		}
	glPopMatrix();
}
bool LoginScene::handleMouseDown(Point p){
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  currentBBox = ok->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  ok->setColor(Color(0.0, 1.0, 0.0));
	  return true;
  }
  currentBBox = cancel->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  cancel->setColor(Color(0.0, 1.0, 0.0));
	  return true;
  }
  currentBBox = user->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  return true;
  }
  currentBBox = pass->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  return true;
  }
  return false;
}
bool LoginScene::handleMouseUp(Point p){
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.5, 0.0, 1.0));
	  exit(0);
  }
  currentBBox = ok->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  ok->setColor(Color(0.5, 0.0, 1.0));
	  if(LoginManager::tryLogin(username->getString(),password->getString())){
			needASwitch = true;
	  }else{
			drawF = true;
	  }
  }
  currentBBox = cancel->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  cancel->setColor(Color(0.5, 0.0, 1.0));
	  username->setInput("");
	  password->setInput("");
	  username->setFocus(true);
	  password->setFocus(false);
	  focus_set = 1;
  }
  currentBBox = user->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  username->setFocus(true);
	  password->setFocus(false);
	  focus_set = 1;
  }
  currentBBox = pass->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  username->setFocus(false);
	  password->setFocus(true);
	  focus_set = 2;
  }
  return false;
}
