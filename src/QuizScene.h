#include <BattleWindow.h>
#include <Scene.h>
#include <Subject.h>
#include <Difficulty.h>
#include <string>
#include <Transition.h>

using namespace std;

class QuizScene : public Scene{
 public:
  QuizScene();
  QuizScene(Subject s, Difficulty d);
  void  draw();
  void processInput(unsigned int key);
  void processMouseDown(unsigned int button, unsigned int x, unsigned int y);
  void processMouseUp(unsigned int button, unsigned int x, unsigned int y);
  Scene* switchScene();
 private:
  BattleWindow* window;
  Transition* tran;
  int oldPlace;
  int place;
  int whichAni;
  int totalAnswered;
  int answeredCorrect;
  bool displayCorrect;
  bool displayWindow;
  Rectangle1* correctRec;
  Subject subject;
  Difficulty difficulty;
  string mon;
};
