#include "Shot.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Shot::Shot(std::string const& text, sf::Vector2f const& shot_dim)
        : Object(text, shot_dim), remove_status{false}
{


   // shape.setSize(sf::Vector2f(5.f,10.f));

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

/*
bool Shot::check_coll(std::vector<sf::RectangleShape> const& all_spiders)
=======
bool Shot::check_coll(std::vector<sf::Sprite> const& all_spiders)
>>>>>>> 1262816645ea7bbeb819e06c3e4794d52e86516d
{
    for (auto & spider : all_spiders) {
        if (get_right() > spider.getPosition().x
            && get_top() < spider.getPosition().y + spider.getScale().y
            && get_bot() > spider.getPosition().y
            && get_left() < spider.getPosition().x + spider.getScale().x)
        {
            //shape.setPosition(30, 30);
            return true;
        }

        //1920 x 1080
    }

    bool down = (shape.getPosition().y + shape.getScale().y > (1080));
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
*/


bool Shot::check_is_dead()
{
    // change to rendertarget.get bla bla
    return (shape.getPosition().y + shape.getGlobalBounds().height > (1080) ||
            shape.getPosition().y < 0);
}
