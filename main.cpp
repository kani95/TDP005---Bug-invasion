#include <SFML/Graphics.hpp>
#include "Game.h"
    //#include <Window.hpp>
    //#include <Event.hpp>
/*
    sf::Vector2f find_direction()
    {
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;
    float len = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    if (len > 0.0f)
        return direction * (1.0f / len);
    else
        return direction;
    }*/





int main()
{
    //sf::RenderWindow window{sf::VideoMode(1024, 768), "Hello World!"};
    //sf::RenderWindow window(sf::VideoMode(width, height), "Game");
    //window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(120);
    Game game{};

    while (game.window_status())
    {
        game.update();

        game.render();

    }

    return 0;
}
