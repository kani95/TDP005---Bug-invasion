#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    auto vec_shape = transform(all_spiders);
    player.update(leaf.shape, vec_shape);
    spiderswarm.update(player_shots);

    // !!! The update call should be made by each ant individually much more cleaner so
    swarm.update(player_shots);

}


void PlayState::render(sf::RenderTarget* target)
{
    player_shots = player.get_player_shots();
    ant_shots = swarm.get_ant_shots();
    all_spiders = spiderswarm.get_all_spiders();

    target -> draw(leaf.shape);

    for (auto & shot_ : player_shots)
    {
        target -> draw(shot_.shape);
    }

    swarm.render(target);

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


PlayState::PlayState(sf::RenderWindow *window)
    : State(window)
    {}


PlayState::~PlayState() = default;


std::vector<sf::RectangleShape> PlayState::transform(std::vector<Spider> & all_spiders)
{
    std::vector<sf::RectangleShape> vec_shape;

    for (auto spider : all_spiders)
    {
        vec_shape.push_back(spider.shape);
    }

    return vec_shape;
}