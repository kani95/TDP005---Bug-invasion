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
    void move_swarm(const sf::RenderTarget* target);


    int get_size_swarm() const;

    std::vector<Ant>& get_all_ants();

    void update(const sf::RenderTarget* target,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player);

private:
    //std::vector<Shot> ant_shots;
    std::vector<Ant> ant_swarm;
    bool is_swarm_right{true};
    short int border_hit{};
    sf::Vector2f direction;
    int border_limit_left;
    int border_limit_right;

};

#endif //GAME_ANTSWARM_H
