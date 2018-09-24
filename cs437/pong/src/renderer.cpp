/*
  view.cpp
  Purpose: 

  @author Jeremy Elkayam
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "constants.hpp"

using namespace std;

Renderer::Renderer(Logic *logic,Game *game, sf::RenderWindow *window)
{
  this->game=game;
  this->window=window;
  this->logic=logic;

  //idea - make set_up_font(), set_up_ball(), etc. methods for this?
  if (!this->pixel_font.loadFromFile(Constants::PIXEL_FONT_PATH))
    {
      //TODO - handle this error (immediate exit and popup saying file not found?)
    }
  if (!this->title_font.loadFromFile(Constants::TITLE_FONT_PATH))
    {
      //TODO - handle this error (immediate exit and popup saying file not found?)
    }
  ball.setRadius(Constants::BALL_RADIUS);
  
  p1_paddle.setSize(sf::Vector2f(Constants::PADDLE_RENDERED_WIDTH,game->get_p1_paddle()->get_height()));
  p2_paddle.setSize(sf::Vector2f(Constants::PADDLE_RENDERED_WIDTH,game->get_p2_paddle()->get_height()));

  speed_bar.setSize(sf::Vector2f(600,50));
  speed_selector.setSize(sf::Vector2f(50,100));

  speed_selector.setOutlineColor(sf::Color(100,100,100));
  speed_selector.setOutlineThickness(5);

  speed_bar.setOutlineColor(sf::Color(100,100,100));
  speed_bar.setOutlineThickness(5);
		    
  speed_bar.setPosition(100,window->getSize().y/2-25);
}

void Renderer::update()
{
  //clear window to prepare for rendering
  window->clear(Constants::BACKGROUND_COLOR);

  if(game->get_current_state()==GameState::MainMenu)
    {
      draw_main_menu();
    }
  else if(game->get_current_state()==GameState::AboutScreen)
    {
      draw_about_screen();
    }
  else if(game->get_current_state()==GameState::Settings)
    {
      draw_settings_menu();
    }
  else
    {
      draw_scores();
      
      if(game->get_current_state()==GameState::EndScreen)
	{
	  draw_end_menu();
	}
      else
	{
	  draw_paddles();
      
	  if(game->get_current_state()==GameState::NewRound)
	    {
	      draw_new_round_text();
	    }
	  else if(game->get_current_state()==GameState::CountDown)
	    {
	      draw_countdown_text();
	    }
	  else if(game->get_current_state()==GameState::Paused)
	    {
	      draw_pause_menu();
	    }
	  else
	    {
	      draw_ball();
	      if(logic->displaying_GO())
		{
		  draw_go_text();
		}
	    }
	}
    }
  window->display();
}


void Renderer::draw_ball(sf::Color color)
{
  ball.setPosition(window->getSize().x*(game->get_ball()->get_xcor()-Constants::BALL_RADIUS)/800,
		   window->getSize().y*(game->get_ball()->get_ycor()-Constants::BALL_RADIUS)/600);
  ball.setFillColor(color);

  window->draw(ball);
}

void Renderer::draw_scores()
{
  //set font for both score texts
  p1score.setFont(pixel_font);
  p2score.setFont(pixel_font);

  //set score texts to display respective scores
  p1score.setString(Constants::P1_SCORE_DISPLAY_BEGIN + to_string(game->get_p1_score()) + Constants::SCORE_DISPLAY_END);
  p2score.setString(Constants::P2_SCORE_DISPLAY_BEGIN + to_string(game->get_p2_score()) + Constants::SCORE_DISPLAY_END);

  p1score.setCharacterSize(Constants::SCORE_CHAR_SIZE);
  p2score.setCharacterSize(Constants::SCORE_CHAR_SIZE);

  set_origin_to_center(&p1score);
  set_origin_to_center(&p2score);
  
  p1score.setPosition(window->getSize().x*(Constants::P1_SCORE_XCOR)/800,
		      window->getSize().y*(Constants::P1_SCORE_YCOR)/600);
  p2score.setPosition(window->getSize().x*(Constants::P2_SCORE_XCOR)/800,
		      window->getSize().y*(Constants::P2_SCORE_YCOR)/600);

  window->draw(p1score);
  window->draw(p2score);
  
}

void Renderer::draw_paddles(sf::Color color)
{
  p1_paddle.setFillColor(color);
  p2_paddle.setFillColor(color);

  p1_paddle.setPosition(0,game->get_p1_paddle()->get_ycor());
  p2_paddle.setPosition(game->get_x_dimension()-Constants::PADDLE_RENDERED_WIDTH,game->get_p2_paddle()->get_ycor());

  window->draw(p1_paddle);
  window->draw(p2_paddle);			       
}

void Renderer::draw_new_round_text()
{
  new_round_text.setFont(pixel_font);

  new_round_text.setString(Constants::NEW_ROUND_TEXT);

  new_round_text.setCharacterSize(Constants::NEW_ROUND_CHAR_SIZE);

  set_origin_to_center(&new_round_text);
  
  new_round_text.setPosition(window->getSize().x/2,window->getSize().y-Constants::NEW_ROUND_YCOR_OFFSET);

  window->draw(new_round_text);
}

void Renderer::draw_countdown_text()
{
  countdown_text.setFont(pixel_font);

  countdown_text.setString(to_string(game->get_countdown()));

  int character_size;
  if(game->get_countdown()==3)
    {
      character_size=Constants::COUNTDOWN_CHAR_SIZE;
    }
  else if(game->get_countdown()==2)
    {
      character_size=2*Constants::COUNTDOWN_CHAR_SIZE;
    }
  else if(game->get_countdown()==1)
    {
      character_size=4*Constants::COUNTDOWN_CHAR_SIZE;
    }
  else if(game->get_countdown()==0)
    {
      return;
    }
  
  countdown_text.setCharacterSize(character_size);

  set_origin_to_center(&countdown_text);
  
  
  countdown_text.setPosition(window->getSize().x/2,window->getSize().y/2);
  window->draw(countdown_text);
}


void Renderer::draw_menu_text(int starting_ycor)
{
  vector <string> menu_options=game->get_menu()->get_options();
  int selection=game->get_menu()->get_selection();

  for(int z=0;z<menu_options.size();z++)
    {
      sf::Text option;
      option.setFont(pixel_font);
      
      option.setString(menu_options[z]);
      
      option.setCharacterSize(Constants::MENU_CHAR_SIZE);
      
      set_origin_to_center(&option);
      
      option.setPosition(window->getSize().x/2,starting_ycor+Constants::MENU_TEXT_OFFSET*z);

      if(z==game->get_menu()->get_selection())
	{
	  /*
	  option.setOutlineThickness(1);
	  option.setOutlineColor(sf::Color::White);
	  option.setFillColor(sf::Color::Black);
	  */
	  option.setFillColor(Constants::MENU_HIGHLIGHT_COLOR);
	}
      
      window->draw(option);
    }
}

void Renderer::draw_end_menu()
{
  
  string player_name;

  if(game->get_p1_score()>game->get_p2_score())
    {
      player_name=Constants::P1_NAME;
    }
  else
    {
      player_name=Constants::P2_NAME;
    }
  
  sf::Text finish_text;
  
  finish_text.setFont(pixel_font);
  
  finish_text.setString(player_name+Constants::WINS_TEXT);
  
  finish_text.setCharacterSize(Constants::FINISH_TEXT_CHAR_SIZE);
  
  set_origin_to_center(&finish_text);
      
  finish_text.setPosition(window->getSize().x/2,window->getSize().y/2);
  
  window->draw(finish_text);

  draw_menu_text(window->getSize().x/2);
}

void Renderer::draw_pause_menu()
{
  sf::Text paused_text;
  
  paused_text.setFont(pixel_font);
  
  paused_text.setString(Constants::PAUSE_TEXT);
  
  paused_text.setCharacterSize(Constants::PAUSE_TEXT_CHAR_SIZE);
  
  set_origin_to_center(&paused_text);
      
  paused_text.setPosition(window->getSize().x/2,window->getSize().y/2);
  
  window->draw(paused_text);

  draw_menu_text(window->getSize().y/2+Constants::PAUSE_MENU_OFFSET);
}

void Renderer::set_origin_to_center(sf::Text *text)
{
  sf::FloatRect textRect=text->getLocalBounds();
  text->setOrigin(textRect.left + textRect.width/2,
		  textRect.top + textRect.height/2);
}

void Renderer::draw_attract_mode()
{
  draw_ball(sf::Color(75,75,75));
  
  draw_paddles(sf::Color(75,75,75));
}

void Renderer::draw_main_menu()
{
  draw_attract_mode();
  
  sf::Text text;
  
  //TODO: set this to something easy and fun like Mumbo-SSK
  
  text.setFont(title_font);
  
  text.setString(Constants::TITLE_SCREEN_TITLE);
  
  text.setCharacterSize(Constants::TITLE_CHAR_SIZE);
  
  set_origin_to_center(&text);
      
  text.setPosition(window->getSize().x/2,Constants::TITLE_YCOR);
  
  window->draw(text);

  draw_menu_text(Constants::TITLE_MENU_YCOR);

  draw_version_author_texts();

}

void Renderer::draw_version_author_texts()
{
  sf::Text author_text,version_text;
  string author_str = (Constants::AUTHOR_PREFIX + " " +
		       Constants::RELEASE_YEAR + " " +
		       Constants::AUTHOR_NAME);
  
  author_text.setFont(pixel_font);
  version_text.setFont(pixel_font);

  author_text.setString(author_str);
  version_text.setString(Constants::VERSION_TEXT+Constants::VERSION_NUMBER);

  author_text.setCharacterSize(Constants::VERSION_AUTHOR_CHAR_SIZE);
  version_text.setCharacterSize(Constants::VERSION_AUTHOR_CHAR_SIZE);

  set_origin_to_bottom_left(&author_text);
  set_origin_to_bottom_right(&version_text);

  author_text.setPosition(0,window->getSize().y);
  version_text.setPosition(window->getSize().x,window->getSize().y);
  
  window->draw(author_text);
  window->draw(version_text);
}

void Renderer::set_origin_to_bottom_left(sf::Text *text)
{
  sf::FloatRect textRect=text->getLocalBounds();
  text->setOrigin(textRect.left,
		  textRect.top + textRect.height);
}

void Renderer::set_origin_to_bottom_right(sf::Text *text)
{
  sf::FloatRect textRect=text->getLocalBounds();
  text->setOrigin(textRect.left + textRect.width,
		  textRect.top + textRect.height);
}

void Renderer::draw_about_screen()
{
  draw_attract_mode();
  
  sf::Text about_title,about_text;

  about_title.setFont(title_font);

  about_title.setString(Constants::ABOUT_SCREEN_TITLE);
  
  about_title.setCharacterSize(Constants::ABOUT_TITLE_CHAR_SIZE);
  
  set_origin_to_center(&about_title);
      
  about_title.setPosition(window->getSize().x/2,Constants::ABOUT_TITLE_YCOR);
  
  window->draw(about_title);

  vector<string> about_body=Constants::ABOUT_SCREEN_TEXT;

  about_body.insert(about_body.begin(),
		    Constants::ABOUT_VERSION_NUMBER_PREFIX+Constants::VERSION_NUMBER);

  for(int z=0;z<about_body.size();z++)
    {
      about_text.setFont(pixel_font);

      about_text.setString(about_body[z]);
      
      about_text.setCharacterSize(Constants::ABOUT_TEXT_CHAR_SIZE);
      
      set_origin_to_center(&about_text);

      int blah=0;
      if(z!=0)
	{
	  blah=2;
	}
      
      about_text.setPosition(window->getSize().x/2,
			     Constants::ABOUT_TEXT_STARTING_YCOR+Constants::ABOUT_TEXT_OFFSET*(z+blah));
  
      window->draw(about_text);
    }

  draw_menu_text(window->getSize().y-100);
}
//TODO make a render_text function that takes all of these parameters and just does the whole damn process


//DOES WEIRD SHIT. APPROACH WITH CAUTION. TRY WORKING WITH THIS IN AN EXPERIMENTAL BRANCH MAYBE.
void Renderer::render_text(sf::Font a_font, string str, int char_size, double xcor, double ycor)
{
  sf::Text text;

  text.setFont(a_font);

  text.setString(str);

  text.setCharacterSize(char_size);

  text.setPosition(xcor,ycor);

  window->draw(text);
}

void Renderer::draw_settings_menu()
{
  draw_attract_mode();
  
  sf::Text settings_text;
  
  settings_text.setFont(pixel_font);
  
  settings_text.setString("Settings");
  
  settings_text.setCharacterSize(Constants::PAUSE_TEXT_CHAR_SIZE);
  
  set_origin_to_center(&settings_text);
      
  settings_text.setPosition(window->getSize().x/2,.3*window->getSize().y);
  
  window->draw(settings_text);

  vector <string> menu_options=game->get_menu()->get_options();
  int selection=game->get_menu()->get_selection();

  for(int z=0;z<menu_options.size();z++)
    {
      sf::Text option;
      option.setFont(pixel_font);

      string display_string=menu_options[z];

      if(menu_options[z]==Constants::SPEED_MENU_OPTION)
	{
	  display_string+=to_string(game->get_time_multiplier());
	}
      else if(menu_options[z]==Constants::WIN_THRESHOLD_OPTION)
	{
	  display_string+=to_string(Constants::WIN_SCORE);
	}
	
      option.setString(display_string);
      
      option.setCharacterSize(Constants::MENU_CHAR_SIZE);
      
      set_origin_to_center(&option);
      
      option.setPosition(window->getSize().x/2,window->getSize().y/2+100+Constants::MENU_TEXT_OFFSET*z);

      if(z==game->get_menu()->get_selection())
	{
	  option.setFillColor(Constants::MENU_HIGHLIGHT_COLOR);
	}
      
      window->draw(option);
    }


  if(game->get_menu()->get_selected_option()==Constants::SPEED_MENU_OPTION)
    {      
      speed_selector.setFillColor(Constants::MENU_HIGHLIGHT_COLOR);
    }
  else
    {
      speed_selector.setFillColor(sf::Color::White);
    }

  speed_selector.setPosition(window->getSize().x/2-265+
			     game->get_speed_index()*60,
			     window->getSize().y/2-50);
  //cout << game->get_speed_index() << "\n";
  window->draw(speed_bar);
  window->draw(speed_selector);
}

void Renderer::draw_go_text()
{
  sf::Text go_text;
  go_text.setFont(pixel_font);
  
  go_text.setString("GO!!");

  go_text.setCharacterSize(Constants::COUNTDOWN_CHAR_SIZE);
  
  set_origin_to_center(&go_text);
  
  
  go_text.setPosition(window->getSize().x/2,window->getSize().y-100);
  window->draw(go_text);
}
