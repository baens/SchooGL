#ifndef BBOX_H
#define BBOX_H
#include <Point.h>
#ifdef _WIN32
#undef min
#undef max
#endif

class BBox {
 public:
  BBox();
  BBox(Point minPoint, Point maxPoint);

  Point min();
  Point max();

  bool containPoint(Point p);
 private:
  Point minPoint;
  Point maxPoint;
};
#endif
