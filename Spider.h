#ifndef GAME_H_SPIDER_H
#define GAME_H_SPIDER_H
#include "Enemy.h"
#include <vector>
#include "Shot.h"

class Spider : public Enemy {
public:
    Spider();
    void move(float const, float const) override;
    void update(const sf::RenderTarget* window,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player) override;

    void set_start_pos();
    //void add_second();
    bool check_coll(sf::RectangleShape & enemy);
    void check_coll_player_shots(std::vector<Shot> & player_shots, Character * player);
    void get_movement();


   void check_coll_screen();

    //std::vector<Spider>& get_all_spiders();
private:
    //int timer;
   // std::vector<Spider> all_spiders;
};

#endif
