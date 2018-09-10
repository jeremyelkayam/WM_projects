#include <SFML/Graphics.hpp>
#include <iostream>

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

      if(Event.type == sf::Event::KeyPressed)
	{
	  //std::cout <<"key is being pressed\n";
	  bgcolor=sf::Color::White;
	}
      else if(Event.type == sf::Event::KeyReleased)
	{
	  //std::cout << "key is released\n";
	  bgcolor=sf::Color::Black;
	}
	
    }

    // clear screen and fill with blue
    
    App.clear(bgcolor);
    
    
    // display
    App.display();
  }

  // Done.
  return 0;
}
