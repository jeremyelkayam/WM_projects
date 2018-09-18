/*
  logic.cpp
  Purpose: Handle the logic computations of the game's main loop
           (e.g. controls, collison detection, etc).

  @author Jeremy Elkayam
 */

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "logic.hpp"
#include "paddle.hpp"
#include "sound_player.hpp"
#include "constants.hpp"

using namespace std;

Logic::Logic(Game *game)
{
  this->game=game;
  this->cp=new ComputerPlayer(game);
  this->total_time=0;
}

void Logic::update(int micros_elapsed)
{
  GameState state=game->get_current_state();

  if(state==GameState::CountDown)
    {
      if(game->get_countdown()==0)
	{
	  game->set_state(GameState::Playing);
	}
      else
	{

	  keyboard_paddle_movement(micros_elapsed);
	  
	  total_time+=micros_elapsed;
	  
	  if(total_time>Constants::COUNTDOWN_INTERVAL)
	    {
	      //cout << "decrementing countdown\ntotal time: " <<total_time << "\n";
	      game->decrement_countdown();
	      total_time=0;
	      //cout << "new total time: " <<total_time << "\n";
	    }
	}
    }
  else if(state==GameState::Playing)
    {

      //TODO: separate this into more functions?
      keyboard_paddle_movement(micros_elapsed);
      
      if(ball_above_screen() || ball_below_screen())
	{
	  top_bottom_bounce();
	}
      
      if(ball_past_left_side() || ball_past_right_side())
	{
	  if((ball_hit_p1_paddle() && ball_past_left_side())
	     || (ball_hit_p2_paddle() && ball_past_right_side()))
	{
	  left_right_bounce();
	}
	  else{
	    player_score_point(ball_past_right_side());
	    if(game->get_current_state()!=GameState::EndScreen)
	      {
		start_new_round();
	      }
	  }
	}
      
      this->cp->update(micros_elapsed);
      
      this->game->get_ball()->move(micros_elapsed);
    }
}

bool Logic::ball_above_screen()
{
  return ball_y()<0;
}

bool Logic::ball_below_screen()
{
  return ball_y()>game->get_y_dimension();
}


bool Logic::ball_past_left_side()
{
  return ball_x()<0;
}

bool Logic::ball_past_right_side()
{
  return ball_x()>game->get_x_dimension();
}

void Logic::top_bottom_bounce()
{
  double screen_edge;
  if(ball_above_screen())
    {
      screen_edge=0;
    }
  else if(ball_below_screen())
    {
      screen_edge=game->get_y_dimension();
    }
      
  /*
    set ball to being exactly on the screen's edge, to prevent ball being too
    far offscreen and causing unnecessary calls to reflect_x().
  */
  this->game->get_ball()->set_ycor(screen_edge);
  
  this->game->get_ball()->reflect_x();
}

void Logic::left_right_bounce()
{
  double screen_edge;
  if(ball_past_left_side())
    {
      screen_edge=0;
    }
  else if(ball_past_right_side())
    {
      screen_edge=game->get_x_dimension();
    }

  this->game->get_ball()->set_xcor(screen_edge);
  
  this->game->get_ball()->reflect_y();
}
 

void Logic::player_score_point(bool player_one_scored)
{
  if(player_one_scored)
    {
      game->increment_p1_score();
    }
  else
    {
      game->increment_p2_score();
    }
}

void Logic::start_new_round()
{
  if(game->get_current_state()==GameState::Playing)
    {
      game->new_round();
    }
}

bool Logic::ball_hit_p1_paddle()
{
  if(ball_past_left_side())
    {
      double ball_ycor=game->get_ball()->get_ycor();
      Paddle *paddle;
      paddle=game->get_p1_paddle();
      return (ball_ycor>paddle->get_ycor() &&
	      ball_ycor<paddle->get_ycor()+paddle->get_height());
    }
  return false;
}


bool Logic::ball_hit_p2_paddle()
{
  if(ball_past_right_side())
    {
      double ball_ycor=game->get_ball()->get_ycor();
      Paddle *paddle;
      paddle=game->get_p2_paddle();
      return (ball_ycor>paddle->get_ycor()-Constants::PADDLE_BOUNCE_TOLERANCE &&
	      ball_ycor<paddle->get_ycor()+paddle->get_height()+Constants::PADDLE_BOUNCE_TOLERANCE);
    }
  return false;
}

void Logic::keyboard_paddle_movement(int micros_elapsed)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      game->get_p2_paddle()->move(micros_elapsed,Paddle::Direction::Up);
    }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      game->get_p2_paddle()->move(micros_elapsed,Paddle::Direction::Down);
    }
}

void Logic::handle_menu_event(sf::Event event, sf::RenderWindow *App)
{
  if(event.key.code == sf::Keyboard::Up)
    {
      game->get_menu()->move_up();
    }
  else if(event.key.code == sf::Keyboard::Down)
    {
      game->get_menu()->move_down();		  
    }
  else if(event.key.code == sf::Keyboard::Return)
    {
      string selected=game->get_menu()->get_selected_option();
      if(selected==Constants::QUITGAME_MENU_OPTION)
	{
	  App->close();
	}
      else if(selected == Constants::NEWGAME_MENU_OPTION ||
	      selected == Constants::STARTGAME_MENU_OPTION)
	{
	  game->restart_game();
	}
      else if(selected==Constants::CONTINUEGAME_MENU_OPTION)
	{
	  game->set_state(GameState::Playing);
	}
      else if(selected==Constants::MAINMENU_MENU_OPTION ||
	      selected==Constants::BACK_MENU_OPTION)
	{
	  //cout << "going to main menu\n";
	  game->set_state(GameState::MainMenu);
	}
      else if(selected==Constants::ABOUT_MENU_OPTION)
	{
	  game->set_state(GameState::AboutScreen);
	}
    }
}
