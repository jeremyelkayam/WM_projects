/*
  sound_player.cpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */

#include <iostream>
#include <SFML/Audio.hpp>
#include "sound_player.hpp"

using namespace std;

void SoundPlayer::play_three()
{
  sf::SoundBuffer buffer;
  if(!buffer.loadFromFile("../assets/sounds/THREE.wav"))
    {
      cout << "error encountered\n";
      //error handling
    }
  
  sf::Sound sound;
  
  sound.setBuffer(buffer);
  sound.play();
  //cout << "play sound\n";
}

void SoundPlayer::play_two()
{
  sf::SoundBuffer buffer;
  if(!buffer.loadFromFile("../assets/sounds/TWO.wav"))
    {
      cout << "error encountered\n";
      //error handling
    }
  
  sf::Sound sound;

  sound.setBuffer(buffer);
  sound.play();
  //cout << "play sound\n";
}
