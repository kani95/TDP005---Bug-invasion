#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"

// type 1 enemy
class Ant : public Enemy{
public:
    Ant();
    //~Ant() override;

    int get_score() override;
    void move(float const, float const) override;
    void update() override;


private:
    int score;
};


#endif //GAME_ANT_H
