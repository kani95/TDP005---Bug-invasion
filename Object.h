#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H
#include <SFML/Graphics.hpp>
//#include "PlayState.h"


class Object {
public:
    // explicit Object(sf::RenderTarget & window);
    Object();

//protected:
    sf::Vector2f position;
    sf::Vector2f area;
    sf::Vector2f speed;
    sf::RectangleShape shape;

    //sf::RenderTarget &window;
};


#endif //MAIN_CPP_OBJECT_H
