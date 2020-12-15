#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game()
        :frame_time{}, window{}, timer{}
{

    init_window();
    init_states();
}


Game::~Game()
{
    clear_stack();
}


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
    states.push(new PlayState(window, "example.txt"));
    states.push(new MenuState(window));
}


bool Game::window_status() const
{
    return window -> isOpen();
}


// ignore stupid clion warnings
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch"
/*void Game::poll_events()
{

    *//*while (window -> pollEvent( event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                clear_stack();
                break;

                // move to leaderbordstate maybe
            case sf::Event::Resized:
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window -> setView(sf::View(visibleArea));
        }
    }*//*



*//*    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        clear_stack();
    }*//*
}*/
#pragma clang diagnostic pop

/*
void Game::update_tick()
{
    *//* Update the time var with the time it takes to make
     * one update call and than one render one frame *//*

    //std::cout << frame_time << std::endl;
  //  frame_time = tick.restart().asMilliseconds();
}*/


void Game::update()
{
   // poll_events();
    states.top() -> poll_events(event);

    if (!states.empty())
    {
        if (states.top() -> get_is_done())
        {
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
        else
        {
            states.top()->update(1.0f/tick.asSeconds());
        }
    }
}


void Game::render()
{
    window -> clear();

    if (!states.empty())
    {
        states.top() -> render();
    }

    window -> display();

 sf::Time time = clock.getElapsedTime();
 clock.restart().asSeconds();
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
}
