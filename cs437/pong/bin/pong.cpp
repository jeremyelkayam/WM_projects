
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong (working title)",sf::Style::Titlebar | sf::Style::Close); //enable titlebar & close options
  sf::Color bgcolor=sf::Color::Black;

  
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
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
	bgcolor=sf::Color::White;
      }


    // clear screen and fill with bgcolor    
    App.clear(bgcolor);
    
    bgcolor=sf::Color::Black;


    
    // display
    App.display();
  }

  // Done.
  return 0;
}
