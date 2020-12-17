#ifndef GAME_ANTSWARM_H
#define GAME_ANTSWARM_H
#include "Ant.h"
#include <iostream>
#include "Player.h"

class AntSwarm {
public:

    AntSwarm() = default;
    AntSwarm(std::string const& text,
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
             int const att_timer);

    void render(sf::RenderTarget* target);
    std::pair<float, float> find_furthest_ants();
    void move_swarm(float const frame_time);

    int get_size_swarm() const;

    void update(float const frame_time,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player);

private:
    std::vector<Ant> ant_swarm;
    bool is_swarm_right{true};
    short int border_hit{};
    int border_limit_left;
    int border_limit_right;
    sf::Vector2f direction;
    sf::Vector2f shot_dir;
};

#endif //GAME_ANTSWARM_H
