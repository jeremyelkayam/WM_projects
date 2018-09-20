/*
 *computer_player.cpp 
 *Purpose: Control a paddle without any human input, i.e. a 
 *         computer-controlled opponent for the player to play against.
 *
 *@author Jeremy Elkayam
 */
 
#include <cstdlib>
#include <cmath>
#include "computer_player.hpp"
#include "paddle.hpp"
#include "constants.hpp"

ComputerPlayer::ComputerPlayer(Game *game)
{
  srand(time(0));
  this->game=game;
  this->my_paddle=game->get_p1_paddle();//TODO maybe make the AI paddle configurable?
  this->my_paddle->set_speed(Constants::COMPUTER_PLAYER_SPEED);
  
  this->next_target=0;
  this->wait_time=0;
  this->current_action=ActionType::None;

  target_perturbation_rng.seed(std::random_device()());
}

void ComputerPlayer::update(int micros_elapsed)
{
  //cout << "current_action is none? " << to_string(current_action==ActionType::None) << "\n"; 
  if(!(current_action==ActionType::None))
    {
      //cout << "doing something\n";
      if(current_action==ActionType::Moving)
	{
	  if(my_paddle->get_center() > (next_target - .5) && my_paddle->get_center() < (next_target + .5))
	    {
	      //we're within half a pixel of the goal. it's ok to stop
	      current_action=ActionType::Waiting;
	    }
	  else
	    {
	      if(my_paddle->get_center() > next_target)
		{
		  my_paddle->move(micros_elapsed, Paddle::Direction::Up);
		}
	      else
		{
		  my_paddle->move(micros_elapsed, Paddle::Direction::Down);
		}
	    }
	}
    }
  else
    {
      // if the x component of the velocity is less than 0, it's heading left
      if(game->get_ball()->get_x_velocity()<0) 
	{
	  double where_ball_will_hit=(game->get_ball()->get_ycor()-
				   game->get_ball()->get_xcor()*tan(game->get_ball()->get_angle()));
	  //if the ball is going to hit the screen between 0 and the window height
	  //cout << "ball will hit: " << where_ball_will_hit << "\n";
	  if(0 < where_ball_will_hit && where_ball_will_hit < 600)
	    {
	      //cout << "determining where to move\n";

	      std::uniform_real_distribution<double>unif(-1.5*my_paddle->get_height(),1.5*my_paddle->get_height());
	      
	      double perturbation=unif(target_perturbation_rng);
	      
	      next_target=where_ball_will_hit+perturbation;
	      current_action=ActionType::Moving;
	    }
	}
    }
  
  /*plan:
    if(doing_nothing)
      if(ball_moving_toward_my_side)
        move_to_where_it_will_hit()
      else
        if(rand()%2)
	  wait(random_time_less_than_1_second)
        else
	  move_to_random_place()
   */
  
  /*
  Paddle::Direction dir;
  double ball_ycor = game->get_ball()->get_ycor();

  if(ball_ycor>my_paddle->get_ycor()+my_paddle->get_height()/2)
    {
      dir = Paddle::Direction::Down;
    }
  else
    {
      dir = Paddle::Direction::Up;
    }

  my_paddle->move(micros_elapsed,dir);
  */
}
