#ifdef _WIN32
#include <windows.h>
#endif
#include "StatWindow.h"
#include "Rectangle1.h"
#include "Point.h"
#include "Util.h"
#include "PrintManager.h"

StatWindow::StatWindow(string s, string d, double c, double m){
	Color color(1.0, 0.0, 0.0);
	Color ecolor(0.5, 0.0, 1.0);
	Point ex(7.5, -9);
	Point sv(-7.5, -9);
	Point subPoint(0.0f, 9.0f, 0.0f);
	Point difPoint(0.0f, 7.0f, 0.0f);
	Point correctPoint(-4.5f, 5.0f, 0.0f);
	Point missedPoint(4.0f, 5.0f, 0.0f);
	Point percentPoint(-3.0f, -2.0f, 0.0f);
	Point cPoint(-4.5f, 3.0f, 0.0f);
	Point mPoint(4.0f, 3.0f, 0.0f);
	Point pPoint(2.0f, -2.0f, 0.0f);
	double p = (c / (c + m)) * 100;
	string cString = to_string(c);
	string mString = to_string(m);
	string pString = to_string(p);
	pString = pString + "%";
	this->subRec = new Rectangle1(1.0, 1.0, subPoint, color, s);
	this->difRec = new Rectangle1(1.0, 1.0, difPoint, color, d);
	this->correctRec = new Rectangle1(1.0, 1.0, correctPoint, color, "Correct");
	this->missedRec = new Rectangle1(1.0, 1.0, missedPoint, color, "Missed");
	this->percentRec = new Rectangle1(1.0, 1.0, percentPoint, color, "Percent");
	this->numberRec[0] = new Rectangle1(1.0, 1.0, cPoint, color, cString);
	this->numberRec[1] = new Rectangle1(1.0, 1.0, mPoint, color, mString);
	this->numberRec[2] = new Rectangle1(1.0, 1.0, pPoint, color, pString);
	this->pexit = new Rectangle1(0.0, 0.0, ex, ecolor, "Exit");
	this->save = new Rectangle1(0.0, 0.0, sv, ecolor, "Save");
}
StatWindow::StatWindow(StatWindow &rhs){
	this->subRec = rhs.subRec;
	this->difRec = rhs.difRec;
	this->correctRec = rhs.correctRec;
	this->missedRec = rhs.missedRec;
	this->percentRec = rhs.percentRec;
	this->numberRec[0] = rhs.numberRec[0];
	this->numberRec[1] = rhs.numberRec[1];
	this->numberRec[2] = rhs.numberRec[2];
	this->pexit = rhs.pexit;
	this->save = rhs.save;
}
void StatWindow::draw(){
	subRec->draw();
	difRec->draw();
	correctRec->draw();
	missedRec->draw();
	percentRec->draw();
	numberRec[0]->draw();
	numberRec[1]->draw();
	numberRec[2]->draw();
	pexit->draw();
	save->draw();
}
bool StatWindow::handleMouseDown(Point p){
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  currentBBox = save->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  save->setColor(Color(0.0,1.0, 0.0));
	  return true;
  }
  return false;
}
bool StatWindow::handleMouseUp(Point p){
  Point screen_point = screen_to_obj(p.getX(),p.getY());
  BBox currentBBox = pexit->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  pexit->setColor(Color(0.5, 0.0, 1.0));
	  exit(0);
  }
  currentBBox = save->getBBox();
  if(currentBBox.containPoint(screen_point)){
	  save->setColor(Color(0.5,0.0, 1.0));
	  //TODO::lets invert the colors before we do this, my printer doesn't
	  //like printing all that black
	  //PrintManager::print(1024,768);
	  return true;
  }
  return false;
}