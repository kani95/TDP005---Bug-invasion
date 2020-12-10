#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Character : public Object {
public:
    Character();

    virtual void move(float const, float const) = 0;
    virtual void take_damage();
    void shake_shape();
    int get_hp();

protected:
    int hp;
    bool status{false};
    bool can_shoot;
    int score;
    float movespeed;
};


#endif //MAIN_CPP_CHARACTER_H
