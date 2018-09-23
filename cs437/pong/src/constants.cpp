/*
  Constants.cpp
  Purpose: Consolidate all game constants/strings into a single class as static
  variables for easy editing across classes. This source file initializes
  variables that are not defined in the header file.
  
  @author Jeremy Elkayam
 */

#include "constants.hpp"

const sf::Color Constants::BACKGROUND_COLOR = sf::Color::Black;
const sf::Color Constants::MENU_HIGHLIGHT_COLOR = sf::Color::Yellow;

const vector<double> Constants::SPEED_VALUES = {0.25, 0.33, 0.5, 0.75, 1.0,
						1.5, 2.0, 3.0, 4.0};

int Constants::WIN_SCORE = 11;

const string Constants::VERSION_NUMBER="1.2";

const string Constants::NEWGAME_MENU_OPTION="New Game";
const string Constants::CONTINUEGAME_MENU_OPTION = "Continue";
const string Constants::MAINMENU_MENU_OPTION = "Main Menu";
const string Constants::QUITGAME_MENU_OPTION = "Quit";
const string Constants::STARTGAME_MENU_OPTION = "Start Game";
const string Constants::OPTIONS_MENU_OPTION = "Options";
const string Constants::ABOUT_MENU_OPTION = "About";
const string Constants::BACK_MENU_OPTION = "Back";
const string Constants::SPEED_MENU_OPTION = "Speed: ";
const string Constants::WIN_THRESHOLD_OPTION = "Points required to win: ";


const string Constants::PIXEL_FONT_PATH = "../assets/fonts/gloryquest.ttf";
const string Constants::TITLE_FONT_PATH = "../assets/fonts/mumbold.ttf";
const string Constants::THREE_SOUND_PATH = "../assets/sounds/THREE.wav";
const string Constants::TWO_SOUND_PATH = "../assets/sounds/TWO.wav";
const string Constants::ONE_SOUND_PATH = "../assets/sounds/ONE.wav";
const string Constants::GO_SOUND_PATH = "../assets/sounds/GO.wav";

const string Constants::P1_SCORE_DISPLAY_BEGIN = "P1: ";
const string Constants::P2_SCORE_DISPLAY_BEGIN = "P2: ";
const string Constants::SCORE_DISPLAY_END = " points";

const string Constants::NEW_ROUND_TEXT = "Press any key to continue...";

const string Constants::P1_NAME = "Player 1";
const string Constants::P2_NAME = "Player 2";
const string Constants::WINS_TEXT = " wins!";

const string Constants::PAUSE_TEXT = "Paused";

const string Constants::TITLE_SCREEN_TITLE = "PONG";
const string Constants::WINDOW_TITLE = "Pong";
const string Constants::VERSION_TEXT = "Version ";
const string Constants::AUTHOR_NAME = "Jeremy Elkayam";
const string Constants::RELEASE_YEAR = "2018";
const string Constants::AUTHOR_PREFIX = "(c)";

const string Constants::ABOUT_VERSION_NUMBER_PREFIX = "Pong version ";
const string Constants::ABOUT_SCREEN_TITLE = "About";
const vector<string> Constants::ABOUT_SCREEN_TEXT = {"Game programmed by Jeremy Elkayam.\n\n",
						     "Created using the Simple Fast Multimedia Library by the SFML Team.\n",
						     "Based on the 1972 arcade game Pong by Al Alcorn.\n",
						     "Created for CS437: Intro to Game Design and Game Development",
						     "at The College of William & Mary."};
