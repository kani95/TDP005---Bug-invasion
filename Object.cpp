#include "Object.h"


Object::Object(std::string const& text, sf::Vector2f const& dim)
        : position{220,220}, direction{}, shape{}
{
    init_texture(text);
    shape.setScale(dim);

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


void Object::render(sf::RenderTarget* window) const
{
    window -> draw(shape);
}


float Object::get_right() const
{
    return shape.getPosition().x + shape.getGlobalBounds().width;
}


float Object::get_left() const
{
    return shape.getGlobalBounds().left;
}


float Object::get_top() const
{
    return shape.getGlobalBounds().top;
}


float Object::get_bot() const
{
    return shape.getPosition().y + shape.getGlobalBounds().height;
}


void Object::set_position(sf::Vector2f const& pos)
{
    shape.setPosition(pos);
}


void Object::set_scale(sf::Vector2f const& scale)
{
    shape.setScale(scale);
}


bool Object::check_coll(sf::Sprite & sprite) const
{
    if(sprite.getGlobalBounds().intersects(shape.getGlobalBounds()))
    {
        return true;
    }
    return false;
}


sf::Sprite& Object::get_sprite()
{
    return shape;
}
