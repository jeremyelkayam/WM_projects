/*
  sound_player.cpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */

#include <iostream>
#include "sound_player.hpp"
#include "constants.hpp"

using namespace std;

sf::SoundBuffer SoundPlayer::three_buffer,SoundPlayer::two_buffer,SoundPlayer::one_buffer,SoundPlayer::go_buffer,SoundPlayer::game_set_buffer,SoundPlayer::menu_select_buffer;
sf::Sound SoundPlayer::three,SoundPlayer::two,SoundPlayer::one,SoundPlayer::go,SoundPlayer::game_set,SoundPlayer::menu_select;

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
  
  if(!SoundPlayer::one_buffer.loadFromFile(Constants::ONE_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::one.setBuffer(SoundPlayer::one_buffer);

  if(!SoundPlayer::go_buffer.loadFromFile(Constants::GO_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::go.setBuffer(SoundPlayer::go_buffer);

  if(!SoundPlayer::game_set_buffer.loadFromFile(Constants::GAME_SET_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::game_set.setBuffer(SoundPlayer::game_set_buffer);

  if(!SoundPlayer::menu_select_buffer.loadFromFile(Constants::MENU_SELECT_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::menu_select.setBuffer(SoundPlayer::menu_select_buffer);
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

void SoundPlayer::play_one()
{
  SoundPlayer::one.play();
}

void SoundPlayer::play_go()
{
  SoundPlayer::go.play();
}

void SoundPlayer::play_game_set()
{
  SoundPlayer::game_set.play();
}
void SoundPlayer::play_menu_select()
{
  SoundPlayer::menu_select.play();
}
