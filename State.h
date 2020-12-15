#ifndef MAIN_CPP_STATE_H
#define MAIN_CPP_STATE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "stack"
#include "map"
#include <unistd.h>
#include<iostream>


class State {

protected:
    sf::RenderWindow* window{};
    std::vector<sf::Texture*> textures;
    bool is_done;
    bool exit_status;
    bool leaderboard_status;
    bool gameover_status;
    bool playstate_status;
    bool is_game_won;
    unsigned long int score;

public:
    explicit State(sf::RenderWindow* window);
    virtual ~State() = default;

    virtual void poll_events(sf::Event & event);
    virtual void quit_state() = 0;
    virtual void update(float const& frame_time) = 0;
    // if nothing is give in the parameter render to window
    // else render to specific target
    virtual void render() = 0;
    bool get_is_done() const;
    bool get_exit_status() const;
    bool get_leaderboard_status() const;
    bool get_gameover_status() const;
    bool get_playstate_status() const;
    bool get_is_game_won() const;
    unsigned long int get_score() const;


};


#endif //MAIN_CPP_STATE_H
