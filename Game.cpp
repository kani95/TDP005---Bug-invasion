#include "Game.h"
#include <SFML/Graphics.hpp>


void Game::init_vars()
{
    this -> window = {nullptr};
}

void Game::init_window()
{
    this -> video_mode.height = 600;
    this -> video_mode.width = 800;
    this -> window = new sf::RenderWindow(sf::VideoMode(this -> video_mode), "Game");
}

Game::Game()
{
    this -> init_vars();
    this -> init_window();
}

Game::~Game()
{
    delete this -> window;
}


bool Game::window_status() const
{
    return this -> window -> isOpen();
}


void Game::poll_events()
{
    while (this -> window -> pollEvent(this -> event))
    {
        switch (this -> event.type)
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


void Game::update()
{
    this -> poll_events();
    player->move();
}


void Game::render()
{
    this -> window -> clear();


    this -> window -> display();
}

