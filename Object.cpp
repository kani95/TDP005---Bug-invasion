#include "Object.h"

Object::Object()
    :position{300,300}, speed{}, area{}, shape{}
{
    shape.setSize(sf::Vector2(100.f, 400.f));
}

