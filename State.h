#ifndef MAIN_CPP_STATE_H
#define MAIN_CPP_STATE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "stack"
#include "map"


class State {
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture*> textures;

public:
    explicit State(sf::RenderWindow* window);
    virtual ~State();

    //
    virtual void quit_state() = 0;
    virtual void update(float const& frame_time) = 0;
    // if nothing is give in the parameter render to window
    // else render to specific target
    virtual void render(sf::RenderTarget*  target) = 0;
    virtual bool get_is_done() = 0;
    virtual bool get_exit_status() = 0;
    virtual bool get_leaderboard_status() = 0;

   /* virtual void move_down() = 0;
    virtual void move_up() = 0;*/
};


#endif //MAIN_CPP_STATE_H
