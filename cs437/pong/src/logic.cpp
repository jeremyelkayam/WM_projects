/*
  logic.cpp
  Purpose:

  @author Jeremy Elkayam
 */

#include <iostream>
#include "logic.hpp"

using namespace std;

Logic::Logic(Game *game)
{
  this->game=game;
}

void Logic::update(int micros_elapsed)
{
  if(ball_above_below_screen())
    {
      this->game->get_ball()->reflect_y();
    }
  //cout << ms_elapsed;
  this->game->get_ball()->move(micros_elapsed);
}
bool Logic::ball_above_below_screen()
{
  return (ball_y()<0 || ball_y()>game->get_y_dimension());
}
