/*
  paddle.cpp
  Purpose:

  @author Jeremy Elkayam
  */
#include "paddle.hpp"

Paddle::Paddle(double speed, double accel, double ycor)
{
  set_speed(speed);
  set_accel(accel);
  set_ycor(ycor);
}
