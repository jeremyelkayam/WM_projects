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
  static sf::SoundBuffer three_buffer,two_buffer,one_buffer,go_buffer,game_set_buffer,menu_select_buffer,player_score_buffer,computer_score_buffer,paddle_deflect_buffer,wall_deflect_buffer;
  static sf::Sound three,two,one,go,game_set,menu_select,player_score,computer_score,wall_deflect,paddle_deflect;
public:
  static void play_three();
  static void play_two();
  static void play_one();
  static void play_go();
  static void play_game_set();
  static void play_menu_select();
  static void play_player_score();
  static void play_computer_score();
  static void play_paddle_deflect();
  static void play_wall_deflect();
  static void init();
};

#endif
