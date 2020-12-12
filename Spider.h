#ifndef GAME_H_SPIDER_H
#define GAME_H_SPIDER_H
#include "Enemy.h"
#include <vector>
#include "Shot.h"

class Spider : public Enemy {
public:
    Spider(sf::Vector2f const& dim,
           sf::Vector2f const& dir,
           sf::Vector2f const& spawn_limit_x,
           sf::Vector2f const& spawn_limit_y,
           int const score,
           int const hp);
   // int get_score() const override;
    void move(float const, float const) override;
    void update(const sf::RenderTarget* window,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player) override;
    void set_start_pos(sf::Vector2f const& spw_lmt_x,
                       sf::Vector2f const& spw_lmt_y);
    //void add_second();
    bool check_coll(sf::RectangleShape & enemy);
    void check_coll_player_shots(std::vector<Shot> & player_shots, Character * player);
    void get_movement();


   void check_coll_screen();

    //std::vector<Spider>& get_all_spiders();
private:

    sf::Vector2f spw_lmt_x;
    sf::Vector2f spw_lmt_y;
    //int timer;
   // std::vector<Spider> all_spiders;
};

#endif
