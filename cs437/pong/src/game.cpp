/*
  game.cpp
  Purpose: A singleton, storing all game properties in a singular class for
  easy access by any class that needs them.
 */

#include <random>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "game.hpp"
#include "ball.hpp"

using namespace std;

Game::Game(double x,double y,GameState state)
{
  starting_angle_rng.seed(std::random_device()());

  srand(time(0));
  
  this->ball=new Ball(random_angle(),.008,x/2,y/2);
  this->p1_paddle=new Paddle(.02,0,y/2,y/10,y);
  this->p2_paddle=new Paddle(.013,0,y/2,y/10,y);
  this->menu=new Menu(MenuType::Main,0);
  this->p1score=0;
  this->p2score=0;
  this->x_dimension=x;
  this->y_dimension=y;
  this->current_state=state;
}

void Game::increment_p1_score()
{
  if(p1score==10)
    {
      this->set_state(GameState::EndScreen);
    }
  p1score++;
}

void Game::increment_p2_score()
{
  if(p2score==10)
    {
      this->set_state(GameState::EndScreen);
    }
  p2score++;
}

void Game::new_round()
{

  ball->set_xcor(x_dimension/2);
  ball->set_ycor(y_dimension/2);
  ball->set_angle(random_angle());
  set_state(GameState::NewRound);
}

double Game::random_angle()
{
  std::uniform_real_distribution<double>angle_unif((M_PI/7),(3*M_PI/7));

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

void Game::set_state(GameState new_state)
{
  if(new_state==GameState::CountDown)
    {
      this->countdown=3;
    }
  else if(new_state==GameState::EndScreen)
    {
      menu->set_type(MenuType::Finish);
    }
  else if(new_state==GameState::Paused)
    {
      menu->set_type(MenuType::Pause);
    }
  else if(new_state==GameState::MainMenu)
    {
      menu->set_type(MenuType::Main);
    }
  
  this->current_state=new_state;
}

void Game::restart_game()
{
  p1_paddle->set_ycor(y_dimension/2);
  p2_paddle->set_ycor(y_dimension/2);
  
  p1score=0;
  p2score=0;
  new_round();
}
