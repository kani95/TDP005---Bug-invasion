#include "Object.h"

/*
Object::Object(sf::RenderTarget & window)
    :position{220,220}, area{}, speed{}, shape{}, window{window}
{
    shape.setSize(sf::Vector2f(10.f, 40.f));
}
*/


Object::Object()
    :position{220,220}, area{}, speed{}, shape{}
    {
        shape.setSize(sf::Vector2f(10.f, 40.f));
    }


