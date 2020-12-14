#include "State.h"

State::State(sf::RenderWindow *window)
        :window{window}, is_done{false}, exit_status{false}, leaderboard_status{false}
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

State::~State() = default;
