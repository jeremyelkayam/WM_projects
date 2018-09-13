/*
  game.cpp
  Purpose: A singleton, storing all game properties in a singular class for
  easy access by any class that needs them.
 */

#include <random>
#include "game.hpp"
#include "ball.hpp"

Game::Game(double x,double y)
{
  starting_angle_rng.seed(std::random_device()());

  std::uniform_real_distribution<double>unif(0,2*M_PI);

  this->ball=new Ball(unif(starting_angle_rng),.004,x/2,y/2);
  this->p1_paddle=new Paddle(.005,0,y/2,y/10);
  this->p2_paddle=new Paddle(.005,0,y/2,y/10);
  this->p1score=0;
  this->p2score=0;
  this->x_dimension=x;
  this->y_dimension=y;
}

void Game::increment_p1_score()
{
  p1score++;
}

void Game::increment_p2_score()
{
  p2score++;
}

void Game::new_round()
{
  std::uniform_real_distribution<double>unif(0,2*M_PI);

  ball->set_xcor(x_dimension/2);
  ball->set_ycor(y_dimension/2);
  ball->set_angle(unif(starting_angle_rng));

  
}
