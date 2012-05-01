#ifdef _WIN32
#include <windows.h>
#endif
#include <PrintManager.h>
#include <string>
#include <GL/glut.h>
#include <StatScene.h>
#include <SelectionScene.h>
#include <Util.h>
#include "Transition.h"

using namespace std;

StatScene::StatScene(){
  statWindow = new StatWindow("Addition","Easy",1,0);
  needASwitch = false;
}

StatScene::StatScene(Subject s, Difficulty d, int c, int m){
	
  statWindow = new StatWindow(to_string(s),to_string(d),c,m);
  needASwitch = false;
}

void StatScene::draw()
{
  statWindow->draw();
}

bool StatScene::needSwitch()
{
  return needASwitch;
}

void StatScene::processInput(unsigned int key)
{
  if(key = 'p')
    PrintManager::print(1024,768);
}

void StatScene::processMouseDown(unsigned int button, unsigned int x,unsigned int y)
{
  if(button == GLUT_LEFT){
    statWindow->handleMouseDown(Point(x,y));
  }
}

void StatScene::processMouseUp(unsigned int button,unsigned int x,unsigned int y)
{
  if(button == GLUT_LEFT){
    if(statWindow->handleMouseUp(Point(x,y)))
      needASwitch = true;
  }
}

Scene* StatScene::switchScene()
{
  //return new SelectionScene();
  return new Transition(new SelectionScene(), true);
}
