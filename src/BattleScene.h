#include <Scene.h>
#include <Question.h>
class BattleScene : public Scene{
public:
	BattleScene();
	BattleScene(Question* q);
	void draw();
	void processInput(unsigned int key);
	void processMouseDown(unsigned int button, unsigned int x, unsigned int y);
	void processMouseUp(unsigned int button, unsigned int x, unsigned int y);
	Scene* switchScene();
private:
	Question* question;
};

