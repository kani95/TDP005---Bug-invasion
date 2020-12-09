#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"
#include "Shot.h"

// type 1 enemy
class Ant : public Enemy {
public:
    Ant();
    // check if ant collides with a player shot
    //~Ant() override;


    int get_score() const override;
    void move(float , float) override;
    void update(const sf::RenderTarget* window) override;

    void render(sf::RenderTarget* target) const;
    bool can_shoot() const;

    bool check_coll(Shot & shot) const;
    void set_id(unsigned short int new_id);
    unsigned short get_id();


private:
    int score;
    unsigned short int id;
};

#endif //GAME_ANT_H
