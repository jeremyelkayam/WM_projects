/*
  game.hpp
  Purpose: Store game properties in a singular class for easy access.
 */

//TODO: make this class a singleton.

#ifndef GAME_HPP
#define GAME_HPP

#include <cmath>
#include "ball.hpp"
#include "paddle.hpp"

class Game
{
private:
  Ball *ball;
  Paddle *p1_paddle,*p2_paddle;
  int p1score,p2score;
  double x_dimension,y_dimension;  
  std::mt19937 starting_angle_rng;
  
public:
  Game(double x, double y);

  Ball *get_ball(){return this->ball;}
  Paddle *get_p1_paddle(){return this->p1_paddle;}
  Paddle *get_p2_paddle(){return this->p2_paddle;}
  
  int get_p1_score(){return this->p1score;}
  int get_p2_score(){return this->p2score;}

  void increment_p1_score();
  void increment_p2_score();

  double get_x_dimension(){return this->x_dimension;}
  double get_y_dimension(){return this->y_dimension;}

  void new_round();  
};

#endif
