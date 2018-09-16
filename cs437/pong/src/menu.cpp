/*
  menu.cpp
  Purpose:

  @author Jeremy Elkayam
 */
#include "menu.hpp"

using namespace std;

Menu::Menu(MenuType type, int default_selection)
{
  this->type=type;
  if(type==MenuType::Finish)
    {
      options.push_back("New Game");
      options.push_back("Main Menu");
      options.push_back("Quit");
    }
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
