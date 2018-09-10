/*
  game.hpp
  Purpose: Store game properties in a singular class for easy access.
 */
#ifndef GAME_HPP
#define GAME_HPP

#include "ball.hpp"

class Game
{
private:
  //Ball ball;
  int p1score;
  int p2score;
  
public:
  Game(double x, double y);
       
  double get_ball_x();
  double get_ball_y();
  
  int get_p1_score(){return this->p1score;}
  int get_p2_score(){return this->p2score;}

};

#endif
