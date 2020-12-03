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

bool Player::check_inside_leaf(sf::RectangleShape const& box) {

    bool right = (shape.getPosition().x + shape.getSize().x > (box.getPosition().x + box.getSize().x));
    bool left = (shape.getPosition().x < box.getPosition().x);
    bool down = (shape.getPosition().y + shape.getSize().y > (box.getPosition().y + box.getSize().y));
    bool up = (shape.getPosition().y < box.getPosition().y);

    if (right)
    {
        shape.setPosition(shape.getPosition().x - (movespeed), shape.getPosition().y);
        return false;
    }
     else if (left)
     {
        shape.setPosition(shape.getPosition().x + (movespeed), shape.getPosition().y);
        return false;
     }
     else if (down)
    {
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - (movespeed));
        return false;
    }
    else if (up)
    {
        shape.setPosition(shape.getPosition().x, shape.getPosition().y + (movespeed));
        return false;
    }

    return true;
}
