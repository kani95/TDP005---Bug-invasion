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
#include <string>
#include <fstream>
#include "SpiderSwarm.h"


class PlayState : public State {
private:

    void read_lvl(std::string const& filename);

public:
    PlayState(sf::RenderWindow* window, std::string const& filename);
    ~PlayState() override;
   // const sf::RenderTarget(*window){};
    Player* player{};
    Leaf* leaf{};

    AntSwarm ant_swarm;
    std::vector<Shot> player_shots;
    std::vector<Shot> ant_shots;
    //std::vector<Ant> all_ants;
    //std::vector<Spider> all_spiders;
    SpiderSwarm spider_swarm;
    unsigned long int total_score;


    void quit_state() override;
    void update(float const& frame_time) override;
    void update_total_score();
    void render() override;
    void poll_events(sf::Event & event);

    sf::Font font;
    sf::Text score_text;
    sf::Clock game_clock;
};
#endif //MAIN_CPP_PLAYSTATE_H
