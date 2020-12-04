#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include "Character.h"

class Enemy : public Character{
public:
    Enemy();
    //virtual ~Enemy() = 0;


    virtual int get_score() = 0;
    virtual void move(float const, float const) = 0;
    virtual void update() = 0;
    // virtual void drop_loot() = 0;



};


#endif //GAME_ENEMY_H