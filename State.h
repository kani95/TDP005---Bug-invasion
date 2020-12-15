#ifndef MAIN_CPP_STATE_H
#define MAIN_CPP_STATE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "stack"
#include "map"
#include <unistd.h>
#define GetCurrentDir getcwd
#include<iostream>


class State {

public:
    explicit State(sf::RenderWindow* window);
    virtual ~State();

    virtual void poll_events(sf::Event & event);
    virtual void quit_state() = 0;
    virtual void update(float const& frame_time) = 0;
    // if nothing is give in the parameter render to window
    // else render to specific target
    virtual void render() = 0;
    bool get_is_done() const;
    bool get_exit_status() const;
    bool get_leaderboard_status() const;

protected:
    sf::RenderWindow* window;
    bool is_done;
    bool exit_status;
    bool leaderboard_status;
};


#endif //MAIN_CPP_STATE_H
