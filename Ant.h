#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"
#include "Shot.h"

// type 1 enemy
class Ant : public Enemy {
public:
    Ant();
    //~Ant() override;

    int get_score() const override;
    void move(float const, float const) override;
    void update() override;
    void render(sf::RenderTarget* target) const;
    bool can_shoot() const;

    bool check_coll(Shot & shot) const;

private:
    int score;
};

#endif //GAME_ANT_H
