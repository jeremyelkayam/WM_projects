/*
  sound_player.cpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */

#include <iostream>
#include <SFML/Audio.hpp>
#include "sound_player.hpp"
#include "constants.hpp"

using namespace std;

void SoundPlayer::play_three()
{
  sf::SoundBuffer buffer;
  if(!buffer.loadFromFile(Constants::THREE_SOUND_PATH))
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
  if(!buffer.loadFromFile(Constants::TWO_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  
  sf::Sound sound;

  sound.setBuffer(buffer);
  sound.play();
  //cout << "play sound\n";
}
