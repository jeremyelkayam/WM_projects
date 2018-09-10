#ifndef VIEW_HPP
#define VIEW_HPP

#include <SFML/Graphics.hpp>

class View
{
private:
  Game game;
  sf::RenderWindow window;

public:
  View(Game game,sf::RenderWindow window);
  
  void update();
  
}

#endif
