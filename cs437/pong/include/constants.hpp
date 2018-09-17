/*
  Constants.hpp
  Purpose: Consolidate all game constants/strings into a single class as static variables
  for easy editing across classes.
  
 */

class Constants
{
public:
  /* 
     The upper bound for the random perturbation that occurs when a ball bounces off of 
     the screen. The lower bound is the negation of this value. The perturbation
     is a value between these bounds that is added to the ball's reflected angle, in radians.
  */
  static constexpr double BALL_BOUNCE_PERTURBATION = 0.1;

  /*
    The default speed for computer-controlled paddles in pixels per microsecond.
   */
  static constexpr double COMPUTER_PLAYER_SPEED = .004;
};
