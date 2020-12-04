#ifndef GAME_H_SHOT_H
#define GAME_H_SHOT_H
#include "Object.h"

class Shot : public Object
{
public:
    Shot();
    void move();

 /*   int get_right();
    int get_left();
    int get_top();
    int get_bot();*/

    void draw(sf::RenderWindow & window);

};


#endif //GAME_H_SHOT_H
