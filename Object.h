#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Object {
public:
    Object() = default;
    Object(std::string const& text, sf::Vector2f const& dim);
    Object(std::string const& text, sf::Vector2f const& pos, sf::Vector2f const& dim);
    Object(std::string const& text, sf::Vector2f const & pos, sf::Vector2f const& dir,
           sf::Vector2f const& dim);

    void render(sf::RenderWindow* window);

protected:
    std::shared_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Sprite shape;

    void init_texture(std::string const& file_name);
};


#endif //MAIN_CPP_OBJECT_H
