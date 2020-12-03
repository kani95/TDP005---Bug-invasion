#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "Character.h"

class Player : public Character{
public:
    //sf::CircleShape shape(50);
    Player();
    void move() override;
    bool check_inside_leaf(sf::Vector2<float> limit);


};


#endif //MAIN_CPP_PLAYER_H
