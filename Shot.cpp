#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Shot::Shot(std::string const& text, sf::Vector2f const& shot_dim)
        : Object(text, shot_dim)
{}


void Shot::move(float x, float y)
{
    shape.move(x, y);
}


float Shot::get_right()
{
    return shape.getPosition().x + shape.getGlobalBounds().width;
}


float Shot::get_left()
{
    return shape.getGlobalBounds().left;
}


float Shot::get_top()
{
    return shape.getGlobalBounds().top;
}


float Shot::get_bot()
{
    return shape.getPosition().y + shape.getGlobalBounds().height;
}


bool Shot::check_is_dead()
{
    // change to rendertarget.get bla bla
    return (shape.getPosition().y + shape.getGlobalBounds().height > (1080) ||
            shape.getPosition().y < 0);
}
