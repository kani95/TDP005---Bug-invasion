#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"
#include "Shot.h"
#include "Player.h"
#include "Shot.h"
#include <iostream>

// type 1 enemy
class Ant : public Enemy {
public:
    Ant(std::string const& text, std::string const& shot_text,
        sf::Vector2f const& shot_dir, sf::Vector2f const& shot_dim,
        int const score, int const hp, int const att_timer);


    //int get_score() const override;
    void move(float , float) override;
    void render(sf::RenderTarget* target) const;
    void update(const sf::RenderTarget* window,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player) override;

    bool check_collison_player_shots(std::vector<Shot> & player_shots);
    bool check_collison_ant_shots(std::vector<Shot> & ant_shots, Character * player);

    bool can_shoot();

    bool check_coll(Shot & shot);


private:

    int att_timer;
    sf::Vector2f shot_dir;
    sf::Vector2f shot_dim;
    std::string shot_text;
   // sf::Clock clock;
};

#endif //GAME_ANT_H
