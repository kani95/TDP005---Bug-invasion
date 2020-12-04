#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    std::cout << "Hello mate" << std::endl;
    player.update(leaf.shape);
}


void PlayState::render(sf::RenderTarget* target)
{

    target -> draw(leaf.shape);
    target -> draw(player.shape);
    target -> draw(ant.shape);
}


void PlayState::quit_state() {

}


PlayState::PlayState(sf::RenderWindow *window)
    : State(window){

}


PlayState::~PlayState() = default;
