#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>
#include "shape.h"

using namespace std;


class Box : public Shape {

 private:
  double length,width,height;
  string tbcolor;

   public:
  Box(string type, string color, string tbcolor, double length, double width, double height, Point loc);

  void print_color (void);
  
  double compute_volume (void);
  
  // the following overrides print_type in the base class, but can never be called
  //  through a pointer to the base class
  void print_type (void) { cout << "should never be called" << endl; }
};

#endif
