/*
  view.cpp
  Purpose: 

  @author Jeremy Elkayam
 */
#include <SFML/Graphics.hpp>
#include "view.hpp"

View::View(Game *game, sf::RenderWindow window)
{
  this->game=game;
  this->window=&window;
}

void View::update()
{
  //clear window to prepare for rendering
  window->clear(sf::Color::Black);

  draw_ball();

  window->display();
  
}


void View::draw_ball()
{
  sf::CircleShape ball(5);

  ball.setPosition(game->get_ball_x(),game->get_ball_y());

  window->draw(ball);
}
