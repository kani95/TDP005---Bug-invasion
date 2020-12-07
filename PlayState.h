#ifndef MAIN_CPP_PLAYSTATE_H
#define MAIN_CPP_PLAYSTATE_H
#include "State.h"
#include "Object.h"
#include "Player.h"
#include "Leaf.h"
#include "Ant.h"
#include "Shot.h"
#include <iostream>
#include <vector>
#include "SpiderSwarm.h"

class PlayState : public State {
private:

public:
    explicit PlayState(sf::RenderWindow* window);
    ~PlayState() override;
    Player player;
    Leaf leaf;
    Ant ant;
    Shot shot;
    std::vector<Shot> player_shots;
    std::vector<Spider> all_spiders;
    //Spider spider;
    SpiderSwarm spiderswarm;


    void quit_state() override;
    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target) override;

    std::vector<sf::RectangleShape> transform(std::vector<Spider> & all_spiders);

};
#endif //MAIN_CPP_PLAYSTATE_H
