#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Spider.h"

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
/*
bool Shot::check_coll(std::vector<Spider> & all_spiders)
{
    for (Spider & spider : all_spiders) {
        if (get_right() > spider.shape.getPosition().x &&
            get_top() < spider.shape.getPosition().y + spider.shape.getSize().y
            && get_bot() > spider.shape.getPosition().y && get_left()
                                                           < spider.shape.getPosition().x + spider.shape.getSize().x) {
            //shape.setPosition(30, 30);
            return true;
        }
    }
    return false;
}*/

/*void Shot::update(Shot & new_shot)
{

}*/

/*void Shot::render(sf::RenderTarget* & window)
{

}*/

