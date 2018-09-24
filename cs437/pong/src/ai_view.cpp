/*
  ai_view.hpp
  Purpose: Provide the AI with the information it needs to make decisions.
 */

#include "ai_view.hpp"

//Constructor
AIView::AIView(Game *game)
{
  this->game=game;
}

//Return ball's y-coordinate
double AIView::ball_ycor()
{
  return game->get_ball()->get_ycor();
}

//Return ball's x-coordinate
double AIView::ball_xcor()
{
  return game->get_ball()->get_xcor();
}

//Return ball's velocity's angle
double AIView::ball_angle()
{
  return game->get_ball()->get_angle();
}

//Return ball's velocity's x-component
double AIView::ball_x_velocity()
{
  return game->get_ball()->get_x_velocity();
}

//Return ball's velocity's y-component
double AIView::ball_y_velocity()
{
  return game->get_ball()->get_y_velocity();
}

//Return player 1's paddle
Paddle *AIView::get_p1_paddle()
{
  return game->get_p1_paddle();
}
