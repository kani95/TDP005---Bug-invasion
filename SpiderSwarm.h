#ifndef GAME_H_SPIDERSWARM_H
#define GAME_H_SPIDERSWARM_H
#include "Spider.h"
#include "vector"
#include "Player.h"

class SpiderSwarm {

public:
    SpiderSwarm();
    void update(const sf::RenderTarget* target,
                     std::vector<Shot> & player_shots,
                     std::vector<Shot> & ant_shots,
                     Character* player);

    void add_second();
    std::vector<Spider>& get_all_spiders();

private:
    std::vector<Spider> all_spiders;
    int timer;

};


#endif //GAME_H_SPIDERSWARM_H
