//
// Created by andrei on 2020-12-13.
//

#include "LeaderboardState.h"

LeaderboardState::LeaderboardState(sf::RenderWindow * window)
        :State(window), is_done{false}, exit_status{false}, leaderboard_status{false}, string_score{}
{
    std::cout << "here" << std::endl;
    std::ifstream scores("Leaderboard.txt");

    while (getline (scores, string_score))
    {
        std::cout << string_score;
    }

    scores.close();
}


bool LeaderboardState::get_is_done()
{
    return is_done;
}


bool LeaderboardState::get_exit_status()
{
    return exit_status;
}


bool LeaderboardState::get_leaderboard_status()
{
    return leaderboard_status;
}


void LeaderboardState::update(const float &frame_time) {

}


void LeaderboardState::quit_state() {

}

void LeaderboardState::render(sf::RenderTarget *target) {

}
