/*
  human_view.hpp
  Purpose: Consolidate all rendering operations into a single class, with one
           function that executes with each iteration of the main loop.

  @author Jeremy Elkayam
 */
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "game.hpp"
#include "logic.hpp"

class HumanView
{
private:
  //A reference to the properties of the game being played.
  Game *game;
  //A reference to the class that handles game logic.
  Logic *logic;
  //A reference to the window used by the game.
  sf::RenderWindow *window;
  //The fonts used by the game.
  sf::Font pixel_font,title_font;
  //The pong game's ball.
  sf::CircleShape ball;
  //The text objects used by the class.
  sf::Text p1score,p2score,new_round_text,countdown_text;
  //The rectangles used by the class.
  sf::RectangleShape p1_paddle,p2_paddle,speed_bar,speed_selector;

  /*
    Draws the game's ball at its coordinates.
    
    @param color The fill color for the ball. Defaults to white.
   */
  void draw_ball(sf::Color color=sf::Color::White);
  /*
    Draws the two pieces of text displaying P1 and P2's respective scores.
    These are drawn near the top of the screen.
   */
  void draw_scores();
  /*
    Draw both players' paddles on the edges of the screen as rectangles,
    at their respective coordinates.

    @param color The fill color for the paddles. Defaults to white.
   */
  void draw_paddles(sf::Color color=sf::Color::White);
  /*
    Draws the "press any key to continue" text that displays at the
    beginning of each round.
   */
  void draw_new_round_text();
  /*
    Draws the number of the countdown. As the countdown decreases,
    the size of this number grows.
   */
  void draw_countdown_text();
  /*
    Draws the menu and text that displays at the end of the game. 
   */
  void draw_end_menu();
  /*
    Draws the menu and text that displays when the game is paused. 
   */
  void draw_pause_menu();
  /*
    Draws the menu and text that display on the title screen. 
   */
  void draw_main_menu();
  /*
    Draws the menu and text that display on the about screen. 
   */
  void draw_about_screen();
  /*
    Given a y-coordinate to start drawing from, this function
    draws each successive option of the menu starting at 
    starting_ycor and going down, highlighting the selected
    option in yellow. The x-coordinate of these will always
    be halfway across the screen.

    @param starting_ycor the ycor to start drawing from.
  */
  void draw_menu_text(int starting_ycor);
  /*
    Draws the two small pieces of text on the title screen
    denoting version number and author.
   */
  void draw_version_author_texts();
  /*
    Draws the text and options of the settings menu,
    including the speed slider.
   */
  void draw_settings_menu();
  /*
    Draws the ball and paddles in dark gray to display
    the sample gameplay of the title screen.
   */
  void draw_attract_mode();
  /*
    Draws the text saying "GO!!" from the beginning of each round.
   */
  void draw_go_text();
  
  /*
    Sets the origin of the given text to the center of the text.
    This makes positioning easier, as the setPosition() function
    only sets the text's origin to the given position.

    @param text The text whose origin is to be changed.
  */
  void set_origin_to_center(sf::Text *text);

  /*
    Sets the origin of the given text to the bottom left corner 
    of the text. This makes positioning easier, as the
    setPosition() function only sets the text's origin to the
    given position.

    @param text The text whose origin is to be changed.
  */
  void set_origin_to_bottom_left(sf::Text *text);

  /*
    Sets the origin of the given text to the bottom right corner
    of the text. This makes positioning easier, as the
    setPosition() function only sets the text's origin to
    the given position.

    @param text The text whose origin is to be changed.
  */
  void set_origin_to_bottom_right(sf::Text *text);


public:
  /*
    Constructor for the HumanView class. Initializes the class's objects.

    @param logic A reference to the class handling game logic.
    @param game A reference to the class storing game properties.
    @param window A reference to the window in which the game is being rendered.
   */
  HumanView(Logic *logic,Game *game,sf::RenderWindow *window);

  /*
    Should be called once every loop. Observes the properties of the game,
    and renders objects accordingly.
   */
  void update();
  
};

#endif
