#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "Character.h"
#include "Shot.h"
#include <vector>
#include "Spider.h"

class Player : public Character{
public:
    Player();
    void move(float dirx, float diry) override;

    void update_input();

    void update(sf::Sprite const& box,
                std::vector<Shot> & player_shots);

  //  std::vector<sf::RectangleShape> const& all_spiders
    void check_inside_leaf(sf::Sprite const& box);
    bool check_enemy_coll(sf::Sprite const& enemy);
/*    bool check_ant_shots_coll(Shot & shot);
    bool check_spider_coll(Spider & spider);
    bool check_enemy_coll(sf::RectangleShape const& all_spiders);
    void check_player_shots_coll(std::vector<sf::RectangleShape> const& all_spiders,
                                         std::vector<sf::RectangleShape> const& all_ants,
                                         std::vector<Shot> & player_shots);*/

    void add_shot(std::vector<Shot> & player_shots);
    // std::vector<Shot> & get_player_shots();

    float get_dirx();
    float get_diry();

    void take_damage() override;

    void draw(sf::RenderWindow & window);

private:
    //std::vector<Shot> player_shots;
    int timer ;
    int timer_dmg;
    bool immunity;
   // Shot new_shot;
};
#endif //MAIN_CPP_PLAYER_H
