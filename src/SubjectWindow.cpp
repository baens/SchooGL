#ifdef _WIN32
#include <windows.h>
#endif
#include <Rectangle1.h>
#include <SubjectWindow.h>
#include <Color.h>
#include <Util.h>
#include <BBox.h>

SubjectWindow::SubjectWindow(string achievement[3]){
	Point subject1(-4.0, 5.0);
	Point subject2(-4.0, 2.0);
	Point subject3(-4.0, -1.0);
	Point achieve1(5.0, 5.0);
	Point achieve2(5.0, 2.0);
	Point achieve3(5.0, -1.0);
	Point t1(-4.0, 8.0);
	Point t2(5.0, 8.0);
	Point ex(7.5, -9);
	Color color(1.0, 0.0, 0.0);
	Color color2(0.0, 0.0, 1.0, 0.0);
	Color ecolor(0.5, 0.0, 1.0);
	this->subjects[0] = new Rectangle1(1.25, 0.0, subject1, color, "Placement");
	subjectCats[0] = Placement;
	this->subjects[1] = new Rectangle1(1.25, 0.0, subject2, color, "Addition");
	subjectCats[1] = Addition;
	this->subjects[2] = new Rectangle1(1.25, 0.0, subject3, color, "Subtraction");
	subjectCats[2] = Subtraction;
	this->achievements[0] = new Rectangle1(1.25, 0.0, achieve1, color, achievement[0]);
	this->achievements[1] = new Rectangle1(1.25, 0.0, achieve2, color, achievement[1]);
	this->achievements[2] = new Rectangle1(1.25, 0.0, achieve3, color, achievement[2]);
	this->title[0] = new Rectangle1(2.0, 0.0, t1, color2, "Subject");
	this->title[1] = new Rectangle1(2.0, 0.0, t2, color2, "Complete");
	lastSelectedSubject = Addition;
	this->pexit = new Rectangle1(0.0, 0.0, ex, ecolor, "Exit");
	this->edit = new Rectangle1(0.0, 0.0, Point(-4.5, -9), ecolor, "Edit Profile");
}
void SubjectWindow::draw(){
	subjects[0]->draw();
	subjects[1]->draw();
	subjects[2]->draw();
	achievements[0]->draw();
	achievements[1]->draw();
	achievements[2]->draw();
	title[0]->draw();
	title[1]->draw();
	pexit->draw();
	edit->draw();
}

bool SubjectWindow::handleMouseDown(Point p)
{
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  for(int a = 0; a < 4; a++){
    BBox currentBBox = subjects[a]->getBBox();
    if(currentBBox.containPoint(screen_point)){

      subjects[a]->setColor(Color(0.0,1.0,0.0));
      lastSelectedSubject = subjectCats[a];
      return true;
    }
  }
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  currentBBox = edit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  edit->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  return false;
}

int SubjectWindow::handleMouseUp(Point p)
{
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  for(int a = 0; a < 4; a++){
    BBox currentBBox = subjects[a]->getBBox();
    if(currentBBox.containPoint(screen_point)){
      subjects[a]->setColor(Color(1.0,0.0,0.0));
      return 0;
    }
  }
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.5, 0.0, 1.0));
	  exit(0);
  }
  currentBBox = edit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  edit->setColor(Color(0.5, 0.0, 1.0));
	  return 1;
  }
  return -1;
}
