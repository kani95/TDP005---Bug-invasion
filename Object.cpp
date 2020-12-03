#include "Object.h"

Object::Object()
    :position{220,220}, area{}, speed{}, shape{}
{
    shape.setSize(sf::Vector2f(10.f, 40.f));
}

