/*
  menu.hpp
  Purpose:
  
  @authoer Jeremy Elkayam
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

using namespace std;

/*
  Used to denote the various menus used by the game.

  Main: the main menu, displayed when the game executable runs.
  Finish: the menu on the end screen, displayed when one player
          reaches the amount of points required to win a game.
  Pause: the pause menu, displayed when the user pauses
         gameplay.
  About: the about menu, accessible from the main menu,
         displaying information about the creation of the game.
  Settings: the settings menu, accessible from the main menu,
            allowing the user to modify various game settings.
 */
enum class MenuType { Main, Finish, Pause, About, Settings };

class Menu
{
private:
  //The current type of this menu.
  MenuType type;
  //Stores the current menu's options.
  vector <string> options;
  //Stores the index of the option currently selected.
  int selection;
public:
  /*
    Constructor for the menu. Sets the menu to the given
    type and the selection to the default selection given.
   */
  Menu(MenuType type, int default_selection);
  /*
    If there are options below the currently selected one,
    moves the selected option down by one.
   */
  void move_down();
  /*
    If there are options above the currently selected one,
    moves the selected option up by one.
   */
  void move_up();

  
  /*
    Sets the type of the menu to the type given by clearing
    the menu's options and adding the options corresponding to
    the given type. Resets the selected option to 0.
   */
  void set_type(MenuType type);

  /*
    Returns the index of the selected option.
    
    @return the currently selected option's index.
   */
  int get_selection(){return selection;}
  
  /*
    Returns the vector storing the menu's current options.

    @return a vector with the menu's options.
   */
  vector <string> get_options(){return options;}

  /*
    Returns the option currently selected.

    @return the text of the currently selected option.
   */
  string get_selected_option(){return options[selection];}
};


#endif
