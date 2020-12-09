#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include "Character.h"
#include "vector"
#include <memory>



class Enemy : public Character {
public:
    Enemy();
    //virtual ~Enemy() = 0;


    virtual int get_score() const = 0;
    virtual void move(float const, float const) = 0;
    virtual void update(const sf::RenderTarget* window) = 0;
    // virtual void drop_loot() = 0;

    //std::vector<Enemy*> all_spiders;

private:
    int score;
};


#endif //GAME_ENEMY_H