#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include "PlayState.h"
#include "Shot.h"
#include "MenuState.h"
#include "LeaderboardState.h"
// run game engine class

enum class all_states {menu};

class Game {
public:
    Game();
    virtual ~Game();

    [[nodiscard]] bool window_status() const;
    //void update_tick();
   // void poll_events();
    void update();
    void render();
    void clear_stack();

private:
    std::stack<State*> states;
    sf::RenderWindow* window;
    sf::VideoMode video_mode;
    sf::Event event{};
    sf::Clock clock;
    sf::Time tick;

    int timer;
    // how long it take for the game to make one update call and one render call
    float frame_time;

    void init_window();
    void init_states();
};
#endif //MAIN_CPP_GAME_H
