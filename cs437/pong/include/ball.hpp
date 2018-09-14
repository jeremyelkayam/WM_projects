/*
  ball.cpp
  Purpose: Simulate a ball bouncing around in the game environment.

  @author Jeremy Elkayam
 */
#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <random>

class Ball
{
private:
  /*angle: angle of the ball's velocity in radians
   *speed: magnitude of the ball's velocity in pixels per microsecond
   *xcor: x-coordinate of the ball in pixels
   *ycor: y-coordinate of the ball in pixels
   */
  double angle,speed,xcor,ycor;

  //random number generator for generating perturbations when the ball is reflected
  std::mt19937 rng;

public:
  //Constructor to set ball's fields when a new round is initiated.
  Ball(double angle,double speed,double xcor,double ycor);

  /*Sets a new magnitude for the ball's velocity.
   *@param speed
   */
  void set_speed(double speed){this->speed=speed;}
  void set_angle(double angle){this->angle=angle;}
  void set_xcor(double xcor){this->xcor=xcor;}
  void set_ycor(double ycor){this->ycor=ycor;}
  
  double get_x_velocity();
  double get_y_velocity();
  double get_xcor(){return xcor;}
  double get_ycor(){return ycor;}
  
  void move(double ms_elapsed);

  void reflect_y();
  void reflect_x();
  
};

#endif
