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

Game::Game(double x,double y)
{
  starting_angle_rng.seed(std::random_device()());

  srand(time(0));
  
  this->ball=new Ball(random_angle(),.006,x/2,y/2);
  this->p1_paddle=new Paddle(.01,0,y/2,y/10);
  this->p2_paddle=new Paddle(.01,0,y/2,y/10);
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

  ball->set_xcor(x_dimension/2);
  ball->set_ycor(y_dimension/2);
  ball->set_angle(random_angle());
  
}

double Game::random_angle()
{
  std::uniform_real_distribution<double>angle_unif((-3*M_PI/7),(3*M_PI/7));

  double random_angle=angle_unif(starting_angle_rng);

  if(rand() % 2)
    {
      random_angle = M_PI - random_angle;
    }
  
  return random_angle;
}
