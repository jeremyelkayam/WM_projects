/*
  game.hpp
  Purpose: Store all game properties in a singular class for easy access
  by any class that needs them.
 */

#include "game.hpp"
#include "ball.hpp"

Game::Game(double x,double y)
{
  this->ball=new Ball(1.0,.1,x/2,y/2);
  this->p1score=0;
  this->p2score=0;
}

double Game::get_ball_x()
{
  return ball->get_xcor();
}

double Game::get_ball_y()
{
  return ball->get_ycor();
}
