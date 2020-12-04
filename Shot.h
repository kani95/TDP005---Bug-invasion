#ifndef GAME_H_SHOT_H
#define GAME_H_SHOT_H
#include "Object.h"
#include <vector>

class Shot : public Object
{
public:
    Shot();
    void move();

 /*   int get_right();
    int get_left();
    int get_top();
    int get_bot();*/

    //void render(sf::RenderTarget* & window);
    //void update(Shot & new_shot);

private:
};


#endif //GAME_H_SHOT_H
