#include "AntSwarm.h"

AntSwarm::AntSwarm(std::string const& text,
                   std::string const& shot_text,
                   sf::Vector2f & pos,
                   sf::Vector2f const& dim,
                   sf::Vector2f & dist,
                   sf::Vector2f & dir,
                   sf::Vector2f & shot_dir,
                   sf::Vector2f & shot_dim,
                   int const border_limit_left,
                   int const border_limit_right,
                   unsigned short int const total_ants,
                   int const number_of_rows,
                   int const score,
                   int const hp,
                   int const att_timer)
    :ant_swarm{}, direction{dir}, border_limit_right{border_limit_right}, border_limit_left{border_limit_left}, shot_dir{shot_dir}
{
    float prev_x {pos.x};
    for (unsigned short int i{0}; i < total_ants; i++)
    {
        Ant ant{text, shot_text, shot_dim, score, hp, att_timer};
        ant.set_position(pos);
        pos.x += dist.x;
        ant.set_scale(dim);
        ant_swarm.push_back(ant);

        // second row
        if (i == total_ants/number_of_rows - 1)
        {
            pos.x = prev_x;
            pos.y += (dist.y + dim.y);
        }
        // third row
        else if (i == (total_ants/number_of_rows) * 2 - 1)
        {
            pos.x = prev_x;
            pos.y += (dist.y + dim.y);
        }
    }
}


int AntSwarm::get_size_swarm() const
{
    return ant_swarm.size();
}


std::pair<float, float> AntSwarm::find_furthest_ants()
{

    float ant_left_x{ant_swarm.at(0).get_left()};
    float ant_right_x{ant_swarm.at(0).get_left()};


    for (unsigned int i{0}; i < get_size_swarm(); ++i) {
        float current_ant_pos = ant_swarm.at(i).get_left();


        if (current_ant_pos < ant_right_x) {
            ant_right_x = current_ant_pos;
        } else if (current_ant_pos > ant_left_x) {
            ant_left_x = current_ant_pos;
        }

    }
    return {ant_left_x, ant_right_x};
}


void AntSwarm::move_swarm(float const frame_time)
{
    if(!ant_swarm.empty())
    {
        float x_value_left{find_furthest_ants().second};
        float x_value_right{find_furthest_ants().first};

        // std::cout << border_hit << std::endl;

        float x_movement{direction.x * frame_time};
        float y_movement{direction.y * frame_time};

        if (border_hit % 2 != 0) {
            if (border_hit <= 5) {
                y_movement = 10.f;
                x_movement = 0.f;
                border_hit += 1;
            } else {
                y_movement = -10.f;
                x_movement = 0.f;
                border_hit += 1;
            }

            if (border_hit > 11) {
                border_hit = 0;
            }
        }

        // calculate the new x coordnates if the ant furthes right and left
        // were to move, if the new postion is outside the screen border change direction
        if (is_swarm_right) {
            if (x_value_right + x_movement > border_limit_right) {
                is_swarm_right = false;
                border_hit += 1;
            }
        } else {
            if (x_value_left + x_movement < border_limit_left) {
                is_swarm_right = true;
                border_hit += 1;
            }
        }


        // check which way the swarm is going to move, move each ant
        if (is_swarm_right) {
            for (unsigned int i{0}; i < get_size_swarm(); ++i) {
                Ant &ant{ant_swarm.at(i)};
                ant.move(x_movement, y_movement);
            }
        } else {
            for (unsigned int i{0}; i < get_size_swarm(); ++i) {
                Ant &ant{ant_swarm.at(i)};
                ant.move(-x_movement, y_movement);
            }
        }
    }
}


void AntSwarm::update(float const frame_time,
                      std::vector<Shot> & player_shots,
                      std::vector<Shot> & ant_shots,
                      Character* player)
{

    for(unsigned int i{0}; i < ant_swarm.size(); ++i) {
        Ant & ant{ant_swarm.at(i)};

        ant.update(player_shots, ant_shots, player);

        if (ant.is_dead()) {

            player -> increase_score(ant.get_score());

            ant_swarm.erase(begin(ant_swarm) + i);
        }
    }

    for (Shot & shot : ant_shots)
    {
        shot.move(shot_dir.x * frame_time, shot_dir.y * frame_time);
    }

    move_swarm(frame_time);
}


void AntSwarm::render(sf::RenderTarget* target)
{
    for (Ant const& ant : ant_swarm)
    {
       ant.render(target);
      // target -> draw(ant.shape);
    }
}


/*std::vector<Ant>& AntSwarm::get_all_ants()
{
    return ant_swarm;
}*/
