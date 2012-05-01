#ifdef _WIN32
#include <windows.h>
#endif
#include "ProfileWindow.h"
#include <string>
#include "InputBox.h"
#include <GL/glut.h>
#include <Util.h>
#include <BBox.h>
#include <UserManager.h>

ProfileWindow::ProfileWindow(){
	this->title = new Rectangle1(0.0, 0.0, Point(0.0, 9.0), Color(0.0, 0.0, 0.0), "Profile");
	//this->character = new Rectangle1(5.0, 3.0, Point(0.0, 2.0), UserManager::getProfile().getColor(), "");
	this->character = new Rectangle1(6.0, 6.0, Point(0.0, 2.0), "data/character/profilepage",UserManager::getProfile().getColor());
	this->nickname = new InputBox(10, 1, Point(0.0, 6.0));
	this->colors[0] = new Rectangle1(2.0, 2.0, Point(-4.5, -3.0), Color(1.0, 1.0, 1.0), "");
	this->colors[1] = new Rectangle1(2.0, 2.0, Point(-2.25, -3.0), Color(1.0, 0.0, 0.0), "");
	this->colors[2] = new Rectangle1(2.0, 2.0, Point(0.0, -3.0), Color(0.0, 1.0, 0.0), "");
	this->colors[3] = new Rectangle1(2.0, 2.0, Point(2.25, -3.0), Color(0.0, 0.0, 1.0), "");
	this->colors[4] = new Rectangle1(2.0, 2.0, Point(4.5, -3.0), Color(1.0, 0.0, 0.5), "");
	this->pexit = new Rectangle1(0.0, 0.0, Point(7.5, -9), Color(0.5, 0.0, 1.0), "Exit");
	this->save = new Rectangle1(0.0, 0.0, Point(-4.5, -9), Color(0.5, 0.0, 1.0), "Save Profile");
	nickname->setTitle("Nickname");
	nickname->setInput(UserManager::getProfile().getNick());
	nickname->setFocus(true);
}
void ProfileWindow::draw(){
	title->draw();
	nickname->drawBox();
	character->draw();
	colors[0]->draw();
	colors[1]->draw();
	colors[2]->draw();
	colors[3]->draw();
	colors[4]->draw();
	pexit->draw();
	save->draw();
}
bool ProfileWindow::handleMouseDown(Point p){
	Point screen_point = screen_to_obj(p.getX(),p.getY());
	for(int a = 0; a < 5; a++){
		BBox currentBBox = colors[a]->getBBox();
		if(currentBBox.containPoint(screen_point)){
			return true;
		}
	}
	BBox currentBBox = pexit->getBBox();
	if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.0,1.0, 0.0));
	  return true;
	}
	currentBBox = save->getBBox();
	if(currentBBox.containPoint(screen_point)){
		save->setColor(Color(0.0, 1.0, 0.0));
		return true;
	}
	return false;
}
bool ProfileWindow::handleMouseUp(Point p){
	Point screen_point = screen_to_obj(p.getX(),p.getY());
	for(int a = 0; a < 5; a++){
	  BBox currentBBox = colors[a]->getBBox();
	  if(currentBBox.containPoint(screen_point)){
	    //character->setColor(colors[a]->getColor());
	    cout << "yay" << endl;
	    delete character;
	    profile.setColor(colors[a]->getColor());
	    character = new Rectangle1(6.0, 6.0, Point(0.0, 2.0), "data/character/profilepage",profile.getColor());
	  }
	}
	BBox currentBBox = pexit->getBBox();
	if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.5, 0.0, 1.0));
	  exit(0);
	}
	currentBBox = save->getBBox();
	if(currentBBox.containPoint(screen_point)){
	  profile.setNick(nickname->getString());
	  save->setColor(Color(0.5, 0.0, 1.0));
	  saveProfile();
	  return true;
	}
	return false;
}
void ProfileWindow::processInput(unsigned int key){
	switch(key){
	 case(8):
		nickname->deleteChar();
		break;
	 default:
		if(isalpha(key))
			nickname->addChar((char*)&key);
		break;
	}
}
