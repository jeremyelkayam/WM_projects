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
  Game *game;
  Paddle *my_paddle;
  
public:
  ComputerPlayer(Game *game);
  void update(int micros_elapsed);
};

#endif
