#ifdef _WIN32
#include <windows.h>
#endif
#include <Util.h>
#include <GL/glut.h>
#include <stdlib.h>

string to_string(int val)
{
  char s[50];
  sprintf(s, "%d", val);
  return string(s);
}

string to_string(double val)
{
  char s[50];
  sprintf(s, "%g", val);
  return string(s);
}

string to_string(Subject s){
  switch(s){
  case Addition:
    return "Addition";
  case Subtraction:
    return "Subtraction";
  case Placement:
    return "Placement";
  default:
    return "";
  }
}

string to_string(Difficulty d){
  switch(d){
  case Easy:
    return "Easy";
  case Medium:
    return "Medium";
  case Hard:
    return"Hard";
  default:
    return "";
  }
}

Point screen_to_obj(double x, double y)
{
  GLint viewport[4];
  GLdouble modelview[16];
  GLdouble projection[16];
  GLfloat winX, winY, winZ;
  GLdouble posX, posY, posZ;

  glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
  glGetDoublev( GL_PROJECTION_MATRIX, projection );
  glGetIntegerv( GL_VIEWPORT, viewport );

  winX = (float)x;
  winY = (float)viewport[3] - (float)y;
  //winZ = .84;
  glReadPixels( winX, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
  
  gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
  
  return Point(posX,posY);
}

int to_int(string s)
{
  int res;
  sscanf(s.c_str(),"%d",&res);
  return res;
}

double to_double(string s)
{
  float res;
  sscanf(s.c_str(),"%f",&res);
  return res;
}
