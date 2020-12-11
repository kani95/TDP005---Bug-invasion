#include "Leaf.h"
#include <iostream>

Leaf::Leaf()
        : Object()
{



    std::cout << shape.getScale().x << " " << shape.getScale().y << std::endl;
    shape.setScale(sf::Vector2(300.f,300.f));
    std::cout << shape.getScale().x << " " << shape.getScale().y << std::endl;
    shape.setPosition(sf::Vector2(250.f,290.f));

    shape.setColor(sf::Color::Green);
    //std::cout << this -> shape.getSize().x << " " << this -> shape.getSize().y;
    //std::cout << this -> shape.getGlobalBounds().height << "Height " << this -> shape.getGlobalBounds().width << " Width";
}

