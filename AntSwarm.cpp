#include "AntSwarm.h"

AntSwarm::AntSwarm()
    :ant_swarm{}
{
    float prev_x {220.f};
    float prev_y {70.f};
    for (unsigned short int i{0}; i < 2; i++)
    {
        prev_x = prev_x + 40.f;
        //std::cout << prev_x << std::endl;
        Ant ant{};
        ant.shape.setPosition(prev_x, prev_y);
        ant.set_id(i);
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

    std::cout << border_hit << std::endl;

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


void AntSwarm::update(const sf::RenderTarget* window,
                      Player & player,
                      std::vector<Shot> & player_shots)
{
    for(unsigned int i{0}; i < ant_swarm.size(); ++i)
    {
        Ant & ant{ant_swarm.at(i)};

        if (check_collison_player_shots(player_shots, ant))
        {
            ant.take_damage();
            ant.status = false;
            ant.shake_shape();


            if (ant.get_hp() <= 0)
            {
                ant_swarm.erase(begin(ant_swarm) + i);
                continue;
            }
        }

       // ant.update(window);

        if (ant.can_shoot())
        {
            Shot new_shot{};
            new_shot.shape.setPosition(ant.shape.getPosition().x, ant.shape.getPosition().y);
            ant_shots.push_back(new_shot);
        }
    }

    // move_swarm(window);

    for(unsigned int i{0}; i < ant_shots.size(); ++i)
    {
        Shot & shot {ant_shots.at(i)};

        if (shot.check_is_dead())
        {
            ant_shots.erase(begin(ant_shots) + i);
            // check if player took dmg;
            // call player function take dmg;
            // check if ant took dmg from player
        }
        else if (player.check_enemy_coll(shot.shape))
        {
            ant_shots.erase(begin(ant_shots) + i);
            player.take_damage();
        }
        else
        {
           shot.move(0.f, 5.f);
        }
     //std::cout << ant_shots.size();
    }
}

void AntSwarm::render(sf::RenderTarget* target)
{
    for (Ant const& ant : ant_swarm)
    {
        ant.render(target);
    }
}


bool AntSwarm::check_collison_player_shots(std::vector<Shot> & player_shots, Ant & ant)
{
    //for (auto & shot : player_shots)
    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        Shot & shot{player_shots.at(i)};
        if (ant.check_coll(shot))
        {
            player_shots.erase(begin(player_shots) + i);
            return true;
        }
    }
    return false;
}


std::vector<Ant>& AntSwarm::get_all_ants()
{
    return ant_swarm;
}


std::vector<Shot> &AntSwarm::get_ant_shots()
{
    return ant_shots;
}

