/*
  logic.hpp
  Purpose: Handle the logic computations of the game's main loop
           (e.g. controls, collison detection, etc).

  @author Jeremy Elkayam
 */
#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "computer_player.hpp"

class Logic
{
private:
  //A reference to the class storing the game properties.
  Game *game;
  //A reference to the computer player's class.
  ComputerPlayer *cp;
  //Stores the total time elapsed when waiting between counts of the countdown.
  int total_time;
  //Stores the current index in the array of potential multipliers for the game's speed.
  int speed_index=3;

  /*
    Returns whether or not the ball is off-screen, specifically, whether or not
    it is further left than the screen's left edge.

    @return true if the ball's x-coordinate is past the left side of the screen.
            false otherwise.
  */
  bool ball_past_left_side();
  /*
    Returns whether or not the ball is off-screen, specifically, whether or not
    it is further right than the screen's right edge.

    @return true if the ball's x-coordinate is past the right side of the screen,
            false otherwise.
   */
  bool ball_past_right_side();
  /*
    Returns whether or not the ball is off-screen, specifically, whether or not
    it is further up than the screen's top edge.

    @return true if the ball's y-coordinate is past the top side of the screen,
            false otherwise.
   */
  bool ball_above_screen();
  /*
    Returns whether or not the ball is off-screen, specifically, whether or not
    it is further down than the screen's bottom edge.

    @return true if the ball's y-coordinate is past the bottom side of the screen,
            false otherwise.
   */
  bool ball_below_screen();
  /*
    Returns whether or not the ball currently interescts with the boundaries
    of P1's paddle.

    @return true if the ball is intersecting with the boundaries of p1_paddle,
            false otherwise.
   */
  bool ball_hit_p1_paddle();
  /*
    Returns whether or not the ball currently interescts with the boundaries
    of P1's paddle.

    @return true if the ball is intersecting with the boundaries of p1_paddle,
            false otherwise.
   */
  bool ball_hit_p2_paddle();

  /*
    Shortcut for getting the ball's x-coordinate.
    @return the x-coordinate of the ball in pixels.
   */
  double ball_x(){return this->game->get_ball()->get_xcor();}
  /*
    Shortcut for getting the ball's y-coordinate.
    @return the x-coordinate of the ball in pixels.
   */
  double ball_y(){return this->game->get_ball()->get_ycor();}

  /*
    If the ball is past the top or bottom of the screen, simulate
    the ball bouncing off of the top or bottom, by reflecting its
    velocity in the x-axis, making it travel away from the border
    that it just touched.
   */
  void top_bottom_bounce();
  /*
    Simulates a bounce off of a surface to the left or right of
    the ball by reflecting its velocity over the y-axis.
   */
  void left_right_bounce();
  /*
    Increments the score of player one if player_one_scored
    is true, else increment that of player two.

    @param player_one_scored True if player one scored a point, false otherwise
   */
  void player_score_point(bool player_one_scored);
  /*
    Starts new round, setting game state to a new round state
    and setting ball and paddle values to their initial states.
   */
  void start_new_round();
  /*
    Checks for input from the keyboard, and moves the player 2 paddle
    accordingly. The paddle moves up if the player presses the up arrow,
    and down if the player presses the down arrow.

    @param micros_elapsed the time elapsed since the last game loop
                          in microseconds.
   */
  void keyboard_paddle_movement(int micros_elapsed);
  /*
    Tells the given paddle to follow the movement of the ball 
    (e.g. if the ball is above the paddle, move up, if it's below,
    move down)

    @param paddle The paddle to which input should be given.
    @param micros_elapsed the time elapsed since the last game loop
                          in microseconds.
   */
  void paddle_follow_ball(Paddle *paddle,int micros_elapsed);
public:
  /*
    Constructor for the Logic class.
    Sets up the initial values of the class.
    
    @param game the class storing game properties.
   */
  Logic(Game *game);

  /*
    Destructor for the Logic class, freeing up heap memory 
    that the Logic class allocated during its life.
   */
  ~Logic();

  /*
    Run all elements of the game according to the game logic
    and current state. Runs once per game loop.

    `@param micros_elapsed the amount of time elapsed since the
                           last game loop in microseconds.
   */
  void update(int micros_elapsed);
  /*
    When on a menu screen, this function takes the context of 
    the game state and selected menu option, and performs logic
    accordingly.

    @param event the event that the function should be responding to
    @param App a reference to the RenderWindow that the game is being
               viewed through.
  */
  void handle_menu_event(sf::Event event, sf::RenderWindow *App);
};

#endif
