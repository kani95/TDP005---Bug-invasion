#include "AntSwarm.h"

AntSwarm::AntSwarm()
    :ant_swarm{}
{
    float prev_x {220.f};
    float prev_y {70.f};
    for (int i{0}; i < 30; i++)
    {
        prev_x = prev_x + 40.f;
        std::cout << prev_x << std::endl;
        Ant ant;
        ant.shape.setPosition(prev_x, prev_y);
        ant_swarm.push_back(ant);

        if (i > 10)
        {
            prev_x = 200.f;
            prev_y = 120.f;
        }
        else if (i > 20)
        {
            prev_x = 240.f;
            prev_y = 170.f;
        }
    }
}


int AntSwarm::get_size_swarm() const
{
    return ant_swarm.size();
}


void AntSwarm::update() {

    for (Ant & ant : ant_swarm)
    {
        ant.update();
    }
}


void AntSwarm::render(sf::RenderTarget* target)
{
    for (Ant & ant : ant_swarm)
    {
        ant.render(target);
    }
}
