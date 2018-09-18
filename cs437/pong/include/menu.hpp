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

enum class MenuType { Main, Finish, Pause, About };

class Menu
{
private:
  MenuType type;
  vector <string> options;
  int selection;
public:
  Menu(MenuType type, int default_selection);
  void move_down();
  void move_up();
  void select();

  void set_type(MenuType type);

  int get_selection(){return selection;}
  vector <string> get_options(){return options;}
  string get_selected_option(){return options[selection];}
};


#endif
