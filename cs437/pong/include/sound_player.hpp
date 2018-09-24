/*
  sound_player.hpp
  Purpose: Provide easy static methods for playing sound effects.

  @author Jeremy Elkayam
 */


#ifndef SOUND_PLAY_HPP
#define SOUND_PLAY_HPP

#include <SFML/Audio.hpp>

class SoundPlayer
{
private:
  static sf::SoundBuffer three_buffer,two_buffer,one_buffer,go_buffer,game_set_buffer;
  static sf::Sound three,two,one,go,game_set;
public:
  static void play_three();
  static void play_two();
  static void play_one();
  static void play_go();
  static void play_game_set();
  static void init();
};

#endif
