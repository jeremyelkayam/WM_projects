/*
  ball.cpp
  Purpose: Simulate a ball bouncing around in the game environment.

  @author Jeremy Elkayam
 */
#include <iostream>
#include <cmath>
#include "ball.hpp"

using namespace std;

/*Constructor for the Ball class.

  @param angle: direction of velocity in radians 
  @param speed: magnitude of velocity in pixels per millisecond
  @param xcor: starting x-coordinate in pixels
  @param ycor: starting y-coordinate in pixels
 */
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
      angle_changed=false;
    }
  return cached_xvelocity;
}

double Ball::get_y_velocity()
{
  if(angle_changed)
    {
      cached_yvelocity=speed*sin(angle);
      angle_changed=false;
    }
  return cached_yvelocity;
}

void Ball::set_angle(double angle){
  this->angle=angle;
  this->angle_changed=true;
}

void Ball::move(int ms_elapsed){
  
}
