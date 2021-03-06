#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H
#include "Character.h"
#include "Shot.h"


class Enemy : public Character {
public:

    Enemy() = default;
    Enemy(int const score, int const hp);
    //virtual ~Enemy() = 0;

    int get_score() const;

    virtual void move(float const, float const) = 0;
    virtual void update(float const frame_time,
            std::vector<Shot> & player_shots,
            std::vector<Shot> & ant_shots,
            Character* player) = 0;
    // virtual void drop_loot() = 0;

    //std::vector<Enemy*> all_spiders;


protected:

    int score;
};


#endif //GAME_ENEMY_H