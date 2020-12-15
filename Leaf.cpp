#include "Leaf.h"
#include <iostream>


//<<<<<<< HEAD
Leaf::Leaf(std::string const& text, sf::Vector2f const& pos, sf::Vector2f const& dim)
        : Object(text, pos, dim)
{
   /* if(!texture.loadFromFile("leaf.jpg"))
    {
        std::cerr << "No load";
    }
    shape.setTexture(texture);*/
    //this -> shape.setSize(sf::Vector2(300.f,300.f));
    //this -> shape.setPosition(sf::Vector2(250.f,290.f));

    //shape.setFillColor(sf::Color::Green);
/*=======


    std::cout << shape.getScale().x << " " << shape.getScale().y << std::endl;
    shape.setScale(sf::Vector2(300.f,300.f));
    std::cout << shape.getScale().x << " " << shape.getScale().y << std::endl;
    shape.setPosition(sf::Vector2(250.f,290.f));

    shape.setColor(sf::Color::Green);
>>>>>>> 1262816645ea7bbeb819e06c3e4794d52e86516d*/
    //std::cout << this -> shape.getSize().x << " " << this -> shape.getSize().y;
    //std::cout << this -> shape.getGlobalBounds().height << "Height " << this -> shape.getGlobalBounds().width << " Width";
}

/*void Leaf::render(sf::RenderWindow* window)
{
    window -> draw(shape);
}*/
