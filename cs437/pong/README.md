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
- About screen displaying game information.

### Planned features/potential ideas and goals
- _settings screen and improved ai are the main improvements to be made here_
- ___refactor into human view, ai view, and game logic classes___-- potentially combining game and logic classes??
  - "if you're not doing it this way, you're not doing it right"
- use smart pointers!! they're pointers with garbage collection(basically?). less new's also
- proper tear down (delete your new's in reverse order of allocation).
- __check for memory leaks (valgrind)__.
- event processing should incorporate into game logic
- functions that take no args should take void to be more explicit (e.g. foo() -> foo(void))
- only take input if window has focus.
  - potentially: don't play at all if window doesn't have focus
- experiment with resizing, make it work better
- better AI (more realistic). Make it fuck up sometimes. Under or overshoot the ball.
  - tweak it more
- end messages referring to the player and computer instead of just "player 1" and "player 2"
 - player name stored in variable?
- Options Screen with adjustable options.
  - turn AI on/off for each side? i.e. 2 AI players, 2 human players, or one each
  - adjustable speed slider?
  - points required to win?
  - configurable controls?
  - sounds on/off?
- cheesy sound effects?
- acceleration of paddle (the Paddle class already stores an unused acceleration!)
- When bouncing off of a paddle, a ball could have a deterministic perturbation, affected
by the magnitude and direction of the paddle's velocity.
- more/better documentation
- Proper file-not-found errors __and errors in general, for example constructor errors__
- Make the about screen look nicer.
- text factory?
