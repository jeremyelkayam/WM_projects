/*
  logic.cpp
  Purpose:

  @author Jeremy Elkayam
 */

#include "logic.hpp"

Logic::Logic(Game *game)
{
  this->game=game;
}

void Logic::update(int ms_elapsed)
{
  if(ball_above_below_screen())
    {
      
    }
}
bool Logic::ball_above_below_screen()
{
  return (ball_y()<0 || ball_y()>game->get_y_dimension());
}
