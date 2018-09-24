/*
 *computer_player.hpp
 *Purpose: Control a paddle without any human input, i.e. a 
 *         computer-controlled opponent for the player to play against.
 *
 *@author Jeremy Elkayam
 */

#ifndef COMP_PLAY_HPP
#define COMP_PLAY_HPP

#include "ai_view.hpp"

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
  
  // A reference to the ai's view of the game.
  AIView *view;
  
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
    If the paddle is moving, move it towards its next target by
    using the built-in move(int micros_elapsed) function of the
    paddle. This should only ever be called if the paddle is
    in the Moving state. If the paddle has reached its target,
    this sets its state to None.

    @param micros_elapsed The amount of time in microseconds 
                          since the end of the previous game loop.
   */
  void move_toward_target(int micros_elapsed);
  /*
    If the AI is waiting, continue to wait for the
    amount of microseconds specified. If the alloted waiting
    time is over, set the state to None. Like the above 
    method, this should only ever be called if the paddle
    is waiting.

    @param micros_elapsed The amount of time in microseconds 
                          since the end of the previous game loop.
   */
  void continue_waiting(int micros_elapsed);
  /*
    If the AI isn't doing anything, this will randomly decide
    to either wait for a random amount of time between 
    Constants::MIN_WAITING_TIME and Constants::MAX_WAITING_TIME,
    or start moving toward a random y-coordinate on the screen.
   */
  void pick_random_thing_to_do();
  
public:
  /*
    Constructor for the ComputerPlayer class. Stores a reference
    to the game properties and begins controlling the P1 paddle.

    @param game A reference to the class storing the game's properties.
   */
  ComputerPlayer(AIView *view);

  /*
    Called once every game loop. Makes a decision for what the AI's paddle
    should do next-- either continuing its current action, or, if its
    current action is finished, deciding on a new action. Once a decision
    is made, the AI tells the paddle to behave accordingly.
    
    @param micros_elapsed The amount of time elapsed since the
                          previous game loop.
   */
  void update(int micros_elapsed);
};

#endif
