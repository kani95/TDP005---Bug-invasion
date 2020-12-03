#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Character : public Object {
public:
    Character();

    virtual void move(float const, float const) = 0;


protected:
    int hp;
    bool status;
    bool can_shoot;
    int score;
    float movespeed;
};


#endif //MAIN_CPP_CHARACTER_H
