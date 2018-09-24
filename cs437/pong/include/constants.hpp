/*
  Constants.hpp
  Purpose: Consolidate all game constants/strings into a single class as static
  variables for easy editing across classes.
  
  @author Jeremy Elkayam
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;

class Constants
{
public:

  // Initialize all string constants to their intended values.
  static void init_strings();

  //Game values

  /*
    Default width of the gane window in pixels.
   */
  static constexpr unsigned int DEFAULT_WINDOW_WIDTH = 800;
  /*
    Default height of the gane window in pixels.
   */
  static constexpr unsigned int DEFAULT_WINDOW_HEIGHT = 600;
  /*
    Default video pixel depth in bits per pixel.
   */
  static constexpr unsigned int DEFAULT_PIXEL_DEPTH = 32;
  /*
    The amount of points required to win the game.
   */
  static int WIN_SCORE;
  /*
    The starting value for the countdown at the beginning of each round.
   */
  static constexpr int COUNTDOWN_START = 3;
  /*
    The color of the game background.
   */
  static const sf::Color BACKGROUND_COLOR;
  /*
    The color of the game background.
   */
  static const sf::Color MENU_HIGHLIGHT_COLOR;

  
  /*
    The amount of time in microseconds that passes between each number in the
    countdown.
   */
  static constexpr int COUNTDOWN_INTERVAL = 1000000;
  
  // Ball values
  
  /* 
     The upper bound for the random perturbation that occurs when a ball bounces
     off of the screen. The lower bound is the negation of this value. The
     perturbation is a value between these bounds that is added to the ball's
     reflected angle, in radians.
  */
  static constexpr double BALL_BOUNCE_PERTURBATION = 0.1;
  /*
    The value for the magnitude of the ball's velocity in pixels per microsecond.
   */
  static constexpr double BALL_SPEED = .0004;
  /*
    The maximum value for the ball's starting angle at the beginning of a round.
    A value between this value and BALL_MIN_VALUE is generated and then rotated
    into a random quadrant before being set to the ball's angle.
   */
  static constexpr double BALL_MAX_ANGLE = 2*M_PI/7;
  /*
    The minimum value for the ball's starting angle at the beginning of a round.
    A value between this value and BALL_MAX_VALUE is generated and then rotated
    into a random quadrant before being set to the ball's angle.
   */
  static constexpr double BALL_MIN_ANGLE = M_PI/7;
  /*
    The rendered ball's radius in pixels.
   */
  static constexpr double BALL_RADIUS = 5;

  // Paddle values

  /*
    The default speed for human-controlled paddles in pixels per microsecond.
   */
  static constexpr double HUMAN_PLAYER_SPEED = .001;
  /*
    The default speed for computer-controlled paddles in pixels per microsecond.
   */
  static constexpr double COMPUTER_PLAYER_SPEED = .001;
  /*
    The amount of space past the top and bottom of a player's paddle in pixels 
    that the ball can bounce off of. This "cheat" makes the game's controls feel
    more smooth.
   */
  static constexpr int PADDLE_BOUNCE_TOLERANCE = 5;
  /*
    The width of the paddle as rendered by the Renderer. This DOES NOT define
    anything to do with collisions between the paddle and the ball.

    TODO - make the ball hit the entire paddle instead of just the edge?
   */
  static constexpr int PADDLE_RENDERED_WIDTH = 5;

  //AI values

  static constexpr int MAX_WAITING_TIME = 1000000;
  
  static constexpr int MIN_WAITING_TIME = 250000;

  static constexpr int AIM_PERTURBATION_BOUND_MULTIPLIER = 1;
  
  //Text-rendering values

  /*
    The height of each character in the score display.
   */
  static constexpr int SCORE_CHAR_SIZE = 48;
  /*
    The x-coordinate of the center of the Player 1 score display text.
   */
  static constexpr int P1_SCORE_XCOR = 150;
  /*
    The y-coordinate of the center of the Player 1 score display text.
   */
  static constexpr int P1_SCORE_YCOR = 100;
  /*
    The x-coordinate of the center of the Player 2 score display text.
   */
  static constexpr int P2_SCORE_XCOR = 650;
  /*
    The y-coordinate of the center of the Player 2 score display text.
   */
  static constexpr int P2_SCORE_YCOR = 100;

  
  /*
    The height of each character in the new round text display. 
   */
  static constexpr int NEW_ROUND_CHAR_SIZE = 64;

  /*
    The distance between the bottom border of the window and the
    y-coordinate of the new round text.
   */
  static constexpr int NEW_ROUND_YCOR_OFFSET = 100;

  /*
    The height of the number in the countdown. This is multiplied by 2
    repeatedly for each successive number in the countdown.
   */
  static constexpr int COUNTDOWN_CHAR_SIZE = 160;
  
  /*
    The height of each character in menus.
   */
  static constexpr int MENU_CHAR_SIZE = 64;
  /*
    The distance between y-coordinates of each option in the game's menus.
   */
  static constexpr int MENU_TEXT_OFFSET = 48;

  /*
    The height of each character in the text displayed at the end of
    a game.
   */
  static constexpr int FINISH_TEXT_CHAR_SIZE = 128;

  /*
    The height of each character in the title text displayed on the
    pause screen.
   */
  static constexpr int PAUSE_TEXT_CHAR_SIZE = 128;
  /*
    The distance below the center of the screen that the pause
    menu should be displayed.
   */
  static constexpr int PAUSE_MENU_OFFSET = 100;
  /*
    The height of each character in the title text displayed on the
    title screen.
   */
  static constexpr int TITLE_CHAR_SIZE = 256;
  /*
    The y-coordinate of the title text displayed on the title screen.
   */
  static constexpr int TITLE_YCOR = 200;
  /*
    The y-coordinate of the top of the title menu displayed on the
    title screen.
   */
  static constexpr int TITLE_MENU_YCOR = 350;
  /*
    The height of each character in the version and author text displayed
    on the title screen.
   */
  static constexpr int VERSION_AUTHOR_CHAR_SIZE = 32;
  /*
    The height of each character in the title of the about screen.
   */
  static constexpr int ABOUT_TITLE_CHAR_SIZE = 128;
  /*
    The y-coordinate of the title of the about menu.
   */
  static constexpr int ABOUT_TITLE_YCOR = 100;
  /*
    The height of each character in the body text on the about screen.
   */
  static constexpr int ABOUT_TEXT_CHAR_SIZE = 32;
  /*
    The y-coordinate of the top row of body text on the about screen.
   */
  static constexpr int ABOUT_TEXT_STARTING_YCOR = 200;
  /*
    The interval between rows of the body text on the about screen.
   */
  static constexpr int ABOUT_TEXT_OFFSET = 32;

  static const vector<double> SPEED_VALUES;
  
  //Strings

    /*
    The version of the game as displayed on the title and about screens.
   */
  static const string VERSION_NUMBER;


  //Menu options

  static const string NEWGAME_MENU_OPTION;
  static const string CONTINUEGAME_MENU_OPTION;
  static const string MAINMENU_MENU_OPTION;
  static const string QUITGAME_MENU_OPTION;
  static const string STARTGAME_MENU_OPTION;
  static const string OPTIONS_MENU_OPTION;
  static const string ABOUT_MENU_OPTION;
  static const string BACK_MENU_OPTION;
  static const string SPEED_MENU_OPTION;
  static const string WIN_THRESHOLD_OPTION;

  // Paths to asset files
  
  static const string PIXEL_FONT_PATH;
  static const string TITLE_FONT_PATH;
  static const string THREE_SOUND_PATH;
  static const string TWO_SOUND_PATH;
  static const string ONE_SOUND_PATH;
  static const string GO_SOUND_PATH;
  static const string GAME_SET_SOUND_PATH;
  static const string MENU_SELECT_SOUND_PATH;

  // Score display strings
  
  static const string P1_SCORE_DISPLAY_BEGIN;
  static const string P2_SCORE_DISPLAY_BEGIN;
  static const string SCORE_DISPLAY_END;

  // New round display strings

  static const string NEW_ROUND_TEXT;

  // End screen display strings

  static const string P1_NAME;
  static const string P2_NAME;
  static const string WINS_TEXT;

  //Pause screen display strings

  static const string PAUSE_TEXT;

  //Title screen display strings

  static const string TITLE_SCREEN_TITLE;
  static const string WINDOW_TITLE;
  static const string VERSION_TEXT;
  static const string AUTHOR_NAME;
  static const string RELEASE_YEAR;
  static const string AUTHOR_PREFIX;

  //About screen display strings
  static const string ABOUT_VERSION_NUMBER_PREFIX;
  static const string ABOUT_SCREEN_TITLE;
  static const vector<string> ABOUT_SCREEN_TEXT;
};

#endif
