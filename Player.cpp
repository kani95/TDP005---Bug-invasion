#include "Player.h"
#include <iostream>

Player::Player()
    :Character()
{
    shape.setPosition(position);
}


void Player::move(float const dirx, float const diry)
{
   // sf::Clock clock;
   // float delta_time = clock.restart().asSeconds();
    shape.setPosition(shape.getPosition().x + (dirx * movespeed), shape.getPosition().y + (diry * movespeed));
    //shape.setPosition(shape.getPosition().x + (delta_time * movespeed), shape.getPosition().y + (movespeed*delta_time));
    std::cout << shape.getPosition().x << " " << shape.getPosition().y << std::endl;

}


/*bool Player::check_inside_leaf(sf::Vector2<float> limit)
{
    if (this->shape.getPosition().x < limit.x && this->shape.getPosition().y < limit.y)
    {
        return false;
    }
    return true;
}*/
