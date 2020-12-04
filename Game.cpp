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
 :player(), frame_time{}, timer{70}
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

   if (timer < 70)
       timer++;

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer >= 70)
   {
       player.add_shot();
       timer = 0;
   }

    if (! states.empty())
    {
        states.top() -> update(frame_time);
    }

}


void Game::render()
{
    //player.shape.setPosition(player.position);
    window -> clear();

    if (! states.empty())
    {
        states.top() -> render(window);
    }

    window -> draw(leaf.shape);

    player_shots = player.get_player_shots();

    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        player_shots.at(i).shape.move(0.f,20.f);
        window -> draw(player_shots.at(i).shape);
    }
    window -> draw(player.shape);
    window -> display();

    tick.restart();
}
