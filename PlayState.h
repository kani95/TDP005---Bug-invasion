#ifndef MAIN_CPP_PLAYSTATE_H
#define MAIN_CPP_PLAYSTATE_H
#include "State.h"
#include "Object.h"
#include "Player.h"
#include "Leaf.h"
#include "Ant.h"
#include "Shot.h"
#include <iostream>

class PlayState : public State {
private:

public:
    explicit PlayState(sf::RenderWindow* window);
    ~PlayState() override;
    Player player;
    Leaf leaf;
    Ant ant;
    //std::vector<Shot> player_shots;



    void quit_state() override;
    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target) override;

};
#endif //MAIN_CPP_PLAYSTATE_H
