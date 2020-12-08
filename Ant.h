#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"
#include "Shot.h"


// type 1 enemy
class Ant : public Enemy {
public:
    Ant();
    //~Ant() override;

    int get_score() override;
    void move(float const, float const) override;
    void update() override;
    void render(sf::RenderTarget* target);

    bool check_coll(Shot & shot);


private:
    int score;
};

#endif //GAME_ANT_H
