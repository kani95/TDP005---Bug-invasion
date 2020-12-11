#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    player.update(leaf.shape, player_shots);
    // player_shots = player.get_player_shots();
    // send in a player reference to swarm, if it takes dmg call player take dmg

    spider_swarm.update(window, player_shots, ant_shots, &player);

    // !!! The update call should be made by each ant individually much more cleaner so
    ant_swarm.update(window, player_shots, ant_shots, &player);
}


void PlayState::render(sf::RenderTarget* target)
{
    //ant_shots = ant_swarm.get_ant_shots();
    all_spiders = spider_swarm.get_all_spiders();
    all_ants = ant_swarm.get_all_ants();



    target -> draw(leaf.shape);

    for (auto & shot_ : player_shots)
    {
        target -> draw(shot_.shape);
    }

    ant_swarm.render(target);

    for (auto & ant_shot : ant_shots)
    {
        target -> draw(ant_shot.shape);
    }


    target -> draw(player.shape);
    // target -> draw(ant.shape);
    for (auto & spi: all_spiders) {
        target -> draw(spi.shape);
    }
}


void PlayState::quit_state() {

}

bool PlayState::get_is_done()
{
    return is_done;
}

PlayState::PlayState(sf::RenderWindow *window)
    : State(window)
    {}


PlayState::~PlayState() = default;




bool PlayState::get_exit_status()
{
    return exit_status;
}


