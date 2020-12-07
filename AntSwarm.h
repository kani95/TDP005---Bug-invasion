#ifndef GAME_ANTSWARM_H
#define GAME_ANTSWARM_H
#include "Ant.h"
#include <iostream>
//#include <vecor>

class AntSwarm {
public:
    AntSwarm();
    std::vector<Ant> ant_swarm{};
    void update();
    void render(sf::RenderTarget* target);

    int get_size_swarm() const;
};

#endif //GAME_ANTSWARM_H
