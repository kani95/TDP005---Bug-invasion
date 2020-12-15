#ifndef GAME_H_SPIDER_H
#define GAME_H_SPIDER_H
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
    void update(std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player) override;

private:
    sf::Vector2f spw_lmt_x;
    sf::Vector2f spw_lmt_y;

    void set_start_pos(sf::Vector2f const& spw_lmt_x,
                       sf::Vector2f const& spw_lmt_y);
    void check_coll_screen();
    void check_coll_player_shots(std::vector<Shot> & player_shots, Character * player);
};

#endif
