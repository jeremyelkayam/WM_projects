#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>
#include "shape.h"

using namespace std;


class Box : public Shape {

 private:
  double length,width,height;//Dimensions of the box; length, width, and height respectively.
  string tbcolor;

 public:
  //Initializes class with specified attributes, using Shape's constructor as a helper.
  Box(string type, string color, string tbcolor, double length, double width, double height, Point loc);

  //Overrides Shape.print_color(void), adding tbcolor.
  void print_color (void);

  //Returns the volume of the solid using lwh.
  double compute_volume (void);
  
};

#endif
