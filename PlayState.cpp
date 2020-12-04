#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    std::cout << "Hello mate" << std::endl;
    player.update(leaf.shape);
    //player_shots = player.get_player_shots();
    std::vector<Shot> & player_shots{player.get_player_shots()};

    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        std::cout << "SHOT_1  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
        player_shots.at(i).move();
        std::cout << "SHOT_2  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
    }
}


void PlayState::render(sf::RenderTarget* target)
{
    std::vector<Shot> & player_shots{player.get_player_shots()};

    target -> draw(leaf.shape);
    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        target -> draw(player_shots.at(i).shape);
    }
    target -> draw(player.shape);
    target -> draw(ant.shape);
}


void PlayState::quit_state() {

}


PlayState::PlayState(sf::RenderWindow *window)
    : State(window)
    {}


PlayState::~PlayState() = default;
