/*
  ai_view.hpp
  Purpose: Provide the AI with the information it needs to make decisions.
 */

#ifndef AI_VIEW_HPP
#define AI_VIEW_HPP

#include "game.hpp"

class AIView
{
private:
  //Stores a reference to the game's properties.
  Game *game;
public:
  /*
    Constructor for the view. Sets up the reference to the game properties.

    @param game the main Game class storing game properties.
   */
  AIView(Game *game);
  /*
    Returns the y-coordinate of the game's ball.
    
    @return the y-coordinate of the ball in pixels
   */
  double ball_ycor();
  /*
    Returns the x-coordinate of the game's ball.
    
    @return the x-coordinate of the ball in pixels
   */
  double ball_xcor();
  /*
    Returns the angle of the velocity of the game's ball.
    
    @return the angle of the ball's velocity in radians
   */
  double ball_angle();
  /*
    Returns the x component of the velocity of the game's ball.
    
    @return the x component of the ball's velocity in pixels per microsecond
   */
  double ball_x_velocity();
  /*
    Returns the y component of the velocity of the game's ball.
    
    @return the y component of the ball's velocity in pixels per microsecond
   */
  double ball_y_velocity();
  
  /*
    Returns a reference to the Paddle object belonging to player 1
    
    @return a reference to the paddle object controlled by player 1
   */
  Paddle *get_p1_paddle();
};

#endif
