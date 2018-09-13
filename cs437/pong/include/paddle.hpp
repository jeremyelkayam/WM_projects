/*
  paddle.hpp
  Purpose:

  @author Jeremy Elkayam
  */
#ifndef PADDLE_HPP
#define PADDLE_HPP


class Paddle
{
private:
  double speed,accel,ycor,height;

public:
  enum class Direction { Up, Down };
  
  Paddle(double speed, double accel, double ycor, double height);

  void set_speed(double speed){this->speed=speed;}
  void set_accel(double accel){this->accel=accel;}
  void set_ycor(double ycor){this->ycor=ycor;}
  void set_height(double height){this->height=height;}

  double get_ycor(){return this->ycor;}
  double get_height(){return this->height;}

  void move(double micros_elapsed, Direction dir);
  
};

#endif
