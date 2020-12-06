#ifndef GAME_H_SHOT_H
#define GAME_H_SHOT_H
#include "Object.h"
#include <vector>

class Shot : public Object
{
public:
    Shot();
    void move();

    float get_right();
    float get_left();
    float get_top();
    float get_bot();

    //void render(sf::RenderTarget* & window);
    //void update(Shot & new_shot);

private:
};


#endif //GAME_H_SHOT_H
