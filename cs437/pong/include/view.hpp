/*
  view.hpp
  Purpose: 

  @author Jeremy Elkayam
 */
#ifndef VIEW_HPP
#define VIEW_HPP

#include <SFML/Graphics.hpp>

class View
{
private:
  //A reference to the properties of the game being played.
  Game *game;
  sf::RenderWindow window;

  void draw_ball();

public:
  View(Game *game,sf::RenderWindow window);
  
  void update();
  
}

#endif
