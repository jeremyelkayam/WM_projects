/*
  view.cpp
  Purpose: 

  @author Jeremy Elkayam
 */
#include <iostream>
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

  if(game->get_current_state()==GameState::NewRound)
    {
      draw_new_round_text();
    }

  window->display();

}


void Renderer::draw_ball()
{
  ball.setPosition(game->get_ball()->get_xcor()-5,game->get_ball()->get_ycor()-5);

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

  p1score.setCharacterSize(48);
  p2score.setCharacterSize(48);
  
  p1score.setPosition(100,50);
  p2score.setPosition(500,50);

  window->draw(p1score);
  window->draw(p2score);
  
}

void Renderer::draw_paddles()
{

  p1_paddle.setPosition(0,game->get_p1_paddle()->get_ycor());
  p2_paddle.setPosition(game->get_x_dimension()-5,game->get_p2_paddle()->get_ycor());

  window->draw(p1_paddle);
  window->draw(p2_paddle);			       
}

void Renderer::draw_new_round_text()
{
  new_round_text.setFont(font);

  new_round_text.setString("Press any key to continue...");

  new_round_text.setCharacterSize(64);
  
  new_round_text.setPosition(100,450);

  window->draw(new_round_text);
}
