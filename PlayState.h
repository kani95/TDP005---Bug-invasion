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

public:
    PlayState(sf::RenderWindow* window, std::string const& filename);
    ~PlayState() override;
    const sf::RenderTarget(*window){};
    Player* player{};
    Leaf* leaf{};

    AntSwarm ant_swarm;
    std::vector<Shot> player_shots;
    std::vector<Shot> ant_shots;
    std::vector<Spider> all_spiders;
    SpiderSwarm spider_swarm;
    std::vector<Ant> all_ants;
    bool is_done = false;
    bool exit_status = false;
    bool leader_board = false;

/*    void move_down() = delete;
    void move_up() = delete;*/


    void read_lvl(std::string const& filename);

    void quit_state() override;
    void update(float const& frame_time) override;
    void update_total_score();
    void render(sf::RenderTarget* target) override;


    sf::Clock game_clock;
    unsigned long int total_score;


    sf::Font font;
    sf::Text score_text;


};
#endif //MAIN_CPP_PLAYSTATE_H
