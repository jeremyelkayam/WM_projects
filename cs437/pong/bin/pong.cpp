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
#include <SFML/Audio.hpp>
#include "ball.hpp"
#include "game.hpp"
#include "renderer.hpp"
#include "logic.hpp"
#include "sound_player.hpp"

using namespace std;

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong (working title)",sf::Style::Titlebar | sf::Style::Close); //enable titlebar & close options
  sf::Color bgcolor=sf::Color::Black;

  //set up game
  Game *game = new Game(App.getSize().x,App.getSize().y,GameState::NewRound);
  Logic *logic = new Logic(game);
  Renderer *renderer = new Renderer(game,&App);

  sf::Clock clock;
  
  
  
  // start main loop
  while(App.isOpen())
    {
    
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
	      if(game->get_current_state()==GameState::Playing)
		{
		  logic->handle_menu_event(Event,&App);	      
		}
	      else if(game->get_current_state()==GameState::Paused)
		{
		  game->set_state(GameState::Playing);
		}
	    }
	  if(game->get_current_state()==GameState::NewRound)
	    {
	      game->set_state(GameState::CountDown);
	    }
	  else if(game->get_current_state()==GameState::EndScreen)
	    {
	      logic->handle_menu_event(Event,&App);
	    }
	}
	
    }
    //update renderer and logic
    logic->update(clock.getElapsedTime().asMicroseconds());
    renderer->update();

    clock.restart();
  }

  // Done.
  return 0;
}
