/*
  renderer.hpp
  Purpose: Consolidate all rendering operations into a single class, with one
           function that executes with each iteration of the main loop.

  @author Jeremy Elkayam
 */
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"

class Renderer
{
private:
  //A reference to the properties of the game being played.
  Game *game;
  sf::RenderWindow *window;
  sf::Font font;

  void draw_ball();
  void draw_scores();

public:
  Renderer(Game *game,sf::RenderWindow *window);
  
  void update();
  
};

#endif
