#include "Leaf.h"
#include <iostream>

Leaf::Leaf()
        : Object()
{
    this -> shape.setSize(sf::Vector2(200.f,200.f));
    this -> shape.setPosition(sf::Vector2(400.f,400.f));
    this -> shape.setFillColor(sf::Color::Green);
    //std::cout << this -> shape.getSize().x << " " << this -> shape.getSize().y;
    std::cout << this -> shape.getGlobalBounds().height << "Height " << this -> shape.getGlobalBounds().width << " Width";
}

