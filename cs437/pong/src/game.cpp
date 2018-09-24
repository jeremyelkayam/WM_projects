/*
  game.cpp
  Purpose: A class storing all game properties in a singular location for
  easy access by any class that needs them.
 */

#include <random>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "game.hpp"
#include "ball.hpp"
#include "constants.hpp"
#include "sound_player.hpp"

using namespace std;

//Constructor for the Game class
Game::Game(double x,double y,GameState state)
{
  starting_angle_rng.seed(std::random_device()());

  srand(time(0));
  
  this->ball=new Ball(random_angle(),Constants::BALL_SPEED,x/2,y/2);
  this->p1_paddle=new Paddle(Constants::COMPUTER_PLAYER_SPEED,0,y/2,y/10,y,5);
  this->p2_paddle=new Paddle(Constants::HUMAN_PLAYER_SPEED,0,y/2,y/10,y,5);
  this->menu=new Menu(MenuType::Main,0);
  this->p1score=0;
  this->p2score=0;
  this->x_dimension=x;
  this->y_dimension=y;
  this->current_state=state;
}

//Destructor for Game
Game::~Game()
{
  delete(menu);
  delete(p2_paddle);
  delete(p1_paddle);
  delete(ball);
}

//Increments p1 score, and ends game if p1 won
void Game::increment_p1_score()
{
  p1score++;
  if(p1score==Constants::WIN_SCORE)
    {
      this->set_state(GameState::EndScreen);
    }
  else
    {
      SoundPlayer::play_computer_score();
    }
}
//Increments p2 score, ending the game if p2 won
void Game::increment_p2_score()
{
  p2score++;
  if(p2score==Constants::WIN_SCORE)
    {
      this->set_state(GameState::EndScreen);
    }
  else
    {
      SoundPlayer::play_player_score();
    }
}
//Resets gameplay, beginning a new round.
void Game::new_round()
{

  ball->set_xcor(x_dimension/2);
  ball->set_ycor(y_dimension/2);
  ball->set_angle(random_angle());
  set_state(GameState::NewRound);
}
//Generates a new random angle according to specifications.
double Game::random_angle()
{
  std::uniform_real_distribution<double>angle_unif(Constants::BALL_MIN_ANGLE,Constants::BALL_MAX_ANGLE);

  double random_angle=angle_unif(starting_angle_rng);

  if(rand() % 2)
    {
      random_angle = M_PI - random_angle;
    }
  if(rand() % 2)
    {
      random_angle = - random_angle;
    }
  
  return random_angle;
}

//Sets the game state to the corresponding state.
void Game::set_state(GameState new_state)
{
  if(new_state==GameState::CountDown)
    {
      this->countdown=Constants::COUNTDOWN_START;
      SoundPlayer::play_three();
    }
  else if(new_state==GameState::EndScreen)
    {
      menu->set_type(MenuType::Finish);
      SoundPlayer::play_game_set();
    }
  else if(new_state==GameState::Paused)
    {
      menu->set_type(MenuType::Pause);
    }
  else if(new_state==GameState::MainMenu)
    {
      menu->set_type(MenuType::Main);
    }
  else if(new_state==GameState::AboutScreen)
    {
      menu->set_type(MenuType::About);
    }
  else if(new_state==GameState::Settings)
    {
      menu->set_type(MenuType::Settings);
    }
  
  this->current_state=new_state;
}
//Resets all game properties and restarts the game.
void Game::restart_game()
{
  p1_paddle->set_ycor(y_dimension/2);
  p2_paddle->set_ycor(y_dimension/2);
  
  p1score=0;
  p2score=0;
  new_round();
}

//Returns the game menu.
Menu *Game::get_menu()
{
  /*
    you should only need the menu if we're in a menu state.
    if you're asking for the menu and we're not in a menu state,
    there are other problems we should be dealing with.
  */
  assert(current_state==GameState::EndScreen ||
	 current_state==GameState::Paused ||
	 current_state==GameState::MainMenu ||
	 current_state==GameState::AboutScreen ||
	 current_state==GameState::Settings &&
	 "Game should be in a menu state when calling get_menu");
  return this->menu;
}
//Returns place in the countdown.
int Game::get_countdown()
{
  assert(current_state==GameState::CountDown);
  return this->countdown;
}
