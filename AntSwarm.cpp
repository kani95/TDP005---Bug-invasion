#include "AntSwarm.h"

AntSwarm::AntSwarm()
    :ant_swarm{}
{
    float prev_x {220};
    float prev_y {70};
    for (int i{}; i < 30; i++)
    {
        prev_x += 10;
        Ant ant;
        ant.shape.move(prev_x, prev_y);
        ant_swarm.push_back(ant);

        if (prev_x = 320)
        {
            prev_x = 230;
            prev_y = 90;
        }

    }
}


void AntSwarm::update() {

    for (Ant & ant : ant_swarm)
    {
        ant.update();
    }
}

void AntSwarm::render()
{
    for (Ant & ant : ant_swarm)
    {
        ant.render();
    }
}
