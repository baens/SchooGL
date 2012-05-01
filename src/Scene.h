#ifndef SCENE_H
#define SCENE_H
class Scene {
public:
	virtual void draw()=0;
	virtual void processInput(unsigned int key)=0;
	virtual void processMouseDown(unsigned int button, unsigned int x, unsigned int y)=0;
	virtual void processMouseUp(unsigned int button, unsigned int x, unsigned int y)=0;
	virtual bool needSwitch(){return needASwitch;}
	virtual Scene* switchScene()=0;

protected:
	bool needASwitch;
};

#endif
