#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "point.h"

using namespace std;


class Shape {

 private:
  string type; //type of 3D shape this is, i.e. sphere,cone,etc.
  Point loc;   //origin of the shape. Where on the shape this is varies by shape.
  Shape *next; //points to next shape in the sequence.

 protected:
  string color;
 public:
  //Constructor for Shape, setting the type, color, and location to those given.
  Shape(string type, string color, Point loc);
  
  //virtual void print_color (void); commented out for testing purposes
  
  //virtual double compute_volume (void);

  //Prints the type of the shape.
  void print_type (void);

  //Prints the location of the shape.
  void print_loc (void);

  //Sets the variable next to the Shape * that the user passes in.
  void set_next(Shape *next);

  //Returns the variable next.
  Shape *get_next(void);
  
};

#endif
