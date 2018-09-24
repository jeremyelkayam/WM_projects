/*
  sound_player.cpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */

#include <iostream>
#include "sound_player.hpp"
#include "constants.hpp"

using namespace std;

sf::SoundBuffer SoundPlayer::three_buffer,SoundPlayer::two_buffer,SoundPlayer::one_buffer,SoundPlayer::go_buffer,SoundPlayer::game_set_buffer,SoundPlayer::menu_select_buffer,SoundPlayer::player_score_buffer,SoundPlayer::computer_score_buffer;
sf::Sound SoundPlayer::three,SoundPlayer::two,SoundPlayer::one,SoundPlayer::go,SoundPlayer::game_set,SoundPlayer::menu_select,SoundPlayer::player_score,SoundPlayer::computer_score;

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

  if(!SoundPlayer::player_score_buffer.loadFromFile(Constants::PLAYER_SCORE_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::player_score.setBuffer(SoundPlayer::player_score_buffer);
  
  if(!SoundPlayer::computer_score_buffer.loadFromFile(Constants::COMPUTER_SCORE_SOUND_PATH))
    {
      cout << "error encountered\n";
      //error handling
    }
  SoundPlayer::computer_score.setBuffer(SoundPlayer::computer_score_buffer);
}
void SoundPlayer::play_three()
{
  if(Constants::SOUNDS_ON) SoundPlayer::three.play();
  //cout << "hi\n";
}

void SoundPlayer::play_two()
{
  if(Constants::SOUNDS_ON) SoundPlayer::two.play();
}

void SoundPlayer::play_one()
{
  if(Constants::SOUNDS_ON) SoundPlayer::one.play();
}

void SoundPlayer::play_go()
{
  if(Constants::SOUNDS_ON) SoundPlayer::go.play();
}

void SoundPlayer::play_game_set()
{
  if(Constants::SOUNDS_ON) SoundPlayer::game_set.play();
}
void SoundPlayer::play_menu_select()
{
  if(Constants::SOUNDS_ON) SoundPlayer::menu_select.play();
}
void SoundPlayer::play_player_score()
{
  if(Constants::SOUNDS_ON) SoundPlayer::player_score.play();
}
void SoundPlayer::play_computer_score()
{
  if(Constants::SOUNDS_ON) SoundPlayer::computer_score.play();
}
