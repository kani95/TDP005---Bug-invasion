#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Game::init_vars()
{
 //   window = {nullptr};
    init_states();
}


// är intersect okej?
// inläsning av fil
// resize
// kompletteringar
// ta in ett namn?


void Game::init_window()
{
    video_mode.height = 1080;
    video_mode.width = 1920;
    //sf::ContextSettings::antialiasingLevel(2);
    window = new sf::RenderWindow(sf::VideoMode(video_mode), "menu");
   // window = new sf::RenderWindow(sf::VideoMode(video_mode), "Game");
    window -> setKeyRepeatEnabled(false);
    window -> setFramerateLimit(60);
    window -> setVerticalSyncEnabled(true);
}


void Game::init_states()
{
    states.push(new PlayState(window));
    states.push(new MenuState(window));
}


Game::Game()
 :frame_time{}, window{}, timer{}
{

    init_window();
    init_vars();
}


Game::~Game()
{
    clear_stack();
}


bool Game::window_status() const
{
    return window -> isOpen();
}


// ignore stupid clion warnings
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch"
void Game::poll_events()
{
    while (window -> pollEvent( event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
               clear_stack();
              //  window -> close();
                break;

/*            case sf::Event::Resized:
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window -> setView(sf::View(visibleArea));*/
        }
    }

/*    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        clear_stack();
    }*/
}
#pragma clang diagnostic pop


void Game::update_tick()
{
    /* Update the time var with the time it takes to make
     * one update call and than one render one frame */

    //std::cout << frame_time << std::endl;
    frame_time = tick.restart().asMilliseconds();
}


void Game::update()
{
    poll_events();

    if (! states.empty())
    {
        states.top() -> update(frame_time);
        if (states.top() -> get_is_done())
        {
            std::cout << "true" << std::endl;
            delete states.top();
            states.pop();
        }
        else if(states.top() -> get_exit_status())
        {
            clear_stack();
        }
        else if (states.top() -> get_leaderboard_status())
        {
            states.push(new LeaderboardState(window));
        }
    }
}


void Game::render()
{
    window -> clear();

    if (! states.empty())
    {
        states.top() -> render(window);
    }

    window -> display();

    //tick.restart();
}

void Game::clear_stack()
{
   // delete window;

    while (!states.empty())
    {
        delete states.top(); // removes the date the pointer is holding
        states.top() = nullptr;
        states.pop(); // removes the pointer
    }

    window -> close();
}
