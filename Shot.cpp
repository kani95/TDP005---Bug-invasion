#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Shot::Shot(std::string const& text, sf::Vector2f const& shot_dim)
        : Object(text, shot_dim)
{}


void Shot::move(float const x, float const y)
{
    shape.move(x, y);
}


bool Shot::check_is_dead()
{
    return (shape.getPosition().y + shape.getGlobalBounds().height > (1080)
            || shape.getPosition().y < 0);
}
