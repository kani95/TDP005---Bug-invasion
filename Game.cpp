#include "Game.h"

Game::Game()
        :delta{}, window{nullptr}, score{}
{
    init_window();
    init_states();
}


/*Game::~Game()
{
    clear_stack();
}*/


void Game::init_window()
{
    video_mode.width = 1920;
    video_mode.height = 1080;
    //sf::ContextSettings::antialiasingLevel(2);
    window = new sf::RenderWindow(sf::VideoMode(video_mode), "Game");
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


/*
void Game::update_tick()
{
    *//* Update the time var with the time it takes to make
     * one update call and than one render one frame *//*

    //std::cout << frame_time << std::endl;
  //  frame_time = tick.restart().asMilliseconds();
}*/


void Game::update() {
//Remove top function
    update_delta();
    states.top()->update(delta, event);

    if (!states.empty()) {
        if (states.top() -> get_is_done()) {
            delete states.top();
            states.pop();
        } else if (states.top() -> get_exit_status()) {
            clear_stack();
        } else if (states.top() -> get_leaderboard_status()) {
            states.push(new LeaderboardState(window));
        } else if (states.top() -> get_playstate_status()) {
            delete states.top();
            states.pop();
            states.push(new PlayState(window, "example.txt"));
        } else if (states.top() -> get_gameover_status()) {
            bool is_game_won{states.top() -> get_is_game_won()};
            score = states.top() -> get_score();
            delete states.top();
            states.pop();
            states.push(new GameOverState(window, is_game_won, score));
        }
    }
    sf::Time time = delta_clock.getElapsedTime();
    delta_clock.restart().asSeconds();
}


void Game::render() const
{
    window -> clear();

    if (!states.empty())
    {
        states.top() -> render();
    }

    window -> display();
}


void Game::clear_stack()
{
    while (!states.empty())
    {
        delete states.top(); // removes the date the pointer is holding
        states.top() = nullptr;
        states.pop(); // removes the pointer
    }

    window -> close();
    delete window;

    std::exit(EXIT_SUCCESS); // ASK AXEL
}

void Game::update_delta()
{
    delta = delta_clock.restart().asSeconds();
    std::cout << delta << std::endl;
}
