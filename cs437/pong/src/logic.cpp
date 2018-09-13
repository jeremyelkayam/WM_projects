/*
  logic.cpp
  Purpose:

  @author Jeremy Elkayam
 */

#include <iostream>
#include "logic.hpp"
#include "paddle.hpp"

using namespace std;

Logic::Logic(Game *game)
{
  this->game=game;
}

void Logic::update(int micros_elapsed)
{
  if(ball_above_screen() || ball_below_screen())
    {
      top_bottom_bounce();
    }
  
  if(ball_past_left_side() || ball_past_right_side())
    {
      /*goal:
	if(hit_paddle())
	{
	bounce_off_paddle();
	}
	else
	{
	player_score(ball_past_right_side());
	check_for_win(); // maybe not this
	start_new_round();
	}
	
       */
      cout << "did ball hit paddle?: " << ball_hit_paddle() << "\n";
      player_score_point(ball_past_right_side());
      start_new_round();
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

void Logic::top_bottom_bounce()
{
  double screen_edge;
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


void Logic::player_score_point(bool player_one_scored)
{
  if(player_one_scored)
    {
      game->increment_p1_score();
    }
  else
    {
      game->increment_p2_score();
    }
}

void Logic::start_new_round()
{
  game->new_round();
}

bool Logic::ball_hit_paddle()
{
  if(ball_past_left_side() || ball_past_right_side())
    {
      double ball_ycor=game->get_ball()->get_ycor();
      Paddle *paddle;
      if(ball_past_left_side())
	{
	  paddle=game->get_p1_paddle();
	}
      if(ball_past_right_side())
	{
	  paddle=game->get_p2_paddle();
	}
      return (ball_ycor>paddle->get_ycor() &&
	      ball_ycor<paddle->get_ycor()+paddle->get_height());
    }
  return false;
}
