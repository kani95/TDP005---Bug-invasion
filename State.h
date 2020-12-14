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
protected:
    sf::RenderWindow* window{};
    std::vector<sf::Texture*> textures;
    bool is_done;
    bool exit_status;
    bool leaderboard_status;

public:
    explicit State(sf::RenderWindow* window);
    virtual ~State();

    //
    virtual void quit_state() = 0;
    virtual void update(float const& frame_time) = 0;
    // if nothing is give in the parameter render to window
    // else render to specific target
    virtual void render(sf::RenderTarget*  target) = 0;
    bool get_is_done() const;
    bool get_exit_status() const;
    bool get_leaderboard_status() const;

    /* virtual void move_down() = 0;
     virtual void move_up() = 0;*/

};


#endif //MAIN_CPP_STATE_H
