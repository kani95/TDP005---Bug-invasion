#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Character : public Object {
public:
    Character();

    virtual void move(float const, float const) = 0;
    virtual void take_damage();
    unsigned long int get_score();
    void increase_score(long unsigned int plus_score);
    void shake_shape();
    int get_hp();
    bool status{true};
    bool is_dead();
    bool check_enemy_coll(sf::RectangleShape const& enemy);

protected:
    long unsigned int score;
    int hp;
    bool can_shoot;
    float movespeed;
};


#endif //MAIN_CPP_CHARACTER_H
