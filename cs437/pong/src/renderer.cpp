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

  draw_scores();
  draw_paddles();

  if(game->get_current_state()==GameState::NewRound)
    {
      draw_new_round_text();
    }
  else if(game->get_current_state()==GameState::CountDown)
    {
      draw_countdown_text();
    }
  else
    {  
      draw_ball();
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

void Renderer::draw_countdown_text()
{
  //TODO: make the text progressively bigger with the decreasing number
  
  countdown_text.setFont(font);

  countdown_text.setString(to_string(game->get_countdown()));

  int character_size;
  if(game->get_countdown()==3)
    {
      character_size=192;
    }
  else if(game->get_countdown()==2)
    {
      character_size=320;
    }
  else if(game->get_countdown()==1)
    {
      character_size=448;
    }
  else if(game->get_countdown()==0)
    {
      return;
    }
  
  countdown_text.setCharacterSize(character_size);

  sf::FloatRect textRect=countdown_text.getLocalBounds();
  countdown_text.setOrigin(textRect.left + textRect.width/2,
		 textRect.top + textRect.height/2);
  
  
  countdown_text.setPosition(400,300);
  //cout << "width " << countdown_text.getLocalBounds().width << ", height " << countdown_text.getLocalBounds().height << "\n";
  window->draw(countdown_text);
}
