
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "game.hpp"
#include "view.hpp"

using namespace std;

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong (working title)",sf::Style::Titlebar | sf::Style::Close); //enable titlebar & close options
  sf::Color bgcolor=sf::Color::Black;

  //set up game
  Game *game = new Game(App.getSize().x,App.getSize().y);
  View *view = new View(game,&App);

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
    //update view and logic
    view->update();
  }

  // Done.
  return 0;
}
