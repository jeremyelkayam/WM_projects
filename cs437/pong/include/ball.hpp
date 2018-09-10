#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>


class Ball
{
private:
  /*
   *
   */
  double angle,speed,xcor,ycor,cached_xvelocity,cached_yvelocity;
  
  /* Boolean to keep track of whether or not the angle was changed since cached_xvelocity
   * and cached_yvelocity were last calculated.
   */
  bool angle_changed;

  double get_x_velocity();
  double get_y_velocity();

public:
  //Constructor to set ball's fields when a new round is initiated.
  Ball(double angle,double speed,double xcor,double ycor);

  //Delete the ball
  void kill();

  //possibly add time as a param for this?
  void move();

  
};

#endif
