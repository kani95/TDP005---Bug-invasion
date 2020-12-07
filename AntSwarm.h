#ifndef GAME_ANTSWARM_H
#define GAME_ANTSWARM_H
#include "Ant.h"
//#include <vecor>

class AntSwarm {
public:
    AntSwarm();
    std::vector<Ant> ant_swarm{};
    void update();
    void render();
};



#endif //GAME_ANTSWARM_H
