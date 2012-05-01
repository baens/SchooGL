#include <Scene.h>
#include <SubjectWindow.h>
#include <DifficultyWindow.h>
#include <ProfileWindow.h>

class SelectionScene : public Scene {
 public:
  SelectionScene();
  void draw();
  void processInput(unsigned int key);
  void processMouseDown(unsigned int button, unsigned int x, unsigned int y);
  void processMouseUp(unsigned int button, unsigned int x, unsigned int y);
  Scene* switchScene();
 private:
  SubjectWindow* subWindow;
  DifficultyWindow* diffWindow;
  Subject subject;
  Difficulty difficulty;
  ProfileWindow* profile;
  bool displaySubject;
  bool displayProfile;
};
