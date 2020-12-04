#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "Character.h"

class Player : public Character{
public:
    Player();
    void move(float const dirx, float const diry) override;

    void update(sf::RectangleShape const& box);
    bool check_inside_leaf(sf::RectangleShape const& box);


};
#endif //MAIN_CPP_PLAYER_H
