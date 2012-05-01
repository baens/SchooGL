#ifndef TRANSITION_H
#define TRANSITION_H 1
#include <Scene.h>
#include <Animation.h>
#include <vector>
#include <Rectangle1.h>
#include <BattleWindow.h>
class Transition : public Scene {
public:
	Transition();
	Transition(Scene* scene, bool scen);
	Transition(Scene* scene, Animation* animation, bool scen);
	Transition(BattleWindow* bwin, Animation* animation, bool scen);
	Transition(const Transition& rhs);
	void draw();
	void processInput(unsigned int key);
	void processMouseDown(unsigned int button, unsigned int x, unsigned int y);
	void processMouseUp(unsigned int button, unsigned int x, unsigned int y);
	Scene* switchScene(){return scene;}
	bool isDone(){return done;}
private:
	Animation* anim;
	Scene* scene;
	BattleWindow* bwin;
	void drawS();
	void drawSA();
	void drawA();
	void setupVec();
	vector<Rectangle1> rec;
	int n;
	bool sce;
	bool countDown;
	bool s;
	bool done;
	int frame;
	int frameRate;
};
#endif
