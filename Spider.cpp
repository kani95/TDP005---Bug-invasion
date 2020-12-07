#include "Spider.h"
#include <iostream>
#include <random>

Spider::Spider()
        : Enemy(), score{}
{
    shape.setFillColor(sf::Color::Blue);
   // shape.setPosition(300,200);
}

int Spider::get_score()
{
 return score;
}

void Spider::move( float const dirx, float const diry)
{
    shape.move(dirx,diry);
}

void Spider::set_start_pos()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(250,400);
    float start_x {static_cast<float>(dis(gen))};
    float start_y {static_cast<float>(dis(gen))};
    shape.setPosition(start_x,start_y);
   // std::cout << start_x << ":x " << start_y << ":y ";
}

void Spider::update()
{
        move(-0.08, 0);
        //std::cout << spider.shape.getPosition().x << "WWWWWWWWWWWWWWWWW2";

}

bool Spider::check_coll(Shot & shot)
{
    if(shot.get_right() > shape.getPosition().x &&
       shot.get_top() < shape.getPosition().y + shape.getSize().y
       && shot.get_bot() > shape.getPosition().y && shot.get_left()
                                                    < shape.getPosition().x + shape.getSize().x)
    {
        //shape.setPosition(30,30);
        return true;
    }
    return false;
}