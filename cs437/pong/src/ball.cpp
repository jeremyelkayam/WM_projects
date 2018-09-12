
/*
  ball.cpp
  Purpose: Simulate a ball bouncing around in the game environment.

  @author Jeremy Elkayam
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
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

  //initialize rng
  rng.seed(std::random_device()());
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


void Ball::move(double micros_elapsed)
{
  this->xcor+=(get_x_velocity()*micros_elapsed);
  this->ycor+=(get_y_velocity()*micros_elapsed);
}

void Ball::reflect_y()
{
  if(angle>=0){
    angle=M_PI-angle;
  }else{
    angle=-M_PI-angle;
  }
  
}

/*idea: potentially make this so that the perturbation doesn't reflect
  the ball into the direction it came from (i.e. if it would make the
  angle go past pi/2 or 3pi/2, generate a new perturbation)
 */
void Ball::reflect_x()
{
  angle=-angle;

  //generate a random perturbation in the range of -.3 to .3 radians
  std::uniform_real_distribution<double>unif(-0.1,0.1);

  double perturbation=unif(rng);
  
  //add this perturbation to the reflected angle
  angle+=perturbation;

  cout << "perturbation: " << perturbation << "\n";
}

