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
  //Sound buffers for all of the sounds in the game.
  static sf::SoundBuffer three_buffer,two_buffer,one_buffer,go_buffer,game_set_buffer,menu_select_buffer,player_score_buffer,computer_score_buffer,paddle_deflect_buffer,wall_deflect_buffer;
  
  //Sound classes for all the sounds in the game.
  static sf::Sound three,two,one,go,game_set,menu_select,player_score,computer_score,wall_deflect,paddle_deflect;
public:
  /*
    If sounds are on, plays the "THREE" voice sound effect, called "THREE.wav" in the asset files.
   */
  static void play_three();
  /*
    If sounds are on, plays the "TWO" voice sound effect, called "TWO.wav" in the asset files.
   */
  static void play_two();
  /*
    If sounds are on, plays the "ONE" voice sound effect, called "ONE.wav" in the asset files.
   */
  static void play_one();
  /*
    If sounds are on, plays the "GO" voice sound effect, called "GO.wav" in the asset files.
   */
  static void play_go();
  /*
    If sounds are on, plays the "GAME SET" voice sound effect, called
    "GAMESET.wav" in the asset files.
   */
  static void play_game_set();
  /*
    If sounds are on, plays the sound effect for when the player selects a
    menu option, called "MENU_SELECT.wav" in the asset files.
   */
  static void play_menu_select();
  /*
    If sounds are on, plays the sound effect for when the player scores, called
    "PLAYER_SCORE.wav" in the asset files.
   */
  static void play_player_score();
  /*
    If sounds are on, plays the sound effect for when the AI scores, called
    "COMPUTER_SCORE.wav" in the asset files.
   */
  static void play_computer_score();
  /*
    If sounds are on, plays the sound effect for when the ball hits a paddle,
    called "PADDLE_DEFLECT.wav" in the asset files.
   */
  static void play_paddle_deflect();
  /*
    If sounds are on, plays the sound effect for when the ball hits a wall,
    called "WALL_DEFLECT.wav" in the asset files.
   */
  static void play_wall_deflect();
  /*
    Initializes all the sound and buffer classes within the class.
    Loads all sound effects into buffers and links respective 
    sound classes to them. 
   */
  static void init();
};

#endif
