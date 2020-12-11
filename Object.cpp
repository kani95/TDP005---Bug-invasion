#include "Object.h"

/*Object::Object(sf::RenderTarget & window)
    :position{220,220}, area{}, speed{}, shape{}, window{window}
{
    shape.setSize(sf::Vector2f(10.f, 40.f));
}*/


Object::Object()
    :position{220,220}, area{}, speed{}, shape{}
    {
        sf::Texture texture;

        shape.setTexture(texture);

        if (!texture.loadFromFile("leaf.jpg"))
        {
            //std::cerr << "some bs";
        }

        shape.setTextureRect(sf::IntRect(0, 0, 1, 1));
        //shape.setScale(10,40);

 /*       if (!texture.loadFromFile("leaf.jpg"))
        {
            //std::cerr << "some bs";
        }*/
        // shape.scale(sf::Vector2f(10.f, 40.f));
    }
