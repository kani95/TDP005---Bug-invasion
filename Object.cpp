#include "Object.h"

/*Object::Object(sf::RenderTarget & window)
    :position{220,220}, area{}, speed{}, shape{}, window{window}
{
    shape.setSize(sf::Vector2f(10.f, 40.f));
}*/


Object::Object(std::string const& text, sf::Vector2f const& dim)
        : position{220,220}, direction{}, shape{}
{
    init_texture(text);
    shape.setScale(dim);

  // shape.setScale(sf::Vector2f(10.f, 40.f));
}

Object::Object(std::string const& text, sf::Vector2f const& pos, sf::Vector2f const& dim)
        : position{pos}
{
    init_texture(text);
    shape.setPosition(position);
    shape.setScale(dim);
}

Object::Object(std::string const& text, sf::Vector2f const& pos,
               sf::Vector2f const& dir,
               sf::Vector2f const& dim)
        : position{pos}, direction{dir}
{
    init_texture(text);
    shape.setPosition(position);
    shape.setScale(dim);
}

void Object::init_texture(std::string const& file_name)
{
    if(!texture->loadFromFile(file_name))
    {
        std::cerr << "Failed to load texture";
    }
    shape.setTexture(*texture);
}
