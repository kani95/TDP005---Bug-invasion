#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    //std::cout << "Hello mate" << std::endl;

    auto vec_shape_spider = transform(all_spiders);
    auto vec_shape_ant = transform_ant(all_ants);
    player.update(leaf.shape, vec_shape_spider, vec_shape_ant);
    spiderswarm.update(player_shots);

    // !!! The update call should be made by each ant individually much more cleaner so
    swarm.update(player_shots);


  //  std::cout << swarm.get_size_swarm() << std::endl;

    //all_spiders = spider.get_all_spiders();
    //player_shots = player.get_player_shots();
    //  std::vector<Shot> & player_shots{player.get_player_shots()};

 /*   for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        std::cout << "SHOT_1  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
        player_shots.at(i).move();
        std::cout << "SHOT_2  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
    }*/
}


void PlayState::render(sf::RenderTarget* target)
{
    player_shots = player.get_player_shots();
    all_spiders = spiderswarm.get_all_spiders();
    all_ants = swarm.get_all_ants();

    target -> draw(leaf.shape);

    for (auto & shot_ : player_shots)
    {
        target -> draw(shot_.shape);
    }


    swarm.render(target);

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
