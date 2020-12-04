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

void Player::add_shot()
{
    Shot new_shot{};
    new_shot.shape.setPosition(get_dirx(),get_diry());
    player_shots.push_back(new_shot);
}

std::vector<Shot> Player::get_player_shots()
{
    return player_shots;
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

float Player::get_dirx()
{
    return shape.getPosition().x;
}

float Player::get_diry()
{
    return shape.getPosition().y;
}

void Player::draw(sf::RenderWindow & window)
{
    window.draw(shape);
}