#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Game::init_vars()
{
    window = {nullptr};
    float frame_time;
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

Game::Game(sf::RenderWindow* window)
 : PlayState(window), player()
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


void Game::poll_events()
{
    while (window -> pollEvent( event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                this -> window -> close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyPressed:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;

        }
    }

}


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

//    if (player.check_inside_leaf(leaf.position))
//    {
        player.move();
//    }
}


void Game::render()
{
    player.shape.setPosition(player.position);
    window -> clear();

    if (! states.empty())
    {
        states.top() -> render(window);
    }

    window -> draw(leaf.shape);
    window -> draw(player.shape);
    window -> display();
}
