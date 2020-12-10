#include "PlayState.h"


void PlayState::update(float const& frame_time)
{

    //std::cout << "Hello mate" << std::endl;

    auto vec_shape_spider = transform(all_spiders);
    auto vec_shape_ant = transform_ant(all_ants);

    player.update(leaf.shape, vec_shape_spider, vec_shape_ant, ant_shots, player_shots);
    // player_shots = player.get_player_shots();
    // send in a player reference to swarm, if it takes dmg call player take dmg
    spider_swarm.update(window, player_shots, player);


    // !!! The update call should be made by each ant individually much more cleaner so
    ant_swarm.update(window, player, player_shots);
}


void PlayState::render(sf::RenderTarget* target)
{
    ant_shots = ant_swarm.get_ant_shots();
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


PlayState::PlayState(sf::RenderWindow *window)
    : State(window)
    {}


PlayState::~PlayState() = default;

std::vector<sf::RectangleShape> PlayState::transform(std::vector<Spider> const& to_copy_vec)
{
    std::vector<sf::RectangleShape> vec_shape{};

    for (Spider element : to_copy_vec)
    {
        vec_shape.push_back(element.shape);
    }

    return vec_shape;
}

std::vector<sf::RectangleShape> PlayState::transform_ant(std::vector<Ant> const& all_ants)
{
    std::vector<sf::RectangleShape> vec_shape;

    for (auto ant : all_ants)
    {
        vec_shape.push_back(ant.shape);
    }

    return vec_shape;
}
