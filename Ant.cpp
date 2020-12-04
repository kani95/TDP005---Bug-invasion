#include "Ant.h"


Ant::Ant()
:Enemy(), score{}
{
    shape.setFillColor(sf::Color::Red);
}

int Ant::get_score() {
    return score;
}

void Ant::move(float const, float const) {

}

void Ant::update() {

}

//Ant::~Ant() = default;
