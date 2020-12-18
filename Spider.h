#ifndef GAME_H_SPIDER_H
#define GAME_H_SPIDER_H

#include <random>
#include "Enemy.h"

class Spider : public Enemy {
public:

    Spider(std::string const& text,
           sf::Vector2f const& dim,
           sf::Vector2f const& dir,
           sf::Vector2f const& spawn_limit_x,
           sf::Vector2f const& spawn_limit_y,
           int const score,
           int const hp);

    void move(float const, float const) override;
    void update(float const frame_time,
            std::vector<Shot> & player_shots,
            std::vector<Shot> & ant_shots,
            Character* player) override;

private:

    void set_start_pos(sf::Vector2f const& spw_lmt_x,
                       sf::Vector2f const& spw_lmt_y);
    void keep_inside_screen(float const);
    void collision_player(std::vector<Shot> & player_shots,
                          Character * player);
};

#endif
