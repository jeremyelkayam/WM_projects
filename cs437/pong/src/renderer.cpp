/*
  view.cpp
  Purpose: 

  @author Jeremy Elkayam
 */
#include <SFML/Graphics.hpp>
#include "renderer.hpp"

using namespace std;

Renderer::Renderer(Game *game, sf::RenderWindow *window)
{
  this->game=game;
  this->window=window;


  //idea - make set_up_font(), set_up_ball(), etc. methods for this?
  if (!this->font.loadFromFile("../assets/fonts/gloryquest.ttf"))
    {
      //TODO - handle this error (immediate exit and popup saying file not found?)
    }
  ball.setRadius(5);
  
  p1_paddle.setSize(sf::Vector2f(5,game->get_p1_paddle()->get_height()));
  p2_paddle.setSize(sf::Vector2f(5,game->get_p2_paddle()->get_height()));
  
}

void Renderer::update()
{
  //clear window to prepare for rendering
  window->clear(sf::Color::Black);
  
  draw_ball();
  draw_scores();
  draw_paddles();

  window->display();

}


void Renderer::draw_ball()
{
  ball.setPosition(game->get_ball()->get_xcor(),game->get_ball()->get_ycor());

  window->draw(ball);
}

void Renderer::draw_scores()
{
  //set font for both score texts
  p1score.setFont(font);
  p2score.setFont(font);

  //set score texts to display respective scores
  p1score.setString("P1: " + to_string(game->get_p1_score()) + " points");
  p2score.setString("P2: " + to_string(game->get_p2_score()) + " points");

  p1score.setCharacterSize(40);
  p2score.setCharacterSize(40);
  
  p1score.setPosition(100,50);
  p2score.setPosition(600,50);

  window->draw(p1score);
  window->draw(p2score);
  
}

void Renderer::draw_paddles()
{

  p1_paddle.setPosition(0,game->get_p1_paddle()->get_center());
  p2_paddle.setPosition(game->get_x_dimension()-5,game->get_p1_paddle()->get_center());
  
  window->draw(p1_paddle);
  window->draw(p2_paddle);
			       
}
