#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include "PlayState.h"
#include "LeaderboardState.h"
#include "GameOverState.h"
#include <stack>


class Game {
public:
    Game();
    ~Game();

    bool window_status() const;
    void update();
    void render() const;

private:
    std::stack<State*> states;
    sf::RenderWindow* window;
    sf::VideoMode video_mode;
    sf::Event event;
    sf::Clock delta_clock;

    float delta;
    size_t score;

    void init_window();
    void init_states();
    void update_delta();
    void remove_top();
};
#endif //MAIN_CPP_GAME_H
