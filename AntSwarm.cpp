#include "AntSwarm.h"

AntSwarm::AntSwarm()
    :ant_swarm{}
{
    float prev_x {220.f};
    float prev_y {70.f};
    for (unsigned short int i{0}; i < 30; i++)
    {
        prev_x = prev_x + 40.f;
        //std::cout << prev_x << std::endl;
        Ant ant{};
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


std::pair<float, float> AntSwarm::find_furthest_ants()
{
    // !!! this will crash if no ants are in the vector !!!

    float ant_left_x {ant_swarm.at(0).shape.getPosition().x};
    float ant_right_x {ant_swarm.at(0).shape.getPosition().x};


    for(unsigned int i{0}; i < get_size_swarm(); ++i)
    {
        float current_ant_pos = ant_swarm.at(i).shape.getPosition().x;

        if (current_ant_pos < ant_right_x)
        {
            ant_right_x = current_ant_pos;
        }
        else if (current_ant_pos > ant_left_x)
        {
            ant_left_x = current_ant_pos;
        }

    }
    return {ant_left_x, ant_right_x};
}


void AntSwarm::move_swarm(const sf::RenderTarget* window)
{
    float x_value_left{find_furthest_ants().second};
    float x_value_right{find_furthest_ants().first};

    // std::cout << border_hit << std::endl;

    float x_movement{2};
    float y_movement{0};

    if (border_hit % 2 != 0)
    {
        if (border_hit <= 5) {
            y_movement = 10.f;
            x_movement = 0.f;
            border_hit += 1;
        }
        else
        {
            y_movement = -10.f;
            x_movement = 0.f;
            border_hit += 1;
        }

        if (border_hit > 11)
        {
            border_hit = 0;
        }
    }

    // calculate the new x coordnates if the ant furthes right and left
    // were to move, if the new postion is outside the screen border change direction
    if (is_swarm_right)
    {
        if(x_value_right + x_movement > 800)
        {
            is_swarm_right = false;
            border_hit += 1;
        }
    }
    else
    {
        if(x_value_left + x_movement < 0)
        {
            is_swarm_right = true;
            border_hit += 1;
        }
    }


    // check which way the swarm is going to move, move each ant
    if (is_swarm_right)
    {
        for (unsigned int i{0}; i < get_size_swarm(); ++i)
        {
            Ant & ant{ant_swarm.at(i)};
            ant.move(x_movement, y_movement);
        }
    }
    else
    {
        for (unsigned int i{0}; i < get_size_swarm(); ++i)
        {
            Ant & ant{ant_swarm.at(i)};
            ant.move(-x_movement, y_movement);
        }
    }
}


void AntSwarm::update(const sf::RenderTarget* target,
                 std::vector<Shot> & player_shots,
                 std::vector<Shot> & ant_shots,
                 Character* player)
{

    for(unsigned int i{0}; i < ant_swarm.size(); ++i) {
        Ant & ant{ant_swarm.at(i)};


        ant.update(target, player_shots, ant_shots, player);


        if (ant.is_dead()) {
            player -> increase_score(ant.get_score());
            ant_swarm.erase(begin(ant_swarm) + i);

        }
    }
        move_swarm(target);
}


void AntSwarm::render(sf::RenderTarget* target)
{
    for (Ant const& ant : ant_swarm)
    {
        ant.render(target);
    }
}


std::vector<Ant>& AntSwarm::get_all_ants()
{
    return ant_swarm;
}
