/*
 *computer_player.hpp
 *Purpose: Control a paddle without any human input, i.e. a 
 *         computer-controlled opponent for the player to play against.
 *
 *@author Jeremy Elkayam
 */

#ifndef COMP_PLAY_HPP
#define COMP_PLAY_HPP

#include "game.hpp"

class ComputerPlayer
{
private:
  enum class ActionType{ Moving , Waiting, None };
  Game *game;
  Paddle *my_paddle;

  double next_target;
  int wait_until,time_waiting;
  ActionType current_action;
  std::mt19937 target_perturbation_rng,wait_time_rng;

  void set_target_to_nearby_ball_target(double ball_target);
  void set_target_to_random_target();
  void start_waiting_for_random_time();
  
  void move_toward_target(int micros_elapsed);
  void continue_waiting(int micros_elapsed);
  
public:
  ComputerPlayer(Game *game);
  void update(int micros_elapsed);
};

#endif
