/*
  pong.cpp
  Purpose: Main executable for pong assignment. Controls setup/teardown of game as well as game loop.
  
  Disclaimer: may be terrible, since I have no idea what I'm doing and just futsed around with SFML for
  awhile, trying to make use of the SFML documentation and game conventions described in the lectures from
  the first 3 weeks...

  @author Jeremy Elkayam
 */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ball.hpp"
#include "game.hpp"
#include "renderer.hpp"
#include "logic.hpp"
#include "sound_player.hpp"
#include "constants.hpp"

using namespace std;


int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(Constants::DEFAULT_WINDOW_WIDTH,
				     Constants::DEFAULT_WINDOW_HEIGHT,
				     Constants::DEFAULT_PIXEL_DEPTH),
		       Constants::WINDOW_TITLE,
		       sf::Style::Titlebar | sf::Style::Close);
  //enable titlebar & close options
  sf::Color bgcolor=Constants::BACKGROUND_COLOR;
  

  //set up gameColor BACKGROUND_COLOR;
  Game *game = new Game(App.getSize().x,App.getSize().y,GameState::MainMenu);
  Logic *logic = new Logic(game);
  Renderer *renderer = new Renderer(game,&App);

  sf::Clock clock;
  
  
  
  // start main loop
  while(App.isOpen())
    {
      int micros_elapsed=clock.restart().asMicroseconds();
      GameState previous_state;
      // process events
      sf::Event Event;
      while(App.pollEvent(Event))
	{
	  //TODO: put all event handling into the logic class.
	  if(Event.type == sf::Event::Closed)
	    {
	      App.close();
	    }
	  else if(Event.type == sf::Event::KeyPressed)
	    {
	      
	      if(Event.key.code == sf::Keyboard::Escape)
		{ 
		  if(game->get_current_state()==GameState::Playing )
		    //||game->get_current_state()==GameState::CountDown)
		    {
		      game->set_state(GameState::Paused);
		      previous_state=game->get_current_state();
		    }
		  else if(game->get_current_state()==GameState::Paused)
		    {
		      game->set_state(previous_state);
		    }
		}
	      if(game->get_current_state()==GameState::NewRound)
		{
		  game->set_state(GameState::CountDown);
		}
	      else if(game->get_current_state()==GameState::EndScreen ||
		      game->get_current_state()==GameState::Paused ||
		      game->get_current_state()==GameState::MainMenu ||
		      game->get_current_state()==GameState::AboutScreen ||
		      game->get_current_state()==GameState::Settings)
		{
		  logic->handle_menu_event(Event,&App);
		}
	    }
	  
	}
      //update renderer and logic
      logic->update(micros_elapsed);
      renderer->update();
      
    }
  
  // Done.
  return 0;
}
