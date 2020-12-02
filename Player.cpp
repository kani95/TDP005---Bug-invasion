#include "Player.h"
#include <iostream>

Player::Player()
    :Character()
{}


void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y += -2;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x += -2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {

        position.y += 2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x += 2;
    }

    std::cout << position.x << " " << position.y << std::endl;
    // std::cout << this -> shape.getGlobalBounds().height << "Height " << this -> shape.getGlobalBounds().width << " Width";
}


bool Player::check_inside_leaf(sf::Vector2<float> limit)
{
    if (this->position.x < limit.x && this->position.y < limit.y)
    {
        return false;
    }
    return true;
}
