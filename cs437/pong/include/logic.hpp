/*
  logic.hpp
  Purpose: 

  @author Jeremy Elkayam
 */
#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "game.hpp"

class Logic
{
private:
  Game *game;
public:
  Logic(Game *game);
  void update(int ms_elapsed);
};

#endif
