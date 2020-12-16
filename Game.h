#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include "PlayState.h"
#include "LeaderboardState.h"
#include "GameOverState.h"
#include <stack>
#include <stdlib.h>


// run game engine class

class Game {
public:
    Game();
    ~Game() = default;

    bool window_status() const;
    //void update_tick();
    void update();
    void render() const;


private:
    std::stack<State*> states;
    sf::RenderWindow* window;
    sf::VideoMode video_mode;
    sf::Event event{};
    sf::Clock delta_clock;
    sf::Time tick;
    sf::Clock clock;
    sf::Time last_update = sf::Time::Zero;

    float delta;
    unsigned long int score;

    void init_window();
    void init_states();
    void clear_stack();

    void update_delta();
};
#endif //MAIN_CPP_GAME_H
