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

Logic::~Logic()
{
  delete(cp);
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

	  keyboard_paddle_movement(micros_elapsed*game->get_time_multiplier());
	  
	  total_time+=micros_elapsed;
	  
	  if(total_time>Constants::COUNTDOWN_INTERVAL)
	    {
	      game->decrement_countdown();
	      if(game->get_countdown()==2)
		{
		  SoundPlayer::play_two();
		}
	      else if(game->get_countdown()==1)
		{
		  SoundPlayer::play_one();
		}
	      else if(game->get_countdown()==0)
		{
		  SoundPlayer::play_go();
		}
	      total_time=0;
	      //cout << "new total time: " <<total_time << "\n";
	    }
	}
    }
  else if(state==GameState::Playing)
    { 
      micros_elapsed*=game->get_time_multiplier();
       //TODO: separate this into more functions?
      keyboard_paddle_movement(micros_elapsed);
      
      if(ball_above_screen() || ball_below_screen())
	{
	  top_bottom_bounce();
	}

      if((game->get_ball()->get_x_velocity()<0 && ball_hit_p1_paddle()) ||
	 (game->get_ball()->get_x_velocity()>0 && ball_hit_p2_paddle()))
	{
          left_right_bounce();
	}
      if(ball_past_left_side() || ball_past_right_side())
	{
	  player_score_point(ball_past_right_side());
	  if(game->get_current_state()!=GameState::EndScreen)
	    {
	      start_new_round();
	    }
	  
	}
      
      this->cp->update(micros_elapsed);
      
      this->game->get_ball()->move(micros_elapsed);
    }
  else if(state==GameState::MainMenu ||
	  state==GameState::AboutScreen ||
	  state==GameState::Settings)
    {
      if(state==GameState::Settings)
	{
	  micros_elapsed*=game->get_time_multiplier();
	}
      
      if(ball_above_screen() || ball_below_screen())
	{
	  top_bottom_bounce();
	}
      if((game->get_ball()->get_x_velocity()<0 && ball_hit_p1_paddle()) ||
	 (game->get_ball()->get_x_velocity()>0 && ball_hit_p2_paddle()))
	{
          left_right_bounce();
	}
      this->game->get_ball()->move(micros_elapsed);

      //if(game->get_ball()->get_x_velocity() > 0)
      //{
      paddle_follow_ball(game->get_p2_paddle(),micros_elapsed);
      //}
      //else
      //{
      paddle_follow_ball(game->get_p1_paddle(),micros_elapsed);
      //}
    }
}

void Logic::paddle_follow_ball(Paddle *paddle,int micros_elapsed)
{
  double ball_x=this->game->get_ball()->get_xcor();
  double ball_y=this->game->get_ball()->get_ycor();  
  if(ball_y < paddle->get_center())
    {
      paddle->move(micros_elapsed,Paddle::Direction::Up);
    }
  if(ball_y > paddle->get_center())
    {
      paddle->move(micros_elapsed,Paddle::Direction::Down);
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
  return ball_x() < 0;
}

bool Logic::ball_past_right_side()
{
  return ball_x() > game->get_x_dimension() + 50;
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
      double ball_ycor=game->get_ball()->get_ycor();
      double ball_xcor=game->get_ball()->get_xcor();
      Paddle *paddle;
      paddle=game->get_p1_paddle();
      return (ball_xcor > 0 &&
	      ball_xcor < paddle->get_width() &&
	      ball_ycor > paddle->get_ycor() &&
	      ball_ycor < paddle->get_ycor()+paddle->get_height());
  return false;
}


bool Logic::ball_hit_p2_paddle()
{
      double ball_ycor=game->get_ball()->get_ycor();
      double ball_xcor=game->get_ball()->get_xcor();
      Paddle *paddle;
      paddle=game->get_p2_paddle();
      return (ball_xcor < game->get_x_dimension() &&
	      ball_xcor > game->get_x_dimension() - 5 && 
	      ball_ycor > paddle->get_ycor()-Constants::PADDLE_BOUNCE_TOLERANCE &&
	      ball_ycor < paddle->get_ycor()+paddle->get_height()+Constants::PADDLE_BOUNCE_TOLERANCE);
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
  string selected=game->get_menu()->get_selected_option();
  if(event.key.code == sf::Keyboard::Up)
    {
      game->get_menu()->move_up();
    }
  else if(event.key.code == sf::Keyboard::Down)
    {
      game->get_menu()->move_down();		  
    }
  else if(event.key.code == sf::Keyboard::Left)
    {
      if(selected == Constants::SPEED_MENU_OPTION && game->get_speed_index() > 0)
	{
	  game->decrement_speed_index();
	  game->set_time_multiplier(Constants::SPEED_VALUES[game->get_speed_index()]);
	}
      else if(selected == Constants::WIN_THRESHOLD_OPTION &&
	      Constants::WIN_SCORE > 1)
	{
	  Constants::WIN_SCORE--;
	}
    }
  else if(event.key.code == sf::Keyboard::Right)
    {
      if(selected == Constants::SPEED_MENU_OPTION
	 && game->get_speed_index() < Constants::SPEED_VALUES.size()-1)
	{
	  game->increment_speed_index();
	  game->set_time_multiplier(Constants::SPEED_VALUES[game->get_speed_index()]);
	}
      else if(selected == Constants::WIN_THRESHOLD_OPTION)
	{
	  Constants::WIN_SCORE++;
	}
    }
  else if(event.key.code == sf::Keyboard::Return)
    {
      if(selected==Constants::QUITGAME_MENU_OPTION)
	{
	  SoundPlayer::play_menu_select();
	  App->close();
	}
      else if(selected == Constants::NEWGAME_MENU_OPTION ||
	      selected == Constants::STARTGAME_MENU_OPTION)
	{
	  SoundPlayer::play_menu_select();
	  game->restart_game();
	}
      else if(selected==Constants::CONTINUEGAME_MENU_OPTION)
	{
	  SoundPlayer::play_menu_select();
	  game->set_state(GameState::Playing);
	}
      else if(selected==Constants::MAINMENU_MENU_OPTION ||
	      selected==Constants::BACK_MENU_OPTION)
	{
	  SoundPlayer::play_menu_select();
	  //cout << "going to main menu\n";
	  game->set_state(GameState::MainMenu);
	}
      else if(selected==Constants::ABOUT_MENU_OPTION)
	{
	  SoundPlayer::play_menu_select();
	  game->set_state(GameState::AboutScreen);
	}
      else if(selected==Constants::OPTIONS_MENU_OPTION)
	{
	  SoundPlayer::play_menu_select();
	  game->set_state(GameState::Settings);
	}
    }
}
