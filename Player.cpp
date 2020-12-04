#include "Player.h"
#include <iostream>


Player::Player()
    :Character()
{
    shape.setPosition(position);
}


void Player::update(sf::RectangleShape const& box)
{
    if (check_inside_leaf(box)) {


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move(0.f, -1.f);
            // position.y += -2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-1.f, 0.f);
            // position.x += -2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move(0.f, 1.f);
            // position.y += 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(1.f, 0.f);
            // position.x += 2;
        }
    }
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
