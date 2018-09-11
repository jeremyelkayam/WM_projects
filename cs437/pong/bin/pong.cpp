/*
  pong.cpp
  Purpose: Main executable for pong assignment. Controls setup/teardown of game as well as game loop.
  
  Disclaimer: may be terrible, since I have no idea what I'm doing and just futsed around with SFML for
  awhile, trying to make use of the SFML documentation and game conventions described in the lectures from
  the first 3 weeks...

  @author Jeremy Elkayam
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "game.hpp"
#include "renderer.hpp"
#include "logic.hpp"

using namespace std;

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong (working title)",sf::Style::Titlebar | sf::Style::Close); //enable titlebar & close options
  sf::Color bgcolor=sf::Color::Black;

  //set up game
  Game *game = new Game(App.getSize().x,App.getSize().y);
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
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();

	
    }
    //update renderer and logic
    logic->update(clock.getElapsedTime().asMicroseconds());
    renderer->update();

    clock.restart();
  }

  // Done.
  return 0;
}
