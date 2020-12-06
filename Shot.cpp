#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Shot::Shot()
        : Object()
{
    shape.setSize(sf::Vector2f(5.f,10.f));
    speed.x = 0;
    speed.y = -6.5;
}

void Shot::move()
{
    //shape.move(shape.getPosition().x + speed.x, shape.getPosition().y + speed.y);
    shape.move(speed.x, speed.y);
}

float Shot::get_right()
{
    return shape.getPosition().x + shape.getSize().x;
}

float Shot::get_left()
{
    Shoot:return shape.getPosition().x;
}
float Shot::get_top()
{
    return shape.getPosition().y;
}

float Shot::get_bot()
{
    return shape.getPosition().y + shape.getSize().y;
}

/*void Shot::update(Shot & new_shot)
{

}*/

/*void Shot::render(sf::RenderTarget* & window)
{

}*/

