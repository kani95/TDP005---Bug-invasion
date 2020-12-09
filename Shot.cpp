#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Shot::Shot()
        : Object()
{
    shape.setSize(sf::Vector2f(5.f,10.f));
/*    speed.x = 0;
    speed.y = -6.5;*/
}


void Shot::move(float x, float y)
{
    //shape.move(shape.getPosition().x + speed.x, shape.getPosition().y + speed.y);
    shape.move(x, y);
}


float Shot::get_right()
{
    return shape.getPosition().x + shape.getSize().x;
}


float Shot::get_left()
{
    return shape.getPosition().x;
}


float Shot::get_top()
{
    return shape.getPosition().y;
}


float Shot::get_bot()
{
    return shape.getPosition().y + shape.getSize().y;
}

bool Shot::check_coll(std::vector<sf::RectangleShape> const& all_spiders)
{
    for (auto & spider : all_spiders) {
        if (get_right() > spider.getPosition().x &&
            get_top() < spider.getPosition().y + spider.getSize().y
            && get_bot() > spider.getPosition().y &&
            get_left() < spider.getPosition().x + spider.getSize().x) {
            //shape.setPosition(30, 30);
            return true;
        }

        //1920 x 1080
    }

    bool down = (shape.getPosition().y + shape.getSize().y > (1080));
    bool up = (shape.getPosition().y < 0);

    if (down)
    {
        return true;
    }
    else if (up)
    {

        return true;
    }

    return false;
}


bool Shot::check_is_dead()
{
    return (shape.getPosition().y + shape.getSize().y > (1080));
}