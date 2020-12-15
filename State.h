#ifndef MAIN_CPP_STATE_H
#define MAIN_CPP_STATE_H
#include <SFML/Graphics.hpp>

class State {

public:
    explicit State(sf::RenderWindow* window);
    virtual ~State() = default;

    virtual void poll_events(sf::Event & event);
    virtual void update(float const& frame_time, sf::Event & event) = 0;
    virtual void render() = 0;

    bool get_is_done() const;
    bool get_exit_status() const;
    bool get_leaderboard_status() const;
    bool get_gameover_status() const;
    bool get_playstate_status() const;
    bool get_is_game_won() const;
    unsigned long int get_score() const;

protected:
    sf::RenderWindow* window;
    bool is_done;
    bool exit_status;
    bool leaderboard_status;
    bool gameover_status;
    bool playstate_status;
    bool is_game_won;
    unsigned long int score;
};


#endif //MAIN_CPP_STATE_H
