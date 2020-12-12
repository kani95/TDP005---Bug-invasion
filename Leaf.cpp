#include "Leaf.h"
#include <iostream>


Leaf::Leaf(sf::Vector2f const& pos, sf::Vector2f const& dim)
        : Object(pos, dim)
{
    if(!texture.loadFromFile("leaf.jpg"))
    {
        std::cerr << "No load";
    }
    shape.setTexture(&texture);
    //this -> shape.setSize(sf::Vector2(300.f,300.f));
    //this -> shape.setPosition(sf::Vector2(250.f,290.f));

    //shape.setFillColor(sf::Color::Green);
    //std::cout << this -> shape.getSize().x << " " << this -> shape.getSize().y;
    //std::cout << this -> shape.getGlobalBounds().height << "Height " << this -> shape.getGlobalBounds().width << " Width";
}

