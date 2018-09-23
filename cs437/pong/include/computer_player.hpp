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
  /*
    Denotes what the paddle is currently doing.

    Moving: the AI's paddle is traveling toward its determined target location.
    Waiting: the AI's paddle is in the middle of waiting for a predetermined 
             amount of time.
    None: the AI's paddle does not have a current action, and the AI will need to make a decision
          as to what it wants to do.
   */
  enum class ActionType{ Moving , Waiting, None };
  
  // A reference to the stored properties of the game logic.
  Game *game;
  
  // A reference to the paddle being controlled by the AI.
  Paddle *my_paddle;
  
  /*
    If the AI's paddle is currently moving, this stores the
    y-coordinate of the location it is moving towards.
   */
  double next_target;
  
  /*
    If the AI is waiting, these store properties of the current wait operation.
    
    wait_until: the total time the AI intends to wait for
    time_waiting: the time that has passed since the AI started waiting.
   */
  int wait_until,time_waiting;
  
  //Stores the paddle's current action. Types of actions documented above.
  ActionType current_action;

  /*
    Random number generators.
    
    target_perturbation_rng: Generates the random perturbation when the
                             AI aims its paddle for the ball's predicted
			     location, effectively allowing the paddle to
			     occasionally overshoot or undershoot its 
			     target.
    wait_time_rng: Generates the amount of time that the AI waits when it decides 
                   to begin waiting.
    target_rng: When the AI decides to move to a random location, this generates
                the y-coordinate of the location it moves toward.
   */
  std::mt19937 target_perturbation_rng,wait_time_rng,target_rng;

  /*
    Sets the AI's current action to Moving, and sets next_target to
    a y-coordinate close to (but not necessarily equal to) the value
    given. The target is modified by adding a random value between
    the height of the paddle times
    Constants::AIM_PERTURBATION_BOUND_MULTIPLIER and its negation.
    This method is used when the AI predicts where a ball will hit
    its side and aims for that location. The perturbation leaves
    an opportunity for the AI to miss its target.

    @param target The y-coordinate of the location the paddle should
                  move towards.
   */
  void set_target_to_nearby_this_target(double target);
  /*
    Sets the AI's current action to Moving, and sets its next_target
    to a random y-coordinate on the screen. 
   */
  void set_target_to_random_target();
  /*
    Sets the AI's current action to Waiting, and generates a random
    amount of time between Constants::MIN_WAITING_TIME and 
    Constants::MAX_WAITING_TIME that it will wait for.
   */
  void start_waiting_for_random_time();

  /*
    If the paddle is 
   */
  void move_toward_target(int micros_elapsed);
  void continue_waiting(int micros_elapsed);
  void pick_random_thing_to_do();
  
public:
  ComputerPlayer(Game *game);
  void update(int micros_elapsed);
};

#endif
