#include "Object.h"

/*Object::Object(sf::RenderTarget & window)
    :position{220,220}, area{}, speed{}, shape{}, window{window}
{
    shape.setSize(sf::Vector2f(10.f, 40.f));
}*/


Object::Object(std::string const& text, sf::Vector2f const& dim)
        : position{220,220}, direction{}, shape{}
{
    shape.setScale(dim);
    if(!texture.loadFromFile(text))
    {
        std::cerr << "No load";
    }
    shape.setTexture(texture);
  // shape.setScale(sf::Vector2f(10.f, 40.f));
}

Object::Object(std::string const& text, sf::Vector2f const& pos, sf::Vector2f const& dim)
        : position{pos}
{
    if(!texture.loadFromFile(text))
    {
        std::cerr << "Failed to load texture";
    }
    shape.setTexture(texture);
    shape.setPosition(position);
    shape.setScale(dim);
}

Object::Object(std::string const& text, sf::Vector2f const& pos,
               sf::Vector2f const& dir,
               sf::Vector2f const& dim)
        : position{pos}, direction{dir}
{
    if(!texture.loadFromFile(text))
    {
        std::cerr << "Failed to load texture";
    }
    shape.setTexture(texture);
    shape.setPosition(position);
    shape.setScale(dim);
}

