#ifdef _WIN32
#include <windows.h>
#endif
#include "Animation.h"
#include "Point.h"
#include <UserManager.h>=
Animation::Animation(){

}
Animation::Animation(string mon, int a, int startPlace, int nextPlace){
	this->mon = mon;
	this->ani = a;
	this->drawn = 1;
	this->done = false;
	this->frame = 0;
	this->frameRate = 150;
	this->startp = Point(-1.25 + startPlace, -5.0);
	this->nextp = Point(-1.25 + nextPlace, -5.0);
	setupAnimations();
}
Animation::Animation(Animation &rhs){
		
}
bool Animation::draw(){
	switch(ani){
		case 0:
			enterDraw();
			break;
		case 1:
			attackDraw();
			break;
		case 2:
			defendDraw();
			break;
		case 3:
			victoryDraw();
			break;
		default:
			enterDraw();
			break;
	}
	frame++;
	return done;
}
void Animation::setupAnimations(){
  switch(ani){
  case 0:
	setupEnter();
	break;
  case 1:
	setupAttack();
	break;
  case 2:
	setupDefend();
	break;
  case 3:
	setupVictory();
	break;
  }
}
void Animation::setAni(int an){
	this->ani = an;
	this->done = false;
}
void Animation::setPlace(int start, int next){
	this->startp = Point(-1.25 + start, -5.0);
	this->nextp = Point(-1.25 + next, -5.0);
}
// private set ups
void Animation::setupEnter(){
	Point* p1 = new Point(-9.75, -5.0);	Point* p2 = new Point(-9.25, -5.0);	Point* p3 = new Point(-8.75, -5.0);
	Point* p4 = new Point(-8.25, -5.0);	Point* p5 = new Point(-7.75, -5.0);	Point* p6 = new Point(-7.25, -5.0);
	Point* p7 = new Point(-6.75, -5.0);	Point* p8 = new Point(-6.25, -5.0);	Point* p9 = new Point(-5.75, -5.0);
	Point* p10 = new Point(-5.25, -5.0); Point* p11 = new Point(-4.75, -5.0); Point* p12 = new Point(-4.25, -5.0);
	Point* p13 = new Point(-3.75, -5.0); Point* p14 = new Point(-3.25, -5.0); Point* p15 = new Point(-2.75, -5.0);
	Point* p16 = new Point(-2.25, -5.0); Point* p17 = new Point(-1.75, -5.0); Point* p18 = new Point(-1.25, -5.0);
	Rectangle1 nostep(5.0, 5.0, Point(-10.75, -5.0), "data/character/nostep",UserManager::getProfile().getColor());
	Rectangle1 step(5.0, 5.0, Point(-10.25, -5.0), "data/character/step",UserManager::getProfile().getColor());
	Rectangle1 draw1(5.0, 5.0, Point(-1.25, -5.0), "data/character/draw1",UserManager::getProfile().getColor());
	Rectangle1 draw2(5.0, 5.0, Point(-1.25, -5.0), "data/character/draw2",UserManager::getProfile().getColor());
	Rectangle1 draw3(5.0, 5.0, Point(-1.25, -5.0), "data/character/draw3",UserManager::getProfile().getColor());
	Rectangle1 defense(5.0, 5.0, Point(-1.25, -5.0), "data/character/defensivestance",UserManager::getProfile().getColor());
	enter.push_back(nostep); enter.push_back(step); nostep.setPoint(p1); step.setPoint(p2);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p3); step.setPoint(p4);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p5); step.setPoint(p6);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p7); step.setPoint(p8);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p9); step.setPoint(p10);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p11); step.setPoint(p12);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p13); step.setPoint(p14);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p15); step.setPoint(p16);
	enter.push_back(nostep); enter.push_back(step);	nostep.setPoint(p17); step.setPoint(p18);
	enter.push_back(nostep); enter.push_back(step);	enter.push_back(draw1);	enter.push_back(draw2);	enter.push_back(draw3);	enter.push_back(defense);
	Rectangle1 monster(5.0, 5.0, Point(10.5, -6), "data/monster/" + mon);
	enemyEnter.push_back(monster); Point* point = new Point(10.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(9.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(9.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(8.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(8.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(7.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(7.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(6.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(6.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(5.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(4.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(3.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(3.0, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); point = new Point(2.5, -6); monster.setPoint(point);
	enemyEnter.push_back(monster); enemyEnter.push_back(monster); enemyEnter.push_back(monster); 
	enemyEnter.push_back(monster); enemyEnter.push_back(monster); enemyEnter.push_back(monster);
	enemyEnter.push_back(monster); enemyEnter.push_back(monster); enemyEnter.push_back(monster);
	enemyEnter.push_back(monster);
}
void Animation::setupAttack(){
	Point p1 = this->startp;//startp;
	Point p3 = this->nextp; //nextp;
	Point p2 = Point((p1.getX()+p3.getX())/2,(p1.getY()+p3.getY())/2);
	Rectangle1 defense1(5.0, 5.0, p1, "data/character/defensivestance",UserManager::getProfile().getColor());
	Rectangle1 attack1(5.0, 5.0, p1, "data/character/attack1",UserManager::getProfile().getColor());
	Rectangle1 attack2(5.0, 5.0, p1, "data/character/attack2",UserManager::getProfile().getColor());
	Rectangle1 attack3(5.0, 5.0, p1, "data/character/attack3",UserManager::getProfile().getColor());
	Rectangle1 attack4(5.0, 5.0, p2, "data/character/attack4",UserManager::getProfile().getColor());
	Rectangle1 attack5(5.0, 5.0, p2, "data/character/attack5",UserManager::getProfile().getColor());
	Rectangle1 defense2(5.0, 5.0, p3, "data/character/defensivestance",UserManager::getProfile().getColor());
	attack.push_back(defense1);	attack.push_back(attack1);
	attack.push_back(attack2); attack.push_back(attack3);
	attack.push_back(attack4); attack.push_back(attack5);
	attack.push_back(defense2);
	Point point1 = Point(p1.getX() + 3.75, p1.getY() - 1);
	Point point2 = Point(p2.getX() + 3.75, p2.getY() - 1);
	Point point3 = Point(p3.getX() + 3.75, p3.getY() - 1);
	Rectangle1 mon1(5.0, 5.0, point1, "data/monster/" + mon);
	Rectangle1 mon2(5.0, 5.0, point2, "data/monster/" + mon);
	Rectangle1 mon3(5.0, 5.0, point3, "data/monster/" + mon);
	enemyAttack.push_back(mon1); enemyAttack.push_back(mon1); enemyAttack.push_back(mon1); enemyAttack.push_back(mon1);
	enemyAttack.push_back(mon2); enemyAttack.push_back(mon2);
	enemyAttack.push_back(mon3);
}
void Animation::setupDefend(){
	Point p1 = this->startp;//startp;
	Point p4 = this->nextp; //nextp;
	Point p3 = Point((p1.getX()+p4.getX())/2,(p1.getY()+p4.getY())/2);
	Point p2 = Point((p1.getX()+p3.getX())/2,(p1.getY()+p3.getY())/2);
	//Point p1(-1.25, -5);//startp;
	//Point p2(-1.55, -5);
	//Point p3(-1.75, -5);
	//Point p4(-2.25, -5); //nextp;
	Rectangle1 defense1(5.0, 5.0, p1, "data/character/defensivestance",UserManager::getProfile().getColor());
	Rectangle1 attack1(5.0, 5.0, p1, "data/character/attack1",UserManager::getProfile().getColor());
	Rectangle1 attack2(5.0, 5.0, p1, "data/character/attack2",UserManager::getProfile().getColor());
	Rectangle1 block(5.0, 5.0, p1, "data/character/block",UserManager::getProfile().getColor());
	Rectangle1 nockback1(5.0, 5.0, p2, "data/character/nockback1",UserManager::getProfile().getColor());
	Rectangle1 nockback2(5.0, 5.0, p3, "data/character/nockback2",UserManager::getProfile().getColor());
	Rectangle1 nockback3(5.0, 5.0, p4, "data/character/nockback3",UserManager::getProfile().getColor());
	Rectangle1 nockback4(5.0, 5.0, p4, "data/character/nockback4",UserManager::getProfile().getColor());
	Rectangle1 defense2(5.0, 5.0, p4, "data/character/defensivestance",UserManager::getProfile().getColor());
	defend.push_back(defense1);
	defend.push_back(attack1); defend.push_back(attack2);
	defend.push_back(block);
	defend.push_back(nockback1); defend.push_back(nockback2);
	defend.push_back(nockback3); defend.push_back(nockback4);
	defend.push_back(defense2);
	Rectangle1 mon1(5.0, 5.0, Point(p1.getX() + 3.75, p1.getY() - 1), "data/monster/" + mon);
	Rectangle1 mon2(5.0, 5.0, Point(p2.getX() + 3.75, p2.getY() - 1), "data/monster/" + mon);
	Rectangle1 mon3(5.0, 5.0, Point(p3.getX() + 3.75, p3.getY() - 1), "data/monster/" + mon);
	Rectangle1 mon4(5.0, 5.0, Point(p4.getX() + 3.75, p4.getY() - 1), "data/monster/" + mon);
	enemyDefend.push_back(mon1); enemyDefend.push_back(mon1); enemyDefend.push_back(mon1); enemyDefend.push_back(mon1);
	enemyDefend.push_back(mon2); enemyDefend.push_back(mon3);
	enemyDefend.push_back(mon4); enemyDefend.push_back(mon4); enemyDefend.push_back(mon4);
}
void Animation::setupVictory(){
	Point p1 = this->startp;//startp;
	Point p2 = Point(p1.getX(), -4.5);
	Point p3 = Point(p1.getX(), -4);
	//Point p1(-1.25, -5);
	//Point p2(-1.25, -4.5);
	//Point p3(-1.25, -4);
	Rectangle1 defense(5.0, 5.0, p1, "data/character/defensivestance",UserManager::getProfile().getColor());
	Rectangle1 victory1(5.0, 5.0, p1, "data/character/victory1",UserManager::getProfile().getColor());
	Rectangle1 victory2(5.0, 5.0, p1, "data/character/victory2",UserManager::getProfile().getColor());
	Rectangle1 victory3(5.0, 5.0, p2, "data/character/victory1",UserManager::getProfile().getColor());
	Rectangle1 victory4(5.0, 5.0, p3, "data/character/victory1",UserManager::getProfile().getColor());
	Rectangle1 victory5(5.0, 5.0, p2, "data/character/victory1",UserManager::getProfile().getColor());
	victory.push_back(defense);
	victory.push_back(victory1); victory.push_back(victory2);
	victory.push_back(victory3); victory.push_back(victory4);
	victory.push_back(victory5); victory.push_back(victory1);
	victory.push_back(victory2); victory.push_back(victory3);
	victory.push_back(victory4); victory.push_back(victory5);
}

// private draws
void Animation::enterDraw(){
	if(drawn == enter.size() - 1){
		//this->drawn = 1;
		this->done = true;
	}
	//enter[drawn].setPoint(
	enter[drawn].draw();
	enemyEnter[drawn].draw();
	if(frame % frameRate == 0)
		drawn++;
}
void Animation::attackDraw(){
	if(drawn == attack.size() - 1){
		//this->drawn = 1;
		this->done = true;
	}
	attack[drawn].draw();
	enemyAttack[drawn].draw();
	if(frame % frameRate == 0)
		drawn++;
}
void Animation::defendDraw(){
	if(drawn == defend.size() - 1){
		//this->drawn = 1;
		this->done = true;
	}
	defend[drawn].draw();
	enemyDefend[drawn].draw();
	if(frame % frameRate == 0)
		drawn++;
}
void Animation::victoryDraw(){
	if(drawn == victory.size() - 1){
		//this->drawn = 1;
		this->done = true;
	}
	victory[drawn].draw();
	if(frame % frameRate == 0)
		drawn++;
}
