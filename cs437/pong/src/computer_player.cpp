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
  this->wait_until=0;
  this->time_waiting=0;
  this->current_action=ActionType::None;

  target_perturbation_rng.seed(std::random_device()());
  wait_time_rng.seed(std::random_device()());
  target_rng.seed(std::random_device()());
}

void ComputerPlayer::update(int micros_elapsed)
{
  if(current_action==ActionType::Moving)
    {
      if(my_paddle->get_center() > (next_target - .5) && my_paddle->get_center() < (next_target + .5))
	{
	  //we're within half a pixel of the goal. it's ok to stop
	  start_waiting_for_random_time();
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
  else if(current_action==ActionType::Waiting)
    {
      continue_waiting(micros_elapsed);
      if(time_waiting >= wait_until)
	{
	  time_waiting=0;
	  current_action=ActionType::None;
	}
    }
  else
    {
      pick_random_thing_to_do();
      //if the following if statements trigger, they'll override the random thing we chose.
      
      // if the x component of the velocity is less than 0, it's heading left
      if(game->get_ball()->get_x_velocity()<0) 
	{
	  double where_ball_will_hit=(game->get_ball()->get_ycor()-
				      game->get_ball()->get_xcor()*tan(game->get_ball()->get_angle()));
	  //if the ball is going to hit the screen between 0 and the window height
	  //cout << "ball will hit: " << where_ball_will_hit << "\n";
	  if(0 < where_ball_will_hit && where_ball_will_hit < game->get_y_dimension())
	    {
	      //cout << "determining where to move\n";
	      
	      set_target_to_nearby_ball_target(where_ball_will_hit);
	      
	      current_action=ActionType::Moving;
	    }
	}
    }
}
  
void ComputerPlayer::set_target_to_nearby_ball_target(double ball_target)
{
  double perturbation_bound=my_paddle->get_height() * Constants::AIM_PERTURBATION_BOUND_MULTIPLIER;
  std::uniform_real_distribution<double>unif(-perturbation_bound, perturbation_bound);
  
  double perturbation=unif(target_perturbation_rng);
  
  next_target= ball_target + perturbation;
  
  
  //if the target is too close to either edge, it'll never line up with the center of the paddle.
  //it'll get stuck moving forever.
  if(next_target < (my_paddle->get_height() / 2))
    {
      next_target = my_paddle->get_height() / 2;
    }
  if(next_target > (game->get_y_dimension() - (my_paddle->get_height() / 2)))
    {
      next_target = game->get_y_dimension() - (my_paddle->get_height() / 2);
    }
}   
    
void ComputerPlayer::start_waiting_for_random_time()
{
  std::uniform_int_distribution<int>unif(Constants::MIN_WAITING_TIME,Constants::MAX_WAITING_TIME);
  wait_until=unif(wait_time_rng);
  current_action=ActionType::Waiting;
}

void ComputerPlayer::continue_waiting(int micros_elapsed)
{
  time_waiting+=micros_elapsed;
}

void ComputerPlayer::set_target_to_random_target()
{
  std::uniform_real_distribution<double>unif(my_paddle->get_height() / 2,
					     game->get_y_dimension() - (my_paddle->get_height() / 2));
  next_target=unif(target_rng);

  current_action=ActionType::Moving;
}

void ComputerPlayer::pick_random_thing_to_do()
{
  if(rand() % 2)
    {
      start_waiting_for_random_time();
    }
  else
    {
      set_target_to_random_target();
    }
}
