#ifdef _WIN32
#include <windows.h>
#endif
#include <Rectangle1.h>
#include <DifficultyWindow.h>
#include <Color.h>
#include <Util.h>
#include <UserManager.h>

DifficultyWindow::DifficultyWindow(){
	Point diff1(-6.0, -1.0);
	Point diff2(0.0, -1.0);
	Point diff3(6.0, -1.0);
	Point mon1(-6.5, 4.0);
	Point mon2(-0.5, 4.0);
	Point mon3(5.5, 4.0);
	Point ex(7.5, -9);
	Point b(-7.5, -9);
	Color color(1.0, 0.0, 0.0);
	Color color1(0.0, 1.0, 0.0);
	Color ecolor(0.5, 0.0, 1.0);
	this->difficulties[0] = new Rectangle1(0.0, 0.0, diff1, color, "Easy");
	difficultiesCat[0] = Easy;
	this->difficulties[1] = new Rectangle1(0.0, 0.0, diff2, color, "Medium");
	difficultiesCat[1] = Medium;
	this->difficulties[2] = new Rectangle1(0.0, 0.0, diff3, color, "Hard");
	difficultiesCat[2] = Hard;
	//this->monsters[0] = new Rectangle1(5.0, 3.0, mon1, color1, "");
	//this->monsters[1] = new Rectangle1(5.0, 3.0, mon2, color1, "");
	//this->monsters[2] = new Rectangle1(5.0, 3.0, mon3, color1, "");
	this->monsters[0] = new Rectangle1(5.0, 5.0, mon1, "data/monster/enemy");
	this->monsters[1] = new Rectangle1(5.0, 5.0, mon2, "data/monster/enemy1");
	this->monsters[2] = new Rectangle1(5.0, 5.0, mon3, "data/monster/enemy2");
	this->pexit = new Rectangle1(0.0, 0.0, ex, ecolor, "Exit");
	this->back = new Rectangle1(0.0, 0.0, b, ecolor, "Back");
}
void DifficultyWindow::draw(){
	difficulties[0]->draw();
	difficulties[1]->draw();
	difficulties[2]->draw();
	monsters[0]->draw();
	monsters[1]->draw();
	monsters[2]->draw();
	pexit->draw();
	back->draw();
}

bool DifficultyWindow::handleMouseDown(Point p)
{
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  for(int a = 0; a < 3; a++){
    BBox currentBBox = difficulties[a]->getBBox();
    if(currentBBox.containPoint(screen_point)){
      difficulties[a]->setColor(Color(0.0,1.0,0.0));
      lastSelectedDifficulty = difficultiesCat[a];
      return true;
    }
  }
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  currentBBox = back->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  back->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  return false;
}

int DifficultyWindow::handleMouseUp(Point p)
{
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  for(int a = 0; a < 3; a++){
    BBox currentBBox = difficulties[a]->getBBox();
    if(currentBBox.containPoint(screen_point)){
      difficulties[a]->setColor(Color(1.0,0.0,0.0));
      return 0;
    }
  }
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.5, 0.0, 1.0));
	  exit(0);
  }
  currentBBox = back->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  back->setColor(Color(0.5, 0.0, 1.0));
	  return 1;
  }
  return -1;
}

void DifficultyWindow::setSubject(Subject s)
{
  Color invalid(0.5,0.5,0.5);
  switch(s){
  case Addition:
    if(UserManager::getAddScore() > UserManager::getTeacher().getAddEasy())
      this->difficulties[0]->setColor(invalid);
    if(UserManager::getAddScore() > UserManager::getTeacher().getAddMed())
      this->difficulties[1]->setColor(invalid);
    break;
  case Subtraction:
    if(UserManager::getSubScore() > UserManager::getTeacher().getSubEasy())
      this->difficulties[0]->setColor(invalid);
    if(UserManager::getSubScore() > UserManager::getTeacher().getSubMed())
      this->difficulties[1]->setColor(invalid);
    break;
  case Placement:
    if(UserManager::getPlaceScore() > UserManager::getTeacher().getPlaceEasy())
      this->difficulties[0]->setColor(invalid);
    if(UserManager::getPlaceScore() > UserManager::getTeacher().getPlaceMed())
      this->difficulties[1]->setColor(invalid);
  }
}
