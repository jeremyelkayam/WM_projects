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

public:
  //Constructor to set ball's fields when a new round is initiated.
  Ball(double angle,double speed,double xcor,double ycor);

  void set_speed(double speed){this->speed=speed;};
  void set_angle(double angle);
  

  double get_x_velocity();
  double get_y_velocity();
  double get_xcor(){return xcor;}
  double get_ycor(){return ycor;}

  //Delete the ball
  //void kill();

  
  void move(double ms_elapsed);

  void reflect_y();
  void reflect_x();
  
};

#endif
