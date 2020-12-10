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


// 1. hp problem
// 2. när skriver vi ut ett nytt fönster?
// 3. shots collision vi gör det på många ställer
// 4. hur kan vi sapara shots i playstate? , vecshape, collision check happends in player
// 5. läsa in från fil?


class PlayState : public State {
private:

public:
    explicit PlayState(sf::RenderWindow* window);
    ~PlayState() override;
    const sf::RenderTarget(*window);
    Player player;
    Leaf leaf;
    // Ant ant;
    Shot shot;
    AntSwarm ant_swarm;
    std::vector<Shot> player_shots;
    std::vector<Shot> ant_shots;
    std::vector<Spider> all_spiders;
    //Spider spider;
    SpiderSwarm spider_swarm;
    std::vector<Ant> all_ants;
    bool is_done = false;
    bool exit_status = false;

/*    void move_down() = delete;
    void move_up() = delete;*/

    void quit_state() override;
    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target) override;
    bool get_is_done() override;
    bool get_exit_status() override;

    std::vector<sf::RectangleShape> transform(std::vector<Spider> const& all_spiders);
    std::vector<sf::RectangleShape> transform_ant(std::vector<Ant> const& all_ants);

};
#endif //MAIN_CPP_PLAYSTATE_H
