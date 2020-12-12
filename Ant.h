#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"
#include "Shot.h"
#include "Player.h"
#include "Shot.h"
#include <iostream>

// type 1 enemy
class Ant : public Enemy {
public:
    Ant();



    void move(float , float) override;
    void render(sf::RenderTarget* target) const;
    void update(const sf::RenderTarget* window,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player) override;

    bool check_collison_player_shots(std::vector<Shot> & player_shots);
    bool check_collison_ant_shots(std::vector<Shot> & ant_shots, Character * player);

    static bool can_shoot() ;

    bool check_coll(Shot & shot);


private:
};

#endif //GAME_ANT_H
