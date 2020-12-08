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

        // second row
        if (i == 9)
        {
            prev_x = 200.f;
            prev_y = 120.f;
        }
        // third row
        else if (i == 19)
        {
            prev_x = 220.f;
            prev_y = 170.f;
        }
    }
}


int AntSwarm::get_size_swarm() const
{
    return ant_swarm.size();
}


void AntSwarm::update(std::vector<Shot> & player_shots)
{

    check_collison(player_shots);
    for (Ant & ant : ant_swarm)
    {
        ant.update();
        if (ant.can_shoot())
        {
            Shot new_shot;
            new_shot.shape.setPosition(ant.shape.getPosition().x, ant.shape.getPosition().y);
            ant_shots.push_back(new_shot);
        }
    }


    // update shots
    for(unsigned int i{0}; i < ant_shots.size(); ++i)
    {
        if (ant_shots.at(i).check_is_dead())
        {
            ant_shots.erase(ant_shots.begin() + i);
        }
        ant_shots.at(i).move(0.f, 5.f);

    }
}


void AntSwarm::render(sf::RenderTarget* target)
{
    for (Ant & ant : ant_swarm)
    {
        ant.render(target);
    }
}


void AntSwarm::check_collison(std::vector<Shot> & player_shots)
{
    for (auto & shot : player_shots)
    {
        for (Ant & ant : ant_swarm)
        {
            if (ant.check_coll(shot))
            {
                ant.shape.setPosition(0,0);
            }
        }
    }
}


std::vector<Shot> &AntSwarm::get_ant_shots()
{
    return ant_shots;
}
