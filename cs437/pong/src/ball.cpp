/*
  ball.cpp
  Purpose: Simulate a ball bouncing around in the game environment.

  @author Jeremy Elkayam
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "ball.hpp"
#include "constants.hpp"

using namespace std;

//Constructor for the Ball class.
Ball::Ball(double angle, double speed, double xcor, double ycor)
{
  this->angle=angle;
  this->speed=speed;
  this->xcor=xcor;
  this->ycor=ycor;

  //initialize rng
  rng.seed(std::random_device()());
}

//Return the y-component of the ball's velocity in pixels/second.
double Ball::get_x_velocity()
{
  return speed*cos(angle);
}

//Return the y-component of the ball's velocity in pixels/second.
double Ball::get_y_velocity()
{
  return speed*sin(angle);
}

//Sets the coordinates of the ball to what they would be after the
//specified time had elapsed, based on the velocity of the ball.
void Ball::move(double micros_elapsed)
{
  this->xcor+=(get_x_velocity()*micros_elapsed);
  this->ycor+=(get_y_velocity()*micros_elapsed);
}

//Reflects the velocity of the ball over the y-axis.
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

  or let the player turn it on or off.
 */
//Reflects the velocity of the ball over the x-axis, and adds a random amount of perturbation.
void Ball::reflect_x()
{
  angle=-angle;

  //generate a random perturbation in the range of -B_B_P to B_B_P radians
  std::uniform_real_distribution<double>unif(-Constants::BALL_BOUNCE_PERTURBATION,Constants::BALL_BOUNCE_PERTURBATION);

  double perturbation=unif(rng);
  
  //add this perturbation to the reflected angle
  angle+=perturbation;

  //cout << "angle: " << angle << "\n";
}

