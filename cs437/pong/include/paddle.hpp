/*
  paddle.hpp
  Purpose:

  @author Jeremy Elkayam
  */
#ifndef GAME_HPP
#define GAME_HPP

class Paddle
{
private:
  double speed,accel,ycor;

public:
  Paddle(double speed, double accel, double ycor);

  void set_speed(double speed){this->speed=speed;}
  void set_accel(double accel){this->accel=accel;}
  void set_ycor(double ycor){this->ycor=ycor;}

  void move(double ms_elapsed);
  
};

#endif
