#ifndef GAME_LEAF_H
#define GAME_LEAF_H
#include "Object.h"

class Leaf :  public Object
{
public:
    Leaf() = default;
    Leaf(std::string const& text, sf::Vector2f const& pos, sf::Vector2f const& dim);
};


#endif //GAME_LEAF_H
