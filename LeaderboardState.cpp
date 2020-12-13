//
// Created by andrei on 2020-12-13.
//

#include "LeaderboardState.h"

LeaderboardState::LeaderboardState(sf::RenderWindow * window)
        :State(window), is_done{false}, exit_status{false}, leaderboard_status{false}, v_score{}
{
    std::cout << "here" << std::endl;
    std::ifstream scores("Leaderboard.txt");


    unsigned long int score{};

    while (scores >> score)
    {
        //v_score.push_back(std::stol(score));
        //v_scores.push_back(name, score);
    }

    scores.close();

/*    for (auto i : v_scores)
    {
        std::cout << i << std::endl;
    }*/
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
