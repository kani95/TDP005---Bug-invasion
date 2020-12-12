#include "Object.h"

/*
Object::Object(sf::RenderTarget & window)
    :position{220,220}, area{}, speed{}, shape{}, window{window}
{
    shape.setSize(sf::Vector2f(10.f, 40.f));
}
*/


Object::Object()
        : position{220,220}, direction{}, shape{}
{
   // shape.setSize(sf::Vector2f(10.f, 40.f));
}

Object::Object(sf::Vector2f const& pos, sf::Vector2f const& dim)
        : position{pos}
{
    shape.setPosition(position);
    shape.setSize(dim);
}

Object::Object(sf::Vector2f const& pos,
               sf::Vector2f const& dir,
               sf::Vector2f const& dim)
        : position{pos}, direction{dir}
{
    shape.setPosition(position);
    shape.setSize(dim);
}