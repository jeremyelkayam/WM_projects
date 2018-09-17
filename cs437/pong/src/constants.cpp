/*
  Constants.cpp
  Purpose: Consolidate all game constants/strings into a single class as static
  variables for easy editing across classes. This source file initializes
  variables that are not defined in the header file.
  
  @author Jeremy Elkayam
 */

#include "constants.hpp"

const string Constants::NEWGAME_MENU_OPTION="New Game";
const string Constants::CONTINUEGAME_MENU_OPTION = "Continue";
const string Constants::MAINMENU_MENU_OPTION = "Main Menu";
const string Constants::QUITGAME_MENU_OPTION = "Quit";
const string Constants::STARTGAME_MENU_OPTION = "Start Game";
const string Constants::OPTIONS_MENU_OPTION = "Options";


const string Constants::PIXEL_FONT_PATH = "../assets/fonts/gloryquest.ttf";
const string Constants::TITLE_FONT_PATH = "../assets/fonts/mumbold.ttf";

const string Constants::P1_SCORE_DISPLAY_BEGIN = "P1: ";
const string Constants::P2_SCORE_DISPLAY_BEGIN = "P2: ";
const string Constants::SCORE_DISPLAY_END = " points";

const string Constants::NEW_ROUND_TEXT = "Press any key to continue...";

const string Constants::P1_NAME = "Player 1";
const string Constants::P2_NAME = "Player 2";
const string Constants::WINS_TEXT = " wins!";

const string Constants::PAUSE_TEXT = "Paused";

const string Constants::TITLE_SCREEN_TITLE = "PONG";
