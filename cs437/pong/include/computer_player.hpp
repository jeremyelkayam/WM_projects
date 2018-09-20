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
  int wait_time;
  ActionType current_action;
  std::mt19937 target_perturbation_rng;
  
public:
  ComputerPlayer(Game *game);
  void update(int micros_elapsed);
};

#endif
