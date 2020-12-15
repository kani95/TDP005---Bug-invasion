#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Character : public Object {
public:

    Character(int const hp);
    Character(std::string const& text ,sf::Vector2f const& pos,
              sf::Vector2f const& dir,
              sf::Vector2f const& dim,
              float const movespeed,
              int const hp);

    virtual void move(float const, float const) = 0;
    virtual void take_damage();

    void increase_score(long unsigned int plus_score);
    void set_score(int new_score);
    unsigned long int get_score();

    int get_hp();
    bool is_dead();

 //   bool check_enemy_coll(sf::Sprite const& enemy);

protected:
    long unsigned int score;
    int hp;
    float movespeed;
    sf::Clock clock;








};


#endif //MAIN_CPP_CHARACTER_H
