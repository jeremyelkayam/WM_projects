#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;


class Point {

 private:
  double x,y,z;

 public:
  Point(){}
  Point(double x, double y, double z){ set (x,y,z);}

  void set(double x, double y, double z){ this.x=x; this.y=y; this.z=z}

  double length();

  void print(void);
};

#endif
