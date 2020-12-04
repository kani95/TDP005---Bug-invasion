#include "Ant.h"


Ant::Ant()
:Enemy(), score{}
{
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(20,20);
}

int Ant::get_score() {
    return score;
}

void Ant::move(float const, float const) {

}

void Ant::update() {

}

//Ant::~Ant() = default;
