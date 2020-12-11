#ifndef GAME_ANTSWARM_H
#define GAME_ANTSWARM_H
#include "Ant.h"
#include <iostream>
#include "Player.h"

class AntSwarm {
public:
    AntSwarm();

    void render(sf::RenderTarget* target);
    std::pair<float, float> find_furthest_ants();
    void move_swarm(const sf::RenderTarget* target);


    int get_size_swarm() const;

    std::vector<Ant>& get_all_ants();

    void update(const sf::RenderTarget* target,
                     std::vector<Shot> & player_shots,
                     std::vector<Shot> & ant_shots,
                     Character* player);

private:
    //std::vector<Shot> ant_shots;
    std::vector<Ant> ant_swarm;
    bool is_swarm_right{true};
    short int border_hit{};

};

#endif //GAME_ANTSWARM_H
