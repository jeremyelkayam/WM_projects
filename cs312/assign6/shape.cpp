#include <string>
#include <iostream>
#include "shape.h"

using namespace std;

//Constructor for Shape, setting the type, color, and location to those given.
Shape::Shape(string type,string color,Point loc)
{
  this->type=type;
  this->color=color;
  this->loc=loc;
}

//Prints the coordinates of the point.
void Shape::print_type(void)
{
  cout << "Name: " << type << "\n";
}

//Prints the location of the shape.
void Shape::print_loc (void)
{
  cout << "Location: ";
  loc.print();
}

//Sets the variable next to the Shape * that the user passes in.
void Shape::set_next(Shape *next)
{
  this->next=next;
}

//Returns the variable next.
Shape* Shape::get_next(void)
{
  return next;
}

void Shape::print_color(void)
{
  cout << "Color: " << color ;
}
