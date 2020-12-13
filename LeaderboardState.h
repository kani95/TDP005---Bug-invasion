#ifndef ANT_CPP_LEADERBOARDSTATE_H
#define ANT_CPP_LEADERBOARDSTATE_H
#include "State.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class LeaderboardState : public State{
public:
    explicit LeaderboardState(sf::RenderWindow * window);

    bool get_is_done() override;
    bool get_exit_status() override;
    bool get_leaderboard_status() override;

    void update(float const& frame_time) override;
    void quit_state() override;
    void render(sf::RenderTarget*  target) override;


private:
    bool is_done;
    bool exit_status;
    bool leaderboard_status;
    std::vector<unsigned long int> v_score;
};


#endif //ANT_CPP_LEADERBOARDSTATE_H
