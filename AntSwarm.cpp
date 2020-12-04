#include "AntSwarm.h"

AntSwarm::AntSwarm()
    :ant_swarm{}
{
    sf::Vector2f prev_pos{20,20};
    for (int i{}; i < 30; i++)
    {
        Ant ant;
        ant.shape.move();
        ant_swarm.push_back(Ant i);
    }
}