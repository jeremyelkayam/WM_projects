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
  /*Constructor for the Ball class. Sets ball properties to the given values.
    
    @param angle: direction of velocity in radians 
    @param speed: magnitude of velocity in pixels per microsecond
    @param xcor: starting x-coordinate in pixels
    @param ycor: starting y-coordinate in pixels
  */
  Ball(double angle,double speed,double xcor,double ycor);

  /*
    Sets a new magnitude for the ball's velocity.

    @param speed: magnitude of velocity in pixels per microsecond
   */
  void set_speed(double speed){this->speed=speed;}
  
  /*
    Sets a new angle for the ball's velocity.

    @param angle: angle of velocity in radians
   */
  void set_angle(double angle){this->angle=angle;}
  /*
    Sets a new x-coordinate for the ball's position.

    @param xcor: x-coordinate for ball in pixels
   */
  void set_xcor(double xcor){this->xcor=xcor;}
  /*
    Sets a new y-coordinate for the ball's position.

    @param ycor: y-coordinate for ball in pixels
   */
  void set_ycor(double ycor){this->ycor=ycor;}

  /*
    Returns the horizontal, or x-axis component of the ball's velocity.
    A positive value indicates rightward velocity, and a negative value
    indicates leftward velocity.

    @return the x-component of the ball's velocity in pixels per microsecond
   */
  double get_x_velocity();
  /*
    Returns the vertical, or y-axis component of the ball's velocity.
    A positive value indicates downward velocity, and a negative value
    indicates upward velocity.

    @return the y-component of the ball's velocity in pixels per microsecond
   */
  double get_y_velocity();
  /*
    Returns the x-coordinate of the center of the ball in pixels.

    @return the x-coordinate of the ball in pixels
   */
  double get_xcor(){return xcor;}
  /*
    Returns the y-coordinate of the center of the ball in pixels.

    @return the y-coordinate of the ball in pixels
   */
  double get_ycor(){return ycor;}
  /*
    Returns the angle of the velocity of the ball in radians.

    @return the angle of the velocity of the ball in radians
   */
  double get_angle(){return angle;}

  /*
    Sets the coordinates of the ball to what they would be after the
    specified time had elapsed, based on the velocity of the ball.

    @param micros_elapsed The time elapsed in microseconds.
   */
  void move(double micros_elapsed);

  /*
    Reflects the velocity of the ball over the y-axis.
   */
  void reflect_y();
  /*
    Reflects the velocity of the ball over the x-axis, and add or subtracts a random
    amount of perturbation between -Constants::BALL_BOUNCE_PERTURBATION and
    Constants::BALL_BOUNCE_PERTURBATION.
   */
  void reflect_x();
  
};

#endif
