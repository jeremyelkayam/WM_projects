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
#include "human_view.hpp"
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

  sf::SoundBuffer buffer;
		      
  if(!buffer.loadFromFile("../assets/sounds/THREE.wav"))
    {
      
    }
  sf::Sound sound;
  
  sound.setBuffer(buffer);
		      

  //set up game components
  Game *game = new Game(App.getSize().x,App.getSize().y,GameState::MainMenu);
  Logic *logic = new Logic(game);
  HumanView *human_view = new HumanView(logic,game,&App);
  SoundPlayer::init();

  sf::Clock clock;
  
  // start main loop
  while(App.isOpen())
    {
      //Reset clock and track elapsed time since last loop.
      int micros_elapsed=clock.restart().asMicroseconds();
      if(App.hasFocus())
	{
	  
	  // process events
	  sf::Event Event;
	  while(App.pollEvent(Event))
	    {
	      logic->handle_event(Event,&App);
	    }
	  //update renderer and logic
	  logic->update(micros_elapsed);
	  human_view->update();
	}
    }
  
  // Done.

  //Delete allocated classes from heap space.
  delete(human_view);
  delete(logic);
  delete(game);
  
  
  return 0;
}
