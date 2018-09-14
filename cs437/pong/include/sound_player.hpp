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
  static sf::SoundBuffer buffer;
  static void play_buffer(sf::SoundBuffer buffer);
public:
  static void play_three();
  static void play_two();
  static void play_one();
  static void play_go();
};

#endif
