#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include "Rectangle1.h"
#include <GL/gl.h>
#include "Point.h"
#include <string>

using namespace std;

class Animation{
public:
	Animation();
	Animation(string mon, int a, int startPlace, int nextPlace);
	Animation(Animation& rhs);
	bool draw();
	void setPlace(int start, int next);
	void setAni(int an);
private:
	string mon;
	void setupAnimations();
	int ani;
	int drawn;
	bool done;
	vector<Rectangle1> enter; // 0
	vector<Rectangle1> attack; // 1
	vector<Rectangle1> defend; // 2
	vector<Rectangle1> victory; // 3
	vector<Rectangle1> enemyEnter; // 0
	vector<Rectangle1> enemyAttack; // 1
	vector<Rectangle1> enemyDefend; // 2
	void setupEnter();
	void setupAttack();
	void setupDefend();
	void setupVictory();
	void enterDraw();
	void attackDraw();
	void defendDraw();
	void victoryDraw();
	int frame;
	int frameRate;
	Point startp;
	Point nextp;
};
#endif
