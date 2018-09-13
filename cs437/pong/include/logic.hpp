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
  bool ball_past_left_side();
  bool ball_past_right_side();
  bool ball_above_screen();
  bool ball_below_screen();
  bool ball_hit_paddle();
  //Shortcut for getting the ball's x-coordinate.
  double ball_x(){return this->game->get_ball()->get_xcor();}
  //Shortcut for getting the ball's y-coordinate.
  double ball_y(){return this->game->get_ball()->get_ycor();}
  void top_bottom_bounce();
  void player_score_point(bool player_one_scored);
  void start_new_round();
public:
  Logic(Game *game);
  void update(int micros_elapsed);
};

#endif
