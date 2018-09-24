/*
  renderer.hpp
  Purpose: Consolidate all rendering operations into a single class, with one
           function that executes with each iteration of the main loop.

  @author Jeremy Elkayam
 */
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "game.hpp"

class Renderer
{
private:
  //A reference to the properties of the game being played.
  Game *game;
  sf::RenderWindow *window;
  sf::Font pixel_font,title_font;
  sf::CircleShape ball;
  sf::Text p1score,p2score,new_round_text,countdown_text;
  sf::RectangleShape p1_paddle,p2_paddle,speed_bar,speed_selector;

  void draw_ball(sf::Color color=sf::Color::White);
  void draw_scores();
  void draw_paddles(sf::Color color=sf::Color::White);
  void draw_new_round_text();
  void draw_countdown_text();
  void draw_end_menu();
  void draw_pause_menu();
  void draw_main_menu();
  void draw_about_screen();
  void draw_menu_text(int starting_ycor);
  void draw_version_author_texts();
  void draw_settings_menu();
  void draw_attract_mode();

  void set_origin_to_center(sf::Text *text);
  void set_origin_to_bottom_left(sf::Text *text);
  void set_origin_to_bottom_right(sf::Text *text);
  
  void render_text(sf::Font a_font, string str, int char_size, double xcor, double ycor);

public:
  Renderer(Game *game,sf::RenderWindow *window);
  
  void update();
  
};

#endif
