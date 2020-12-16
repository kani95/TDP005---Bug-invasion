#ifndef MAIN_CPP_PLAYSTATE_H
#define MAIN_CPP_PLAYSTATE_H
#include "State.h"
#include "Player.h"
#include "Leaf.h"
#include "AntSwarm.h"
#include "SpiderSwarm.h"
#include "Shot.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class PlayState : public State {
public:
    PlayState(sf::RenderWindow* window, std::string const& filename);
    ~PlayState() override;

    void update(float const& frame_time, sf::Event & event) override;
    void render() override;

private:
    Player* player;
    Leaf* leaf;

    AntSwarm* ant_swarm;
    std::vector<Shot> player_shots;
    std::vector<Shot> ant_shots;
    SpiderSwarm* spider_swarm;

    sf::Text score_text;
    sf::Clock game_clock;

    std::unique_ptr<sf::Texture> background_texture = std::make_unique<sf::Texture>();
    sf::Sprite background;

    void read_lvl(std::string const& filename);
    bool check_game_status();
    void update_total_score();
    void poll_events(sf::Event & event);
};
#endif //MAIN_CPP_PLAYSTATE_H
