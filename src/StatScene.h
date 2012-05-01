#ifndef STATSCENE_H
#define STATSCENE_H
#include <Scene.h>
#include <StatWindow.h>
#include <Subject.h>
#include <Difficulty.h>

class StatScene : public Scene
{
public:
	StatScene();
	StatScene(Subject s, Difficulty d, int c, int m);
	void draw();
	bool needSwitch();
	void processInput(unsigned int key);
	void processMouseDown(unsigned int button,unsigned int x,unsigned int y);
	void processMouseUp(unsigned int key,unsigned int x,unsigned int y);
	Scene* switchScene();
private:
	StatWindow* statWindow;
	bool needASwitch;
};
#endif
