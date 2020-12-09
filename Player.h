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

    void update(sf::RectangleShape const& box,
                std::vector<sf::RectangleShape> const& all_spiders,
                std::vector<sf::RectangleShape> const& all_ants,
                std::vector<Shot> const& ant_shots);


    void check_inside_leaf(sf::RectangleShape const& box);
    void check_coll(std::vector<Shot> const& ant_shots,
                    std::vector<sf::RectangleShape> const& all_spiders);
    bool check_enemy_coll(sf::RectangleShape const& all_spiders);
    void check_player_shots_coll(std::vector<sf::RectangleShape> const& all_spiders,
                                         std::vector<sf::RectangleShape> const& all_ants);

    void add_shot();
    std::vector<Shot> & get_player_shots();

    float get_dirx();
    float get_diry();

    void take_damage();

    void draw(sf::RenderWindow & window);

private:
    std::vector<Shot> player_shots;
    int timer ;
    int timer_dmg;
    bool immunity;
   // Shot new_shot;
};
#endif //MAIN_CPP_PLAYER_H
