# Pong (working title)
Pong game by Jeremy Elkayam, made in SFML

## Project Requirements
- ~~The game should be played in an 800x600 window. Changing the size of the window should be disabled
__(10%)__.~~
_Completed!_
- ~~A well-defined game loop that coordinates game timing and event management __(20%)__.~~ _Completed!_
- ~~A single player version should be implemented where the user controls a single paddle __(15%)__,
and the computer the other paddle __(15%)__.~~ _Completed!_
- ~~The paddle can be moved by keyboard or mouse (one method of control is sufficient). The paddle
of both the player and the AI should move at a constant speed.~~
- ~~A ball should bounce of the top and bottom edge of the playfield and the direction of the ball should
change to the reflected direction __(15%)__.~~
_Completed!_
~~To add an element of uncertainty, a small random perturbation
could be added/subtracted from the reflected direction __(5%)__.~~
_Completed!_
- ~~A player scores when the ball hits the edge of the competitors’ side __(5%)__.~~
_Completed!_
- ~~The game starts with both players having zero points, and ends when one player reaches 11 
points. A message should be shown to indicate whether the player won or lost.  The player 
should have the option to restart the game or quit __(10%)__.~~ _Completed!_
- ~~The current score should be shown in the window __(5%)__.~~ _Completed!_


### Completed Requirements
- 800x600 game window with resizing disabled
- Ball that bounces on contact with top and bottom of screen, with angle reflected
- Random perturbation ranging from -0.1 to 0.1 radians upon bouncing off the top/bottom of the screen
- Single player-controlled paddle that the ball can bounce off of.
- Players score a point when a ball hits the opposing side's edge.
- Both players start with 0 points.
- Game displays point values on-screen.
- Game loop incorporating event handling, logic, and rendering

## Bonus Features
- At the beginning of each round, game waits for player input and counts down before starting gameplay
- Game can be paused during gameplay using the escape key
- Title Screen

### Planned features/potential ideas and goals
- better AI (more realistic). Make it fuck up sometimes. Under or overshoot the ball.
It should be beatable without forcing it to have a much lower speed than the player's paddle.
  - Also: it should try to use all or none of its movement speed. None of this pressing and
  releasing the keys to make it seem slower or faster. I will get points docked if both paddles
  don't move at constant speed.
  - idea: calculate where the ball is going, based on speed and location. if it's heading toward the ai's edge of the screen, aim for where the ball is going, but not exactly where it's going. add a random, mild perturbation so that the ai can over or undershoot the ball.
- end messages referring to the player and computer instead of just "player 1" and "player 2"
 - player name stored in variable?
- Title Screen with adjustable options.
  - turn AI on/off for each side? i.e. 2 AI players, 2 human players, or one each
  - adjustable speed slider?
  - points required to win?
  - configurable controls?
  - sounds on/off?
- cheesy sound effects?
- acceleration of paddle (the Paddle class already stores an unused acceleration!)
- When bouncing off of a paddle, a ball could have a deterministic perturbation, affected
by the magnitude and direction of the paddle's velocity.
- constants and strings contained in a single class (constants.hpp?)
- more/better documentation
