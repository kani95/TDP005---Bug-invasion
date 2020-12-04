#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    std::cout << "Hello mate" << std::endl;
    player.update(leaf.shape);
}


void PlayState::render(sf::RenderTarget* target)
{


    target -> draw(leaf.shape);
    player_shots = player.get_player_shots();

    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        player_shots.at(i).shape.move(0.f,20.f);
        target -> draw(player_shots.at(i).shape);
    }
    target -> draw(player.shape);
    target -> draw(ant.shape);
}


void PlayState::quit_state() {

}


PlayState::PlayState(sf::RenderWindow *window)
    : State(window){

}


PlayState::~PlayState() = default;
