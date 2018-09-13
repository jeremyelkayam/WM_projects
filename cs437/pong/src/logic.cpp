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
  double screen_edge;
  if(ball_above_screen() || ball_below_screen())
    {
      if(ball_above_screen())
	{
	  screen_edge=0;
	}
      else if(ball_below_screen())
	{
	  screen_edge=game->get_y_dimension();
	}
      
      /*
	set ball to being exactly on the screen's edge, to prevent ball being too
	far offscreen and causing unnecessary calls to reflect_x().
       */
      this->game->get_ball()->set_ycor(screen_edge);
      
      this->game->get_ball()->reflect_x();
    }
  if(ball_past_left_side() || ball_past_right_side())
    {
      if(ball_past_left_side())
	{
	  game->increment_p2_score();
	  screen_edge=0;
	}
      
      else if (ball_past_right_side())
	{
	  game->increment_p1_score();
	  screen_edge=game->get_x_dimension();
	}
      game->new_round();
    }

  this->game->get_ball()->move(micros_elapsed);

  
}

bool Logic::ball_above_screen()
{
  return ball_y()<0;
}

bool Logic::ball_below_screen()
{
  return ball_y()>game->get_y_dimension();
}


bool Logic::ball_past_left_side()
{
  return ball_x()<0;
}

bool Logic::ball_past_right_side()
{
  return ball_x()>game->get_x_dimension();
}
