/*
  game.hpp
  Purpose: Store game properties in a singular class for easy access.
 */
#ifndef GAME_HPP
#define GAME_HPP


class Game
{
private:
  Ball ball;
  
public:
  Game();
       
  double get_ball_x();
  double get_ball_y();
}

#endif
