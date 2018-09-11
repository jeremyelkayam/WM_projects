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
  /*
  if(angle_changed)
    {
      remember, this uses radians
      cached_xvelocity=speed*cos(angle);
      return cached_xvelocity;
  */
  return speed*cos(angle);
}

double Ball::get_y_velocity()
{
  /*
  if(angle_changed)
    {
      cout << sin(angle) <<"\n";
      cached_yvelocity=speed*sin(angle);
      angle_changed=false;
    }
  return cached_yvelocity;
  */
  return speed*sin(angle);
}

void Ball::set_angle(double angle)
{
  this->angle=angle;
  this->angle_changed=true;
}

void Ball::move(double micros_elapsed)
{
  //cout << "\nx coordinate " << xcor <<"\ny coordinate " << ycor;
  //cout << "\nx coordinate plus stuff " << (get_x_velocity()*micros_elapsed);
  this->xcor+=(get_x_velocity()*micros_elapsed);
  this->ycor+=(get_y_velocity()*micros_elapsed);
}

void Ball::reflect_y(){
  if(angle>=0){
    angle=M_PI-angle;
  }else{
    angle=-M_PI-angle;
  }
}
