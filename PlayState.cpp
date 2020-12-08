#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    //std::cout << "Hello mate" << std::endl;
    player.update(leaf.shape);
    spider.update();
    swarm.update();

    for (auto & shot_ : player_shots)
    {
        swarm.check_collison(shot_);
    }


    std::cout << swarm.get_size_swarm() << std::endl;
    //all_spiders = spider.get_all_spiders();
    //player_shots = player.get_player_shots();
    //  std::vector<Shot> & player_shots{player.get_player_shots()};

    /*for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        std::cout << "SHOT_1  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
        player_shots.at(i).move();
        std::cout << "SHOT_2  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
    }*/
}


void PlayState::render(sf::RenderTarget* target)
{
    player_shots = player.get_player_shots();
    all_spiders = spider.get_all_spiders();

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
