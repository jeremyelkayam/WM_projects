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
  
  int get_p1_score(){return this->p1score;}
  int get_p2_score(){return this->p2score;}
  int get_countdown(){return this->countdown;}

  GameState get_current_state(){return this->current_state;}

  void increment_p1_score();
  void increment_p2_score();
  void decrement_countdown(){this->countdown--;}

  double get_x_dimension(){return this->x_dimension;}
  double get_y_dimension(){return this->y_dimension;}
  double get_time_multiplier(){return this->time_multiplier;}

  void new_round();

  double random_angle();

  void set_state(GameState new_state);

  void restart_game();

  void set_time_multiplier(double mult){time_multiplier=mult;};

};

#endif
