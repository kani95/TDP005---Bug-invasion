#include "Leaf.h"
#include <iostream>

Leaf::Leaf()
        : Object()
{
    this -> shape.setSize(sf::Vector2(500.f,200.f));
    this -> shape.setPosition(sf::Vector2(250.f,390.f));
    this -> shape.setFillColor(sf::Color::Green);
    //std::cout << this -> shape.getSize().x << " " << this -> shape.getSize().y;
    std::cout << this -> shape.getGlobalBounds().height << "Height " << this -> shape.getGlobalBounds().width << " Width";
}

