#ifndef MAIN_CPP_PLAYSTATE_H
#define MAIN_CPP_PLAYSTATE_H
#include "State.h"
#include "Object.h"
#include "Player.h"
#include "Leaf.h"
#include "Ant.h"
#include "AntSwarm.h"
#include "Shot.h"
#include <iostream>
#include <vector>
#include "SpiderSwarm.h"


class PlayState : public State {
private:

public:
    explicit PlayState(sf::RenderWindow* window);
    ~PlayState() override;
    Object(window);
    Player player;
    Leaf leaf;
    // Ant ant;
    Shot shot;
    AntSwarm antswarm;
    std::vector<Shot> player_shots;
    std::vector<Shot> ant_shots;
    std::vector<Spider> all_spiders;
    //Spider spider;
    SpiderSwarm spiderswarm;
    std::vector<Ant> all_ants;


    void quit_state() override;
    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target) override;


    std::vector<sf::RectangleShape> transform(std::vector<Spider> const& all_spiders);
    std::vector<sf::RectangleShape> transform_ant(std::vector<Ant> const& all_ants);

};
#endif //MAIN_CPP_PLAYSTATE_H
