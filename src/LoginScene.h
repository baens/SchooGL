#ifndef LOGINSCENE_H
#define LOGINSCENE_H 1
#include <Scene.h>
#include <InputBox.h>
#include <Point.h>
#include "Rectangle1.h"

class LoginScene : public Scene {
public:
	LoginScene();
	void draw();
	void processInput(unsigned int key);
	void processMouseDown(unsigned int button,unsigned int x, unsigned int y);
	void processMouseUp(unsigned int button, unsigned int x, unsigned int y);
	bool needSwitch();
	Scene* switchScene();
	void drawFailure();
	void drawSucess();
private:
	InputBox* password;
	InputBox* username;
	unsigned int focus_set;
	bool drawS;
	bool drawF;
	Rectangle1* pexit;
	Rectangle1* ok;
	Rectangle1* cancel;
	Rectangle1* user;
	Rectangle1* pass;
	bool handleMouseDown(Point p);
	bool handleMouseUp(Point p);
};

#endif
