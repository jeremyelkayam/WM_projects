/*
  Constants.hpp
  Purpose: Consolidate all game constants/strings into a single class as static variables
  for easy editing across classes.
  
  @author Jeremy Elkayam
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

using namespace std;

class Constants
{
public:

  // Initialize all string constants to their intended values.
  static void init_strings();
  
  // Ball values
  
  /* 
     The upper bound for the random perturbation that occurs when a ball bounces off of 
     the screen. The lower bound is the negation of this value. The perturbation
     is a value between these bounds that is added to the ball's reflected angle, in radians.
  */
  static constexpr double BALL_BOUNCE_PERTURBATION = 0.1;

  // Paddle values

  /*
    The default speed for computer-controlled paddles in pixels per microsecond.
   */
  static constexpr double COMPUTER_PLAYER_SPEED = .004;


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
