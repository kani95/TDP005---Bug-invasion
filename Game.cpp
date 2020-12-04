#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>


void Game::init_vars()
{
    window = {nullptr};
    init_states();
}


void Game::init_window()
{
    video_mode.height = 600;
    video_mode.width = 800;
    //sf::ContextSettings::antialiasingLevel(2);
    window = new sf::RenderWindow(sf::VideoMode(video_mode), "Game");
    window -> setKeyRepeatEnabled(false);
    window -> setFramerateLimit(120);
    window -> setVerticalSyncEnabled(false);
}


void Game::init_states()
{
    states.push(new PlayState(window));
}


Game::Game()
 :frame_time{}
{
    init_vars();
    init_window();
}


Game::~Game()
{
    delete window;

    while (states.empty())
    {
        delete states.top(); // removes the date the pointer is holding
        states.pop(); // removes the pointer
    }
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
                this -> window -> close();
        }
    }

}
#pragma clang diagnostic pop


void Game::update_tick()
{
    /* Update the time var with the time it takes to make
     * one update call and than one render one frame */

    std::cout << frame_time << std::endl;
    frame_time = tick.restart().asMilliseconds();
}


void Game::update()
{
    poll_events();

    if (! states.empty())
    {
        states.top() -> update(frame_time);
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
