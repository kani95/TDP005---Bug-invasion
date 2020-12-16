#include "Game.h"


Game::Game()
        :delta{}, window{nullptr}, score{}
{
    init_window();
    init_states();
}

Game::~Game()
{
    /// Delete the states on the stack and pops them.
    while (!states.empty())
    {
        delete states.top();
        states.top() = nullptr;
        states.pop();
    }

    delete window;
}


void Game::init_window()
{
    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel= 32;

    window = new sf::RenderWindow(sf::VideoMode(video_mode), "Game",
                                  sf::Style::Fullscreen);
    window -> setKeyRepeatEnabled(false);
    window -> setFramerateLimit(60);
    window -> setVerticalSyncEnabled(true);
}


void Game::init_states()
{
    states.push(new MenuState(window));
}


bool Game::window_status() const
{
    return window -> isOpen();
}


void Game::update()
{
//Remove top function

   /* tick = clock.restart();
    last_update += tick;*/
    update_delta();
 /*  while (last_update < sf::seconds(delta))
   {
       last_update += sf::seconds(delta);
   }*/
 // ask axel about commenting style
 // about memory leak
 // about
   /// Check top state on stack, call update then check if any flags are set to
   /// exit the current state then add the new state.
       states.top() -> update(delta, event);

       if (!states.empty())
       {
           if (states.top() -> get_is_done())
           {
               remove_top();
           }
           else if (states.top() -> get_exit_status())
           {
              window -> close();
           }
           else if (states.top() -> get_leaderboard_status())
           {
               states.push(new LeaderboardState(window));
           }
           else if (states.top() -> get_playstate_status())
           {
               remove_top();

               states.push(new PlayState(window, "Level.txt"));
           }
           else if (states.top() -> get_gameover_status())
           {
               bool is_game_won{states.top() -> get_is_game_won()};

               score = states.top() -> get_score();

               remove_top();

               states.push(new GameOverState(window, is_game_won, score));
           }
       }

    sf::Time time = delta_clock.getElapsedTime();
    delta_clock.restart().asSeconds();
}


void Game::update_delta()
{
    /// how long it takes for the gameloop to make one update call and one render call
    delta = delta_clock.restart().asSeconds();
}


void Game::remove_top()
{
    delete states.top();
    states.pop();
}


void Game::render() const
{
    ///Call the render function for the state at the top of the stack
    window -> clear();

    if (!states.empty())
    {
        states.top() -> render();
    }

    window -> display();
}

