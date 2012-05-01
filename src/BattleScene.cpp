#include <BattleScene.h>
#include <QuestionManager.h>
#include <StatScene.h>
#include <GL/glut.h>

BattleScene::BattleScene()
{
	needASwitch = false;
	question = QuestionManager::getQuestion();
}

BattleScene::BattleScene(Question* q)
{
	question = q;
}
void BattleScene::draw()
{
	question->drawQuestion();
}

void BattleScene::processInput(unsigned int key)
{
}

void BattleScene::processMouseDown(unsigned int button, unsigned int x, unsigned int y)
{
	if(button == GLUT_LEFT)
		question->handleLeftMouseDown(Point(x,y));
}

void BattleScene::processMouseUp(unsigned int button, unsigned int x, unsigned int y)
{
	if(button == GLUT_LEFT)
		if(question->handleLeftMouseUp(Point(x,y)))
		{
			needASwitch = true;
		}
}

Scene* BattleScene::switchScene()
{
	return new StatScene();
}
