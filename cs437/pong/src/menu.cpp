/*
  menu.cpp
  Purpose:

  @author Jeremy Elkayam
 */
#include "menu.hpp"
#include "constants.hpp"

using namespace std;

//Constructor.
Menu::Menu(MenuType type, int default_selection)
{
  set_type(type);
  selection=default_selection;
}

//Moves the selection down if there's room to do so.
void Menu::move_down()
{
  if(selection+1<options.size())
    {
      selection++;
    }
}

//Moves the selection up if there's room to do so.
void Menu::move_up()
{
  if(selection-1>-1)
    {
      selection--;
    }
}

//Resets the menu and changes its type to the given type.
void Menu::set_type(MenuType type)
{
  this->type=type;
  this->options.clear();
  this->selection=0;
  if(type==MenuType::Finish)
    {
      options.push_back(Constants::NEWGAME_MENU_OPTION);
      options.push_back(Constants::MAINMENU_MENU_OPTION);
      options.push_back(Constants::QUITGAME_MENU_OPTION);
    }
  else if(type==MenuType::Pause)
    {
      options.push_back(Constants::CONTINUEGAME_MENU_OPTION);
      options.push_back(Constants::NEWGAME_MENU_OPTION);
      options.push_back(Constants::MAINMENU_MENU_OPTION);
      options.push_back(Constants::QUITGAME_MENU_OPTION);
    }
  if(type==MenuType::Main)
    {
      options.push_back(Constants::STARTGAME_MENU_OPTION);
      options.push_back(Constants::OPTIONS_MENU_OPTION);
      options.push_back(Constants::ABOUT_MENU_OPTION);
      options.push_back(Constants::QUITGAME_MENU_OPTION);
    }
  if(type==MenuType::About)
    {
      options.push_back(Constants::BACK_MENU_OPTION);
    }
  if(type==MenuType::Settings)
    {
      options.push_back(Constants::SPEED_MENU_OPTION);
      options.push_back(Constants::WIN_THRESHOLD_OPTION);
      options.push_back(Constants::SOUND_TOGGLE_OPTION);
      options.push_back(Constants::BACK_MENU_OPTION);      
    }
}
