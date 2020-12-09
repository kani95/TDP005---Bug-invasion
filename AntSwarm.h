#ifndef GAME_ANTSWARM_H
#define GAME_ANTSWARM_H
#include "Ant.h"
#include <iostream>


class AntSwarm {
public:
    AntSwarm();


    void update(const sf::RenderTarget* window, std::vector<Shot> & player_shots) ;
    void render(sf::RenderTarget* target);

    void check_collison(std::vector<Shot> & player_shots);

    std::vector<Shot> & get_ant_shots();
    std::vector<Ant>& get_all_ants();

    int get_size_swarm() const;

private:
    std::vector<Shot> ant_shots;
    std::vector<Ant> ant_swarm;


};

#endif //GAME_ANTSWARM_H
