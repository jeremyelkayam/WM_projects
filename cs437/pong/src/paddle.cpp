/*
  paddle.cpp
  Purpose:

  @author Jeremy Elkayam
  */
#include "paddle.hpp"

Paddle::Paddle(double speed, double accel, double ycor, double height)
{
  set_speed(speed);
  set_accel(accel);
  set_ycor(ycor);
  set_height(height);
}

void Paddle::move(double micros_elapsed, Direction dir)
{
  int multiplier;
  if(dir==Direction::Up)
    {
      multiplier=-1;
    }
  else
    {
      multiplier=1;
    }
  
  
  double delta_y=this->speed*micros_elapsed*multiplier;

  this->ycor+=delta_y;
}
