#ifndef VECTOR_H
#define VECTOR_H

class Vector{
 public:
  Vector();
  Vector(double x, double y, double z);
  Vector(Vector& rhs);
 private:
  double x;
  double y;
  double z;
};
#endif //VECTOR_H
