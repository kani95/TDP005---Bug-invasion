#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include "PlayState.h"
#include "Shot.h"
#include "MenuState.h"
// run game engine class

class Game {
private:
    sf::RenderWindow* window{};
   // sf::RenderWindow* menu;
    sf::VideoMode video_mode;
    sf::Event event{};

    int timer;

    void init_vars();
    void init_window();
    void init_states();

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
    void clear_stack();
};
#endif //MAIN_CPP_GAME_H
