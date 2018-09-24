/*
  sound_player.cpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */

#include <iostream>
#include "sound_player.hpp"
#include "constants.hpp"

using namespace std;

sf::SoundBuffer SoundPlayer::three_buffer,SoundPlayer::two_buffer,SoundPlayer::one_buffer,SoundPlayer::go_buffer;
sf::Sound SoundPlayer::three,SoundPlayer::two,SoundPlayer::one,SoundPlayer::go;

void SoundPlayer::init()
{
  if(!SoundPlayer::three_buffer.loadFromFile(Constants::THREE_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::three.setBuffer(SoundPlayer::three_buffer);

  if(!SoundPlayer::two_buffer.loadFromFile(Constants::TWO_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::two.setBuffer(SoundPlayer::two_buffer);
  
  if(!SoundPlayer::three_buffer.loadFromFile(Constants::THREE_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::three.setBuffer(SoundPlayer::three_buffer);
}
void SoundPlayer::play_three()
{
  SoundPlayer::three.play();
  //cout << "hi\n";
}

void SoundPlayer::play_two()
{
  SoundPlayer::two.play();
}
