#include "Player.h"

Player::Player()
    :Character()
{}


void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y += -1;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x += -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {

        position.y += 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x += 1;
    }
}


/*
sf::Vector2f get_pos(sf::Vector2f direction)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        direction.y += -1;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction.x += -1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {

        direction.y += 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction.x += 1;
    }

    return direction;
}
*/
