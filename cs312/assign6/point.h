#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;


class Point {

 private:
  double x,y,z;

 public:
  Point(){}
  //Initializes Point with the given x,y, and z values
  Point(double x, double y, double z){ set (x,y,z);}

  //Sets the coordinates of the point to the given values.
  void set(double x, double y, double z){ this->x=x; this->y=y; this->z=z;}

  //Gives the Euclidean distance of the point from the origin.
  double length();

  //Prints the coordinates of the point.
  void print(void);

  //Subtraction overload case for points; subtracts the coordinates of the second point from the first.
  Point operator-(const Point& param);
};

#endif
