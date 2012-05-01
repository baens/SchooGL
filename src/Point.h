#ifndef POINT_H
#define POINT_H 1

class Point{
 public:
  //Consturctors
  Point();
  Point(double x, double y);
  Point(double x, double y, double z);
  //Copy Consturctors
  Point(const Point& rhs);
  //  Point(Point rhs):
  //test methods
  void output();
  double getX();
  double getY();
  double getZ();
 private:
  double x;
  double y;
  double z;
};

#endif //POINT_H
