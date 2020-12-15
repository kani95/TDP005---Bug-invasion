#include "State.h"

State::State(sf::RenderWindow *window)
        :window{window}, is_done{false}, exit_status{false},
        leaderboard_status{false}, gameover_status{false},
        playstate_status{false}, is_game_won{false}
{}

bool State::get_is_done() const
{
    return is_done;
}

bool State::get_exit_status() const
{
    return exit_status;
}

bool State::get_leaderboard_status() const
{
    return leaderboard_status;
}

bool State::get_gameover_status() const
{
    return gameover_status;
}


bool State::get_playstate_status() const
{
    return playstate_status;
}

bool State::get_is_game_won() const
{
    return is_game_won;
}