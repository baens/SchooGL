/*
When creating your project, uncheck OWL,
uncheck Class Library, select Static
instead of Dynamic and change the target
model to Console from GUI.
Also link glut.lib to your project once its done.
*/
#ifdef _WIN32
#include <windows.h>   // Standard Header For Most Programs
#endif
#include "Color.h"
#include "Point.h"
#include "Vector.h"
#include "InputBox.h"

#include <LoginManager.h>
#include <stdlib.h>
//#include <GL/gl.h>     // The GL Header File
#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include "Question.h"
#include "StatWindow.h"
#include "Rectangle1.h"
#include "BattleWindow.h"
#include "SubjectWindow.h"
#include "DifficultyWindow.h"
#include "ProfileWindow.h"
#include "Animation.h"
#include "Scene.h"
#include "LoginScene.h"
#include "Transition.h"
#include "SelectionScene.h"
#include "QuestionManager.h"
Rectangle1 rec;
Rectangle1 rec2;
//Animation* ani;
bool done;
int an = 0;
Scene* scene;
//Transition* tran;
BattleWindow* bwin;
void init ( GLvoid )     // Create Some Everyday Functions
{
  glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
  //rec = new Rectangle1(5.0,3.0,Point(0.0,2.0,-1.0),Color(1.0,1.0,1.0),"");
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);	// Clear The Background Color To Blue 
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading	
  rec2 = Rectangle1(5.0, 5.0, Point(5.0, 0.0), "data/monster/enemy");
  rec = Rectangle1(5.0,5.0,Point(-3.0,0.0),"data/character/attack1",Color(0.0,0.0,1.0));
  UserManager::setID(90);
  //ani = new Animation(3, 0, -1);
  //tran = new Transition();
  //tran = new Transition(new SelectionScene(), true);
  //tran = new Transition(new SelectionScene(), ani, true);
  //tran = new Transition(new SelectionScene(), ani, false);
  bwin = new BattleWindow(QuestionManager::getQuestion(),rec2,rec,0);
}
void display ( void )   // Create The Display Function
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
   glLoadIdentity();	

   //rec->draw();
   //rec2->draw();
   //tran->draw();
   bwin->draw();
   //if(tran->getNeedASwitch())
	   //scene = tran->switchScene();
   //scene->draw();

   glutSwapBuffers();

}
void reshape ( int w, int h )   // Create The Reshape Function (the viewport)

{

  glViewport     ( 0, 0, w, h );

  glMatrixMode   ( GL_PROJECTION );  // Select The Projection Matrix

  glLoadIdentity ( );                // Reset The Projection Matrix

  glOrtho(-10,10,-10,10,-1.0f,10.0f);				// Create Ortho 640x480 View (0,0 At Top Left)

  glMatrixMode   ( GL_MODELVIEW );  // Select The Model View Matrix

  glLoadIdentity ( );    // Reset The Model View Matrix

}
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function

{

   switch ( key ) {
    case 27:        // When Escape Is Pressed...
      exit ( 0 );   // Exit The Program
      break;        // Ready For Next Case
  }

}
void arrow_keys ( int a_keys, int x, int y )  // Create Special Function (required for arrow keys)

{

  switch ( a_keys ) {

    case GLUT_KEY_UP:     // When Up Arrow Is Pressed...

      glutFullScreen ( ); // Go Into Full Screen Mode

      break;

    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...

      glutReshapeWindow ( 500, 500 ); // Go Into A 500 By 500 Window

      break;

    default:

      break;

  }

}
void mouse_action(int button, int state, int x, int y)
{

}
int main ( int argc, char** argv )   // Create Main Function For Bringing It All Together

{

  glutInit            ( &argc, argv ); // Erm Just Write It =)

  

  glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH ); // Display Mode

  glutInitWindowSize  ( 500, 500 ); // If glutFullScreen wasn't called this is the window size

  glutCreateWindow    ( "NeHe's OpenGL Framework" ); // Window Title (argv[0] for current directory as title)

  glutFullScreen      ( );          // Put Into Full Screen

  glutDisplayFunc     ( display );  // Matching Earlier Functions To Their Counterparts

  glutReshapeFunc     ( reshape );

  glutKeyboardFunc    ( keyboard );

  glutSpecialFunc     ( arrow_keys );
 
  glutMouseFunc       ( mouse_action );

  glutIdleFunc			 ( display );

  init ();

  glutMainLoop        ( );          // Initialize The Main Loop

  return 0;

}
