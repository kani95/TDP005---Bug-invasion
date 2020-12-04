#include "Shot.h"
#include <SFML/Graphics.hpp>

Shot::Shot()
        : Object()
{
    shape.setSize(sf::Vector2f(5.f,10.f));
    speed.x = 0;
    speed.y = 10;
}

void Shot::move()
{
    shape.move(shape.getPosition().x + speed.x, shape.getPosition().y + speed.y);
}

/*int Shot::get_right()
{
    return shape.getPosition().x + shape.getSize().x;
}
int Shot::get_left()
{
    Shoot:return shape.getPosition().x;
}
int Shot::get_top()
{
    return shape.getPosition().y;
}
int Shot::get_bot()
{
    return shape.getPosition().y + shape.getSize().y;
}*/

void Shot::draw(sf::RenderWindow & window)
{
    window.draw(shape);
}

