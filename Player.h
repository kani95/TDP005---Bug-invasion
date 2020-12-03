#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "Character.h"
#include "Character.cpp"

class Player : public Character{
public:
    //sf::CircleShape shape(50);
    Player();
    void move(float const dirx, float const diry) override;

    bool check_inside_leaf(sf::RectangleShape const& box);


};


#endif //MAIN_CPP_PLAYER_H
