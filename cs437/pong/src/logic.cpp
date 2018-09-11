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
  
  this->game->get_ball()->move(micros_elapsed);

  //cout << "y velocity" << this->game->get_ball()->get_y_velocity() << "\n";
  
  if(ball_above_below_screen())
    {
      this->game->get_ball()->reflect_x();
      
      //cout << ball_y() << "\n";
    }
  //cout << ms_elapsed;
}
bool Logic::ball_above_below_screen()
{
  return (ball_y()<0 || ball_y()>game->get_y_dimension());
}
