#include "Ant.h"
#include "Shot.h"


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

void Ant::update() {
}

void Ant::check_coll(Shot & shot)
{
    if(shot.get_right() > shape.getPosition().x &&
       shot.get_top() < shape.getPosition().y + shape.getSize().y
       && shot.get_bot() > shape.getPosition().y && shot.get_left()
                                                    < shape.getPosition().x + shape.getSize().x)
    {
        shape.setPosition(0,0);
    }
}

void Ant::render()
{
    window -> draw(ant.shape);
}

//Ant::~Ant() = default;
