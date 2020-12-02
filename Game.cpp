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


const bool Game::window_status() const
{
    return this -> window -> isOpen();
}


void Game::poll_events()
{
    while (this -> window -> poll_event(this -> event))
    {
        switch (this -> event.type)
        {
            case sf::Event::Closed:
                this -> window -> close();
                break;
        }
    }

}


void Game::update()
{
    this -> poll_events();
}


void Game::render()
{
    this -> window -> clear();


    this -> window -> display();
}

