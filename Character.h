#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Object.h"

class Character : public Object {
public:

    explicit Character(int const hp);
    Character(std::string const& text ,sf::Vector2f const& pos,
              sf::Vector2f const& direction,
              sf::Vector2f const& dimention,
              float const movespeed,
              int const hp);

    Character();
    virtual ~Character() = default;

    virtual void move(float const, float const) = 0;
    virtual void take_damage();

    // This functions are used only by player, but because we use player as
    // a character pointer in AntSwarm and SpiderSwarm we are forced to define it here
    void increase_score(long unsigned int plus_score);
    void set_score(int new_score);

    unsigned long int get_score() const;
    int get_hp() const;
    bool is_dead() const;

protected:
    long unsigned int score{};
    int hp{};
    float movespeed{};
    sf::Clock clock;
};


#endif //MAIN_CPP_CHARACTER_H
