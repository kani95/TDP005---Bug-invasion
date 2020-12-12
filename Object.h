#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H
#include <SFML/Graphics.hpp>

class Object {
public:
    // explicit Object(sf::RenderTarget & window);
    Object();
    Object(sf::Vector2f const& pos, sf::Vector2f const& dim);
    Object(sf::Vector2f const & pos, sf::Vector2f const& dir,
           sf::Vector2f const& dim);

//protected:
    sf::Vector2f position;
    sf::Vector2f direction;
    sf::RectangleShape shape;
   // sf::Sprite shape;
    sf::Texture texture;

    //sf::RenderTarget &window;
};


#endif //MAIN_CPP_OBJECT_H
