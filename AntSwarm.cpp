#include "AntSwarm.h"

AntSwarm::AntSwarm()
    :ant_swarm{}
{
    float prev_x {220.f};
    float prev_y {70.f};
    for (unsigned short int i{0}; i < 30; i++)
    {
        prev_x = prev_x + 40.f;
        std::cout << prev_x << std::endl;
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


/*std::pair<unsigned short int, unsigned short int> AntSwarm::find_furthest_ant()
{
    // init vars to the first ant of the vector, x coords
    // this will crash if no ants are in the vector

    unsigned short int ant_right_id{ant_swarm.at(0).get_id()};
    unsigned short int ant_left_id{ant_swarm.at(0).get_id()};
    float furthest_right{ant_swarm.at(0).shape.getPosition().x};
    float furthest_left{ant_swarm.at(0).shape.getPosition().x};

    for(unsigned int i{0}; i < get_size_swarm(); ++i)
    {
        float current_ant_pos = ant_swarm.at(i).shape.getPosition().x;
        if (current_ant_pos > furthest_right)
        {
            furthest_right = current_ant_pos;
            ant_right_id = ant_swarm.at(i).get_id();
        }
        else if (current_ant_pos < furthest_left)
        {
            furthest_left = current_ant_pos;
            ant_left_id = ant_swarm.at(i).get_id();
        }
    }

    return {ant_left_id, ant_right_id};
}*/

/*void AntSwarm::move_swarm()
{
    std::pair<unsigned short int, unsigned short int> ant_left_id, ant_right_id;
    ant_left_id{find_furthest_ant().first};
    ant_right_id{find_furthest_ant().second};

    for(unsigned int i{0}; i < get_size_swarm(); ++i)
    {

    }
}*/


void AntSwarm::update(const sf::RenderTarget* window, std::vector<Shot> & player_shots)
{

    //check_collison_player_shots(player_shots);
    // for (Ant & ant : ant_swarm)
    for(unsigned int i{0}; i < ant_swarm.size(); ++i)
    {
        Ant ant{ant_swarm.at(i)};

        if (check_collison_player_shots(player_shots, ant))
        {
            ant_swarm.erase(begin(ant_swarm) + i);
            continue;
        }

        ant.update(window);

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
            // check if player took dmg;
            // call player function take dmg;
            // check if ant took dmg from player
        }
        ant_shots.at(i).move(0.f, 5.f);

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
        Shot shot{player_shots.at(i)};
        if (ant.check_coll(shot))
        {
            std::cout << "ant swarm 1 __" <<player_shots.size() << std::endl;
            player_shots.erase(begin(player_shots) + i);
            std::cout << "ant swarm 2 __" <<player_shots.size() << std::endl;
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

