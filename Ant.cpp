#include "Ant.h"
#include "Shot.h"
#include <iostream>

Ant::Ant()
:Enemy(), score{}
{
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(220, 70);
}

int Ant::get_score() {
    return score;
}

void Ant::move(float const x, float const y) {
    shape.move(x, y);
}

void Ant::update()
{

}

bool Ant::check_coll(Shot & shot)
{
    if(shot.get_right() > shape.getPosition().x &&
       shot.get_top() < shape.getPosition().y + shape.getSize().y
       && shot.get_bot() > shape.getPosition().y && shot.get_left()
                                                    < shape.getPosition().x + shape.getSize().x)
    {
/*        std::cout << "i should be reset" << std::endl;
        shape.setPosition(0,0);*/
        return true;
    }
    return  false;
}

void Ant::render(sf::RenderTarget* target)
{
    target -> draw(shape);
}

//Ant::~Ant() = default;
