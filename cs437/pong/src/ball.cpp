#include <iostream>
#include <cmath>
#include "ball.hpp"

using namespace std;

Ball::Ball(double angle, double speed, double xcor, double ycor)
{
  this->angle=angle;
  this->speed=speed;
  this->xcor=xcor;
  this->ycor=ycor;
  this->angle_changed=true;
}

double Ball::get_x_velocity()
{
  if(angle_changed)
    {
      //remember, this uses radians
      cached_xvelocity=speed*cos(angle);
    }
  return cached_xvelocity;
}

double Ball::get_y_velocity()
{
  if(angle_changed)
    {
      cached_yvelocity=speed*sin(angle);
    }
  return cached_yvelocity;
}
