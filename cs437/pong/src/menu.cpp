/*
  menu.cpp
  Purpose:

  @author Jeremy Elkayam
 */
#include "menu.hpp"

using namespace std;

Menu::Menu(MenuType type, int default_selection)
{
  set_type(type);
  selection=default_selection;
}

void Menu::move_down()
{
  if(selection+1<options.size())
    {
      selection++;
    }
}
void Menu::move_up()
{
  if(selection-1>-1)
    {
      selection--;
    }
}
void Menu::select()
{
  
}

void Menu::set_type(MenuType type)
{
  this->type=type;
  this->options.clear();
  if(type==MenuType::Finish)
    {
      options.push_back("New Game");
      options.push_back("Main Menu");
      options.push_back("Quit");
    }
  else if(type==MenuType::Pause)
    {
      options.push_back("Continue");
      options.push_back("New Game");
      options.push_back("Main Menu");
      options.push_back("Quit");
    }
  if(type==MenuType::Main)
    {
      options.push_back("Start Game");
      options.push_back("Main Menu");
      options.push_back("Quit");
    }
}
