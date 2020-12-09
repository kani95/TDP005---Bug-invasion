#ifndef GAME_ANTSWARM_H
#define GAME_ANTSWARM_H
#include "Ant.h"
#include <iostream>
//#include <vecor>

class AntSwarm {
public:
    AntSwarm();
    std::vector<Ant> ant_swarm{};
    void update(const sf::RenderTarget* window, std::vector<Shot> & player_shots) ;
    void render(sf::RenderTarget* target);
    std::pair<unsigned short int, unsigned short int> find_furthest_ant();

    void check_collison(std::vector<Shot> & player_shots);

    std::vector<Ant>& get_all_ants();

    int get_size_swarm() const;
    std::vector<Shot> ant_shots{};

    std::vector<Shot> & get_ant_shots();

protected:
    bool is_swarm_move_right;
};

#endif //GAME_ANTSWARM_H
