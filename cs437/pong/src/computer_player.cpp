/*
 *computer_player.cpp 
 *Purpose: Control a paddle without any human input, i.e. a 
 *         computer-controlled opponent for the player to play against.
 *
 *@author Jeremy Elkayam
 */

#include "computer_player.hpp"
#include "paddle.hpp"

ComputerPlayer::ComputerPlayer(Game *game)
{
  this->game=game;
  this->my_paddle=game->get_p1_paddle();//TODO maybe make the AI paddle configurable?
  this->my_paddle->set_speed(.003);
}

void ComputerPlayer::update(int micros_elapsed)
{
  Paddle::Direction dir;
  double ball_ycor = game->get_ball()->get_ycor();

  if(ball_ycor>my_paddle->get_ycor()+40)
    {
      dir = Paddle::Direction::Down;
    }
  else
    {
      dir = Paddle::Direction::Up;
    }

  my_paddle->move(micros_elapsed,dir);

}
