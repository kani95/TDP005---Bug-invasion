#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H
#include <SFML/Graphics.hpp>


class Object {
public:
    Object();

protected:
sf::Vector2f position;
sf::Vector2f area;
sf::Vector2f speed;
sf::RectangleShape shape;
};


#endif //MAIN_CPP_OBJECT_H
