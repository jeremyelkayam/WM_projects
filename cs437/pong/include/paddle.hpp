/*
  paddle.hpp
  Purpose: Simulate a paddle and store its properties.

  @author Jeremy Elkayam
  */
#ifndef PADDLE_HPP
#define PADDLE_HPP


class Paddle
{
private:
  /*
    speed: the speed of the paddle's movement in pixels per microsecond.
    accel: the acceleration of the paddle in pixels per microsecond per microsecond. 
           Curently unused.
    ycor: the y-coordinate of the paddle in pixels.
    height: the height of the paddle in pixels.
    width: the width of the paddle in pixels.
    max_ycor: the maximum y-coordinate of the game playing field.
   */
  double speed,accel,ycor,height,width,max_ycor;

public:
  /*
    Denotes movement direction.
    Up: Move upward.
    Down: Move downward.
   */
  enum class Direction { Up, Down };

  /*
    This class's constructor. Sets up class values as given.
        
    @param speed the speed of the paddle's movement in pixels per microsecond.
    @param accel the acceleration of the paddle in pixels per microsecond per microsecond. 
           Curently unused.
    @param ycor the y-coordinate of the paddle in pixels.
    @param height the height of the paddle in pixels.
    @param width the width of the paddle in pixels.
    @param max_ycor the maximum y-coordinate of the game playing field.
   */
  Paddle(double speed, double accel, double ycor, double height, double max_ycor,double width);

  /*
    Sets the paddle's speed to the given speed.
    
    @param speed The speed of the paddle in pixels per microsecond.
   */
  void set_speed(double speed){this->speed=speed;}
  /*
    Sets the paddle's acceleration to the given acceleration.
    
    @param speed The desired acceleration of the paddle in pixels
                 per microsecond per microsecond.
   */
  void set_accel(double accel){this->accel=accel;}
  /*
    Sets the paddle's y-coordinate to the given y-coordinate..
    
    @param speed The desired y-coordinate of the paddle in pixels.
   */
  void set_ycor(double ycor){this->ycor=ycor;}
  /*
    Sets the paddle's height to the given height.
    
    @param speed The desired height of the paddle in pixels.
   */
  void set_height(double height){this->height=height;}
  /*
    Sets the paddle's width to the given width.
    
    @param speed The desired width of the paddle in pixels.
   */
  void set_width(double width){this->width=width;}

  /*
    Returns the y-coordinate of the paddle.
    
    @return the paddle's y-coordinate in pixels
   */
  double get_ycor(){return this->ycor;}
  /*
    Returns the height of the paddle.
    
    @return the paddle's height in pixels
   */
  double get_height(){return this->height;}
  /*
    Returns the width of the paddle.
    
    @return the paddle's width in pixels
   */
  double get_width(){return this->width;}
  /*
    Returns the center of the paddle.
    
    @return the paddle's center in pixels
   */
  double get_center();

  /*
    Moves the paddle in the desired direction, based on
    how many microseconds elapsed since the previous loop.

    @param micros_elapsed The number of microseconds since the previous loop
    @param dir The direction in which the paddle should move.
   */
  void move(int micros_elapsed, Direction dir);
  
};

#endif
