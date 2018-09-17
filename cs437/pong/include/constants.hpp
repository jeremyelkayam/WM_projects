/*
  Constants.hpp
  Purpose: Consolidate all game constants/strings into a single class as static variables
  for easy editing across classes.
  
  @author Jeremy Elkayam
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <cmath>

using namespace std;

class Constants
{
public:

  // Initialize all string constants to their intended values.
  static void init_strings();

  //Game values

  /*
    The amount of points required to win the game.
   */
  static constexpr int WIN_SCORE = 11;
  /*
    The starting value for the countdown at the beginning of each round.
   */
  static constexpr int COUNTDOWN_START = 3;

  
  /*
    The amount of time in microseconds that passes between each number in the countdown.
   */
  static constexpr int COUNTDOWN_INTERVAL = 50000;
  
  // Ball values
  
  /* 
     The upper bound for the random perturbation that occurs when a ball bounces off of 
     the screen. The lower bound is the negation of this value. The perturbation
     is a value between these bounds that is added to the ball's reflected angle, in radians.
  */
  static constexpr double BALL_BOUNCE_PERTURBATION = 0.1;
  /*
    The value for the magnitude of the ball's velocity in pixels per microsecond.
   */
  static constexpr double BALL_SPEED = .008;
  /*
    The maximum value for the ball's starting angle at the beginning of a round. A value between
    this value and BALL_MIN_VALUE is generated and then rotated into a random quadrant before
    being set to the ball's angle.
   */
  static constexpr double BALL_MAX_ANGLE = 3*M_PI/7;
  /*
    The minimum value for the ball's starting angle at the beginning of a round. A value between
    this value and BALL_MAX_VALUE is generated and then rotated into a random quadrant before
    being set to the ball's angle.
   */
  static constexpr double BALL_MIN_ANGLE = M_PI/7;

  // Paddle values

  /*
    The default speed for human-controlled paddles in pixels per microsecond.
   */
  static constexpr double HUMAN_PLAYER_SPEED = .02;
  /*
    The default speed for computer-controlled paddles in pixels per microsecond.
   */
  static constexpr double COMPUTER_PLAYER_SPEED = .004;
  /*
    The amount of space past the top and bottom of a player's paddle in pixels that 
    the ball can bounce off of. This "cheat" makes the game's controls feel better
   */
  static constexpr int PADDLE_BOUNCE_TOLERANCE = 5;

  //Strings

  //Menu options

  static const string NEWGAME_MENU_OPTION;
  static const string CONTINUEGAME_MENU_OPTION;
  static const string MAINMENU_MENU_OPTION;
  static const string QUITGAME_MENU_OPTION;
  static const string STARTGAME_MENU_OPTION;
  static const string OPTIONS_MENU_OPTION;
  
  
};

#endif
