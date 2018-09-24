/*
 *computer_player.cpp 
 *Purpose: Control a paddle without any human input, i.e. a 
 *         computer-controlled opponent for the player to play against.
 *
 *@author Jeremy Elkayam
 */
 
#include <cstdlib>
#include <cmath>
#include <cassert>
#include "computer_player.hpp"
#include "paddle.hpp"
#include "constants.hpp"

// Constructor for the ComputerPlayer class.
ComputerPlayer::ComputerPlayer(AIView *view)
{
  srand(time(0));
  this->view=view;
  this->my_paddle=view->get_p1_paddle();//TODO maybe make the AI paddle configurable?
  this->my_paddle->set_speed(Constants::COMPUTER_PLAYER_SPEED);
  
  this->next_target=0;
  this->wait_until=0;
  this->time_waiting=0;
  this->current_action=ActionType::None;

  target_perturbation_rng.seed(std::random_device()());
  wait_time_rng.seed(std::random_device()());
  target_rng.seed(std::random_device()());
}

//Loop code for the AI. Decides what to do and tells the paddle to do it.
void ComputerPlayer::update(int micros_elapsed)
{
  if(current_action==ActionType::Moving)
    {
      move_toward_target(micros_elapsed);
    }
  else if(current_action==ActionType::Waiting)
    {
      continue_waiting(micros_elapsed);
    }
  else
    {
      pick_random_thing_to_do();
      //if the following if statements trigger, they'll override the random thing we chose.

      //if the AI decided to wait, we should wait. if it decided to move, we should correct
      //its movement to be toward where the ball's going to go.
      
      // if the x component of the velocity is less than 0, it's heading left
      if(current_action==ActionType::Moving && view->ball_x_velocity()<0) 
	{
	  double where_ball_will_hit=(view->ball_ycor()-
				      view->ball_xcor()*tan(view->ball_angle()));
	  //if the ball is going to hit the screen between 0 and the window height
	  //cout << "ball will hit: " << where_ball_will_hit << "\n";
	  if(0 < where_ball_will_hit - 100 && where_ball_will_hit < Constants::DEFAULT_WINDOW_HEIGHT + 100)
	    {
	      //cout << "determining where to move\n";
	      
	      set_target_to_nearby_this_target(where_ball_will_hit);
	    }
	}
    }
}

//Sets target to the given target, but with a random perturbation.
void ComputerPlayer::set_target_to_nearby_this_target(double target)
{
  double perturbation_bound=my_paddle->get_height() * Constants::AIM_PERTURBATION_BOUND_MULTIPLIER;
  std::uniform_real_distribution<double>unif(-perturbation_bound, perturbation_bound);
  
  double perturbation=unif(target_perturbation_rng);
  
  next_target= target + perturbation;
  
  
  //if the target is too close to either edge, it'll never line up with the center of the paddle.
  //it'll get stuck moving forever.
  if(next_target < (my_paddle->get_height() / 2))
    {
      next_target = my_paddle->get_height() / 2;
    }
  if(next_target > (Constants::DEFAULT_WINDOW_HEIGHT - (my_paddle->get_height() / 2)))
    {
      next_target = Constants::DEFAULT_WINDOW_HEIGHT - (my_paddle->get_height() / 2);
    }
  current_action=ActionType::Moving;
}   

//Sets action to Waiting and sets a random time for the AI to wait.
void ComputerPlayer::start_waiting_for_random_time()
{
  assert(current_action==ActionType::None);
  
  std::uniform_int_distribution<int>unif(Constants::MIN_WAITING_TIME,Constants::MAX_WAITING_TIME);
  wait_until=unif(wait_time_rng);
  current_action=ActionType::Waiting;
}

//If the AI is waiting, keep waiting, and if the wait is over, clear its current action.
void ComputerPlayer::continue_waiting(int micros_elapsed)
{
  //this need only be called if the game state is waiting.
  assert(current_action==ActionType::Waiting);
  
  time_waiting+=micros_elapsed;
  if(time_waiting >= wait_until)
    {
      time_waiting=0;
      current_action=ActionType::None;
    }
}

//If the AI has nothing to do, set it to moving and its next_target to a random ycor.
void ComputerPlayer::set_target_to_random_target()
{
  assert(current_action==ActionType::None);
  
  std::uniform_real_distribution<double>unif(my_paddle->get_height() / 2,
					     Constants::DEFAULT_WINDOW_HEIGHT - (my_paddle->get_height() / 2));
  next_target=unif(target_rng);

  current_action=ActionType::Moving;
}

//Decide to either wait a random amount of time or move somewhere random.
void ComputerPlayer::pick_random_thing_to_do()
{
  //this only needs to ever be called if the AI doesn't have
  //anything it's currently doing
  assert(current_action==ActionType::None);
  
  if(rand() % 2)
    {
      start_waiting_for_random_time();
    }
  else
    {
      set_target_to_random_target();
    }
}

//If moving, move toward the next target. If you're there, stop.
void ComputerPlayer::move_toward_target(int micros_elapsed)
{
  //this only ever be called if we're currently moving. if not, we have big problems 
  assert(current_action==ActionType::Moving);
  
  if(my_paddle->get_center() > (next_target - .5) && my_paddle->get_center() < (next_target + .5))
    {
      //we're within half a pixel of the goal. it's ok to stop
      current_action=ActionType::None;
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
