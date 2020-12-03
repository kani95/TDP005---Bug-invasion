#include "Game.h"
#include <SFML/Graphics.hpp>

void Game::init_vars()
{
    window = {nullptr};
}

void Game::init_window()
{

    video_mode.height = 600;
    video_mode.width = 800;
    window = new sf::RenderWindow(sf::VideoMode(video_mode), "Game");
    window -> setKeyRepeatEnabled(false);
    window -> setFramerateLimit(60);
    window -> setVerticalSyncEnabled(true);
}

Game::Game()
 : player()
{
    init_vars();
    init_window();
}

Game::~Game()
{
    delete window;
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


void Game::update()
{
    poll_events();
   if (player.check_inside_leaf(leaf.shape)) {


       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
           player.move(0.f, -1.f);
           // position.y += -2;
       }

       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
           player.move(-1.f, 0.f);
           // position.x += -2;
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
           player.move(0.f, 1.f);
           // position.y += 2;
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
           player.move(1.f, 0.f);
           // position.x += 2;
       }
   }
}


void Game::render()
{
    //player.shape.setPosition(player.position);
    window -> clear();
    window -> draw(leaf.shape);
    window -> draw(player.shape);
    window -> display();
}

