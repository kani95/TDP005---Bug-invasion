#ifndef GAME_ANT_H
#define GAME_ANT_H
#include "Enemy.h"
#include "Shot.h"
#include "Player.h"
#include <iostream>


class Ant : public Enemy {
public:
    Ant(std::string const& text, std::string const& shot_text,
       sf::Vector2f const& shot_dim, int const score, int const hp,
       int const att_timer);

    void move(float, float) override;
    void render(sf::RenderTarget* target) const;
    void update(std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player) override;

private:
    int att_timer;
    sf::Vector2f shot_dim;
    std::string shot_text;
    bool can_shoot() const;
    bool check_collison_player_shots(std::vector<Shot> & player_shots);
    static bool check_collison_ant_shots(std::vector<Shot> & ant_shots,
                                         Character * player);
};
#endif //GAME_ANT_H
