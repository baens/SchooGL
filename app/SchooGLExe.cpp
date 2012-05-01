//
// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe 
// (email Richard Campbell at ulmont@bellsouth.net)
//
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include <LoginScene.h>
#include <PrintManager.h>
#include <Rectangle1.h>

/* ascii code for the escape key */
#define ESCAPE 27

#define WIDTH 1024
#define HEIGHT 768
/* The number of our GLUT window */
int window; 
Scene* scene;
/* lighting crap */
GLfloat LightAmbient[] = {0.5f,0.5f,0.5f,1.0f};
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
Rectangle1* test;
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  
    scene = new LoginScene();
    glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
    glClearColor(0.3f, 0.2f, 0.1f, 0.0f);	// Clear The Background Color To Blue 
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
    
    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
    
    glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
    if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
	Height=1;

    glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    
	glOrtho(-10,10,-10,10,-1.0f,10.0f);
    glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene()
{
  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View
    if(scene->needSwitch())
 		scene = scene->switchScene();
    scene->draw();

    // since this is double buffered, swap the buffers to display what just got drawn.
    glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y) 
{
     /* If escape is pressed, kill everything. */
    if (key == ESCAPE) 
    { 
		/* shut down our window */
		glutDestroyWindow(window); 
	      
		  /* exit the program...normal termination. */
		exit(0);                   
    }

	scene->processInput(key);
}
/* The function called whenever the mouse is clicked */
void mouseClick(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		scene->processMouseDown(button,x,y);
	if(state == GLUT_UP)
		scene->processMouseUp(button,x,y);
}

int main(int argc, char **argv) 
{  
    /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
       X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
    glutInit(&argc, argv);  

    /* Select type of Display mode:   
     Double buffer 
     RGBA color
     Alpha components supported 
     Depth buffer */  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

    /* get a 800 x 600 window */
    glutInitWindowSize(WIDTH, HEIGHT);  

    /* the window starts at the upper left corner of the screen */
    glutInitWindowPosition(0, 0);  

    /* Open a window */  
    window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  

    /* Register the function to do all our OpenGL drawing. */
    glutDisplayFunc(&DrawGLScene);  

    /* Go fullscreen.  This is as soon as possible. */
    glutFullScreen();

    /* Even if there are no events, redraw our gl scene. */
    glutIdleFunc(&DrawGLScene);

    /* Register the function called when our window is resized. */
    glutReshapeFunc(&ReSizeGLScene);

    /* Register the function called when the keyboard is pressed. */
    glutKeyboardFunc(&keyPressed);

	glutMouseFunc(mouseClick);
    /* Initialize our window. */
    InitGL(WIDTH, HEIGHT);
  
    /* Start Event Processing Engine */  
    glutMainLoop();  

    return 1;
}

