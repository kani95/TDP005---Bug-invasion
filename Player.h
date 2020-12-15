#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "Character.h"
#include "Shot.h"
#include <vector>
#include "Spider.h"

class Player : public Character {
public:
    Player() = default;
    Player(std::string const& text, std::string const& shot_text,
           sf::Vector2f const& pos, sf::Vector2f const& dir,
           sf::Vector2f const& dim, float const movespeed,
           int const hp, int const att_timer,
           sf::Vector2f const& shot_dim,
           sf::Vector2f const& shot_dir);

    void move(float dirx, float diry) override;

    void update_input(float const frame_time);

    void update(sf::Sprite const& box,
                std::vector<Shot> & player_shots, float const frame_time);

    void check_inside_leaf(sf::Sprite const& box);

    void add_shot(std::vector<Shot> & player_shots);
    float get_dirx();
    float get_diry();
    void take_damage() override;

private:
    int timer;
    int timer_dmg;
    int att_timer;

    sf::Vector2f shot_dim;
    sf::Vector2f shot_dir;
    std::string shot_text;
};
#endif //MAIN_CPP_PLAYER_H
