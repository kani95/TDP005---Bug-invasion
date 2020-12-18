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

    void render(sf::RenderTarget* window) const;
    float get_right() const;
    float get_left() const;
    float get_top() const;
    float get_bot() const;
    void set_position(sf::Vector2f const& pos);
    void set_scale(sf::Vector2f const& scale);
    bool check_coll(sf::Sprite & sprite) const;
    sf::Sprite& get_sprite();

protected:
    void init_texture(std::string const& file_name);
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    sf::Vector2f position;
    sf::Vector2f direction;
    sf::Sprite shape;
};

#endif //MAIN_CPP_OBJECT_H
