#include <GL/glut.h>
#include <BBox.h>

BBox::BBox()
{
  
}

BBox::BBox(Point minPoint, Point maxPoint)
{
  this->minPoint = minPoint;
  this->maxPoint = maxPoint;
}

Point BBox::min()
{
  return minPoint;
}

Point BBox::max()
{
  return maxPoint;
}

bool BBox::containPoint(Point p)
{
  /*GLint viewport[4];
  GLdouble modelview[16];
  GLdouble projection[16];
  GLfloat winX, winY, winZ;
  GLdouble posX, posY, posZ;
  glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
  glGetDoublev( GL_PROJECTION_MATRIX, projection );
  glGetIntegerv( GL_VIEWPORT, viewport );
  winX = (float)x;
  winY = (float)viewport[3] - (float)y;
  glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
  gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
  Point mouseToSpace(x,y);*/
  double minX = minPoint.getX();
  double minY = minPoint.getY();
  double maxX = maxPoint.getX();
  double maxY = maxPoint.getY();
  
  double poiX = p.getX();
  double poiY = p.getY();
  
  //double check all points to make sure the lower left is the min point
  //and the upper left is the max points
  if(minX > maxX){
    double temp = minX;
    minX = maxX;
    maxX = temp;
  }
  if(minY > maxY){
    double temp = minY;
    minY = maxY;
    maxY = temp;
  }

  if(poiX > minX && poiY > minY && poiX < maxX && poiY < maxY)
    return true;
  else
    return false;
}
