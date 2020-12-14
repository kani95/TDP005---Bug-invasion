#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Object {
public:
    Object() = default;
    // explicit Object(sf::RenderTarget & window);
    Object(std::string const& text, sf::Vector2f const& dim);
    Object(std::string const& text, sf::Vector2f const& pos, sf::Vector2f const& dim);
    Object(std::string const& text, sf::Vector2f const & pos, sf::Vector2f const& dir,
           sf::Vector2f const& dim);

//protected:
    sf::Vector2f position;

    sf::Vector2f direction;
  //  sf::RectangleShape shape;
   // sf::Sprite shape;
    sf::Texture texture;

    sf::Vector2f area;
    sf::Vector2f speed;
    sf::Sprite shape;


    //sf::RenderTarget &window;
};


#endif //MAIN_CPP_OBJECT_H
