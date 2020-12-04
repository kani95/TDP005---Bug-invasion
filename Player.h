#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include "Character.h"
#include "Shot.h"
#include <vector>

class Player : public Character{
public:
    Player();
    void move(float const dirx, float const diry) override;

    void update(sf::RectangleShape const& box);
    bool check_inside_leaf(sf::RectangleShape const& box);

    void add_shot();
    std::vector<Shot> & get_player_shots();

    float get_dirx();
    float get_diry();


    void draw(sf::RenderWindow & window);

private:
    std::vector<Shot> player_shots;
    int timer;
   // Shot new_shot;
};
#endif //MAIN_CPP_PLAYER_H
