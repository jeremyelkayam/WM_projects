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
#include "menu.hpp"

enum class GameState {NewRound, Playing, CountDown, EndScreen, Paused,
		      MainMenu, AboutScreen, Settings};

class Game
{
private:
  Ball *ball;
  Paddle *p1_paddle,*p2_paddle;
  Menu *menu;
  int p1score,p2score;
  double x_dimension,y_dimension;
  std::mt19937 starting_angle_rng;
  GameState current_state;
  int countdown;
  double time_multiplier=1;
public:
  
  Game(double x, double y,GameState state);

  Ball *get_ball(){return this->ball;}
  Paddle *get_p1_paddle(){return this->p1_paddle;}
  Paddle *get_p2_paddle(){return this->p2_paddle;}
  Menu *get_menu(){return this->menu;}
  
  int get_p1_score(){return this->p1score;}
  int get_p2_score(){return this->p2score;}
  int get_countdown(){return this->countdown;}

  GameState get_current_state(){return this->current_state;}

  void increment_p1_score();
  void increment_p2_score();
  void decrement_countdown(){this->countdown--;}

  double get_x_dimension(){return this->x_dimension;}
  double get_y_dimension(){return this->y_dimension;}
  double get_time_multiplier(){return this->time_multiplier;}

  void new_round();

  double random_angle();

  void set_state(GameState new_state);

  void restart_game();

  void set_time_multiplier(double mult){time_multiplier=mult;};

};

#endif
