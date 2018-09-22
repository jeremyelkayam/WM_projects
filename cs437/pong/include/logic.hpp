/*
  logic.hpp
  Purpose: Handle the logic computations of the game's main loop
           (e.g. controls, collison detection, etc).

  @author Jeremy Elkayam
 */
#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "computer_player.hpp"

class Logic
{
private:
  Game *game;
  ComputerPlayer *cp;
  int total_time;
  double time_multiplier=1;
  int speed_index=2;
  
  bool ball_past_left_side();
  bool ball_past_right_side();
  bool ball_above_screen();
  bool ball_below_screen();
  bool ball_hit_p1_paddle();
  bool ball_hit_p2_paddle();

  //Shortcut for getting the ball's x-coordinate.
  double ball_x(){return this->game->get_ball()->get_xcor();}
  //Shortcut for getting the ball's y-coordinate.
  double ball_y(){return this->game->get_ball()->get_ycor();}

  void top_bottom_bounce();
  void left_right_bounce();
  void player_score_point(bool player_one_scored);
  void start_new_round();
  void keyboard_paddle_movement(int micros_elapsed);
public:
  Logic(Game *game);
  void update(int micros_elapsed);

  void handle_menu_event(sf::Event event, sf::RenderWindow *App);
};

#endif
