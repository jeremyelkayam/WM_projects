
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
    

    // clear screen and fill with bgcolor    
    //App.clear(bgcolor);

  
    
    /*bgcolor=sf::Color::Black;

    sf::CircleShape circle(5);

    circle.setPosition(pos,pos);
    circle.setPointCount(10);

    App.draw(circle);
    */
    // display
    App.display();
    
  }

  // Done.
  return 0;
}
