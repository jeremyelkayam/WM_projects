/*
  game.hpp
  Purpose: Store game properties in a singular class for easy access.
 */
#ifndef GAME_HPP
#define GAME_HPP

#include <cmath>
#include "ball.hpp"

class Game
{
private:
  Ball *ball;
  int p1score,p2score;
  double x_dimension,y_dimension;  
  std::mt19937 starting_angle_rng;
  
public:
  Game(double x, double y);

  Ball *get_ball(){return this->ball;}
  
  int get_p1_score(){return this->p1score;}
  int get_p2_score(){return this->p2score;}

  void increment_p1_score();
  void increment_p2_score();

  double get_x_dimension(){return this->x_dimension;}
  double get_y_dimension(){return this->y_dimension;}

  void new_round();
  
};

#endif
