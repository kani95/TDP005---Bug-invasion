#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Character : public Object {
public:
    Character();
    Character(int const hp);
    Character(int const hp, sf::Vector2f const& dir);
    Character(sf::Vector2f const& pos,
              sf::Vector2f const& dir,
              sf::Vector2f const& dim,
              float const movespeed,
              int const hp);

    virtual void move(float const, float const) = 0;
    virtual void take_damage();
    void shake_shape();
    int get_hp();
    bool status{true};
    bool is_dead();
    bool check_enemy_coll(sf::RectangleShape const& enemy);

protected:
    int hp;
    bool can_shoot;
    int score;
    float movespeed;
};


#endif //MAIN_CPP_CHARACTER_H
