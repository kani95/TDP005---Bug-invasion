#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H
#include "Object.h"
#include "Player.h"
#include "Leaf.h"
#include "PlayState.h"
#include "Shot.h"
// run game engine class

class Game{
private:
    sf::RenderWindow* window{};
    sf::VideoMode video_mode;
    sf::Event event{};

    int timer;

    void init_vars();
    void init_window();
    void init_states();

    //Player* player = new Player{};
     Player player;
     Leaf leaf;
     std::vector<Shot> player_shots;

     sf::Clock tick;
     // how long it take for the game to make one update call and one render call
     float frame_time{};

     std::stack<State*> states;

public:
    Game();
    virtual ~Game();

    [[nodiscard]] bool window_status() const;
    void update_tick();
    void poll_events();
    void update();
    void render();
};


#endif //MAIN_CPP_GAME_H
