/*
  logic.hpp
  Purpose: 

  @author Jeremy Elkayam
 */
#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "game.hpp"

class Logic
{
private:
  Game *game;
  bool ball_above_below_screen();
  //Shortcut for getting the ball's x-coordinate.
  double ball_x(){return this->game->get_ball()->get_xcor();}
  //Shortcut for getting the ball's y-coordinate.
  double ball_y(){return this->game->get_ball()->get_ycor();}
public:
  Logic(Game *game);
  void update(int micros_elapsed);
};

#endif
