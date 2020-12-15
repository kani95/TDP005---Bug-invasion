#ifndef GAME_H_SHOT_H
#define GAME_H_SHOT_H
#include "Object.h"

class Shot : public Object
{
public:
    Shot(std::string const& text,sf::Vector2f const& shot_dim);
    void move(float x, float y);
    bool check_is_dead();
};


#endif //GAME_H_SHOT_H
