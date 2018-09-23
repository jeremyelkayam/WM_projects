/*
  game.hpp
  Purpose: Store game logic properties in a singular class for easy access.
 */

//potential TODO: make this class a singleton?

#ifndef GAME_HPP
#define GAME_HPP

#include <cmath>
#include "ball.hpp"
#include "paddle.hpp"
#include "menu.hpp"

/*
  The current state of the game.
  NewRound: The game has just started a new round and is waiting
            for confirmation from the player to begin the round
  CountDown: The round is about to start, and the game is 
             performing a 3-second countdown before gameplay
	     begins.
  Playing: A round of gameplay is in progress. The ball is bouncing
           around the screen and players are moving paddles to 
	   attempt to score.
  EndScreen: The game is over. The end-screen menu is being displayed,
             and the player who won is indicated. 
  Paused: The game is in progress, but has been paused by a player.
          Gameplay is stopped, but the player can choose options from 
	  the pause menu.
  Main Menu: The main menu is being displayed. No gameplay is taking
             place.
  AboutScreen: The about screen is being displayed.
  Settings: The settings menu is being displayed. No gameplay is taking
            place.
 */
enum class GameState {NewRound, Playing, CountDown, EndScreen, Paused,
		      MainMenu, AboutScreen, Settings};

class Game
{
private:
  //A reference to the game's ball.
  Ball *ball;
  //References to the 2 paddles.
  Paddle *p1_paddle,*p2_paddle;
  //Reference to the current menu being displayed (if in a menu state).
  Menu *menu;
  //These store the scores of each player.
  int p1score,p2score;
  //Dimensions of the playing area.
  double x_dimension,y_dimension;
  /*
    Random number generateor, generating the
    angle the ball's velocity starts at
    when a round begins.
  */
  std::mt19937 starting_angle_rng;
  //Stores the game's current state as documented above.
  GameState current_state;
  //Store's the position in the countdown (if counting down).
  int countdown;
  //Stores the multiplier on game speed. Defaults to 1.
  double time_multiplier=1;
public:
  /*
    Constructor, setting up the game's properties.
  
    @param x: the x-dimension of the starting window
    @param y: the y-dimension of the starting window
    @param state: the starting state of the game
   */
  Game(double x, double y,GameState state);

  /*
    Destructor, de-allocating all heap memory the
    class used during its life.
   */
  ~Game();

  /*
    Returns a reference to the game's ball.
    
    @return a reference to the ball stored by the game.
  */
  Ball *get_ball(){return this->ball;}
  /*
    Returns a reference to the player one's paddle.
    
    @return a reference to the P1 paddle stored by the game.
  */
  Paddle *get_p1_paddle(){return this->p1_paddle;}
  /*
    Returns a reference to player two's paddle.
    
    @return a reference to the P2 paddle stored by the game.
  */
  Paddle *get_p2_paddle(){return this->p2_paddle;}
  /*
    If game is in a menu state, return a reference to the current game menu.
    
    @return a reference to the current menu.
  */
  Menu *get_menu();

  /*
    Return player 1's stored score.

    @return the score accumulated by player 1 in total points.
   */
  int get_p1_score(){return this->p1score;}
  /*
    Return player 2's stored score.

    @return the score accumulated by player 2 in total points.
   */
  int get_p2_score(){return this->p2score;}
  /*
    Return the number in the countdown.

    @return the current number in the countdown.
   */
  int get_countdown();

  /*
    Return the game's current state.

    @return the current state of the game.
   */
  GameState get_current_state(){return this->current_state;}

  /*
    Increment player 1's score by one. If the score reaches the
    number of points required to win, end the game.
   */
  void increment_p1_score();
  /*
    Increment player 2's score by one. If the score reaches the
    number of points required to win, end the game.
   */
  void increment_p2_score();
  /*
    Decrements the countdown by one. If the countdown reaches 0,
    gameplay starts.
   */
  void decrement_countdown(){this->countdown--;}

  /*
    Return the initial x-dimension of the game window.

    @return the x-dimension of the window in which the game started
   */
  double get_x_dimension(){return this->x_dimension;}
  /*
    Return the initial y-dimension of the game window.

    @return the y-dimension of the window in which the game started
   */
  double get_y_dimension(){return this->y_dimension;}
  /*
    Return the multiplier on game time as set by the settings menu.

    @return the multiplier on game time
   */
  double get_time_multiplier(){return this->time_multiplier;}

  /*
    Begin a new round, resetting the ball's angle and the positions
    for ball and paddles. Sets game state accordingly and prompts
    player for input.
   */
  void new_round();

  /*
    Generates a random angle between Constants::BALL_MIN_ANGLE
    and Constants::BALL_MAX_ANGLE, and rotates it randomly into
    one of the four quadrants.

    @return an angle in radians between Constants::BALL_MIN_ANGLE and Constants::BALL_MAX_ANGLE, in a random quadrant.
   */
  double random_angle();

  /*
    Sets game state to the specified state. If this is a menu
    state, also sets up the corresponding menu.
    
    @param new_state The new state for the game to use.
   */
  void set_state(GameState new_state);

  /*
    Starts a new game with scores at 0 and gameplay in
    its initial state.
   */
  void restart_game();

  /*
    Sets the game's time multiplier to the specified value.

    @param mult The new multiplier on game time.
   */
  void set_time_multiplier(double mult){time_multiplier=mult;};

};

#endif
