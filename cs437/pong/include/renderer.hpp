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
  sf::CircleShape ball;
  sf::Text p1score,p2score,new_round_text,countdown_text;
  sf::RectangleShape p1_paddle,p2_paddle;

  void draw_ball();
  void draw_scores();
  void draw_paddles();
  void draw_new_round_text();
  void draw_countdown_text();

public:
  Renderer(Game *game,sf::RenderWindow *window);
  
  void update();
  
};

#endif
