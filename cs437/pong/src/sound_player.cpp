/*
  sound_player.cpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */

#include "sound_player.hpp"

void SoundPlayer::play_three()
{
  if(!buffer.loadFromFile("../assets/sounds/THREE.wav"))
    {
      //error handling
    }
  play_buffer(buffer);
}

void SoundPlayer::play_buffer(sf::SoundBuffer buffer)
{
  sf::Sound sound;
  
  sound.setBuffer(buffer);
  sound.play(); 
}
