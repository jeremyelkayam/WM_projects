/*
  paddle.cpp
  Purpose:

  @author Jeremy Elkayam
  */
#include <iostream>
#include "paddle.hpp"
#include "game.hpp"

using namespace std;

Paddle::Paddle(double speed, double accel, double ycor, double height, double max_ycor)
{
  set_speed(speed);
  set_accel(accel);
  set_ycor(ycor);
  set_height(height);
  this->max_ycor=max_ycor;
}

void Paddle::move(int micros_elapsed, Direction dir)
{
  //cout << "speed: " << speed << "\n";
  if(((ycor > 0 && dir==Direction::Up) || (ycor < max_ycor-height && dir==Direction::Down )))
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
}

double Paddle::get_center()
{
  return get_ycor()+(get_height()/2);
}
