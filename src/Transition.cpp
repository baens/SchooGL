#ifdef _WIN32
#include <windows.h>
#endif
#include "Transition.h"

Transition::Transition(){
	setupVec();
	this->sce = true;
	this->n = 1;
	this->frame = 0;
	this->frameRate = 35;
	this->countDown = false;
	needASwitch = false;
	this->done = false;
}
Transition::Transition(Scene *scene, bool scen){
	this->scene = scene;
	this->sce = scen;
	this->n = 1;
	this->frame = 0;
	this->frameRate = 35;
	setupVec();
	this->countDown = false;
	needASwitch = false;
	this->done = false;
}
Transition::Transition(Scene *scene, Animation *animation, bool scen){
	this->scene = scene;
	this->anim = animation;
	this->sce = scen;
	this->s = true;
	this->n = 1;
	this->frame = 0;
	this->frameRate = 35;
	setupVec();
	this->countDown = false;
	needASwitch = false;
	this->done = false;
}
Transition::Transition(BattleWindow *bwin, Animation *animation, bool scen){
	this->bwin = bwin;
	this->anim = animation;
	this->s = false;
	this->sce = scen;
	this->n = 1;
	this->frame = 0;
	this->frameRate = 35;
	setupVec();
	this->countDown = false;
	needASwitch = false;
	this->done = false;
}
Transition::Transition(const Transition &rhs){
	this->scene = rhs.scene;
	this->anim = rhs.anim;
	this->sce = rhs.sce;
	this->n = rhs.n;
	this->frame = rhs.frame;
	this->frameRate = rhs.frameRate;
	this->countDown = rhs.countDown;
	needASwitch = false;
	this->done = false;
	//setupVec();
}
void Transition::draw(){
	if(sce){
		drawS();
	}
	else{
		if(s)
			drawSA();
		else
			drawA();
	}
	frame++;
}
void Transition::drawS(){
	if(n == 0){
		//scene->draw();
		needASwitch = true;
	}
	if(n == rec.size()){
		this->countDown = true;
	}
	for(int i = 0; i < n; i++){
		rec[i].draw();
	}
	if(frame % frameRate == 0){
		if(countDown)
			n--;
		else
			n++;
	}
}
void Transition::drawSA(){
	needASwitch = anim->draw();
}
void Transition::drawA(){
	bwin->back->draw();
	done = anim->draw();
}
void Transition::processInput(unsigned int key){}
void Transition::processMouseDown(unsigned int button, unsigned int x, unsigned int y){}
void Transition::processMouseUp(unsigned int button, unsigned int x, unsigned int y){}

void Transition::setupVec(){
	Rectangle1 rec1(5.0, 5.0, Point(0.0, 0.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec2(5.0, 5.0, Point(5.0, 0.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec3(5.0, 5.0, Point(-5.0, 0.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec4(5.0, 5.0, Point(0.0, -5.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec5(5.0, 5.0, Point(0.0, 5.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec6(5.0, 5.0, Point(5.0, 5.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec7(5.0, 5.0, Point(-5.0, 5.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec8(5.0, 5.0, Point(5.0, -5.0), Color(0.0,0.0,1.0), "");
	Rectangle1 rec9(5.0, 5.0, Point(-5.0, -5.0), Color(0.0,0.0,1.0), "");
	rec.push_back(rec1); rec.push_back(rec2); rec.push_back(rec3);
	rec.push_back(rec4); rec.push_back(rec5); rec.push_back(rec6);
	rec.push_back(rec7); rec.push_back(rec8); rec.push_back(rec9);
	Point* p = new Point(10.0, 0.0); Point* p1 = new Point(-10.0, 0.0);
	Point* p2 = new Point(0.0, 10.0); Point* p3 = new Point(0.0, -10.0);
	Point* p4 = new Point(10.0, 10.0); Point* p5 = new Point(10.0, -10.0);
	Point* p6 = new Point(-10.0, 10.0);	Point* p7 = new Point(-10.0, -10.0);
	Point* p8 = new Point(10.0, 5.0); Point* p9 = new Point(10.0, -5.0);
	Point* p10 = new Point(-10.0, 5.0);	Point* p11 = new Point(-10.0, -5.0);
	Point* p12 = new Point(5.0, 10.0); Point* p13 = new Point(5.0, -10.0);
	Point* p14 = new Point(-5.0, 10.0);	Point* p15 = new Point(-5.0, -10.0);
	rec1.setPoint(p); rec2.setPoint(p1); rec3.setPoint(p2);
	rec4.setPoint(p3); rec5.setPoint(p4); rec6.setPoint(p5);
	rec7.setPoint(p6); rec8.setPoint(p7); rec9.setPoint(p8);
	rec.push_back(rec1); rec.push_back(rec2); rec.push_back(rec3);
	rec.push_back(rec4); rec.push_back(rec5); rec.push_back(rec6);
	rec.push_back(rec7); rec.push_back(rec8); rec.push_back(rec9);
	rec3.setPoint(p9); rec4.setPoint(p10); rec5.setPoint(p11); 
	rec6.setPoint(p12); rec7.setPoint(p13);	rec8.setPoint(p14);
	rec9.setPoint(p15);
	rec.push_back(rec3); rec.push_back(rec4); rec.push_back(rec5);
	rec.push_back(rec6); rec.push_back(rec7); rec.push_back(rec8);
	rec.push_back(rec9);
}
