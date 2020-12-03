#include "PlayState.h"

void PlayState::update(float const& frame_time)
{
    std::cout << "Hello mate" << std::endl;
}


void PlayState::render(sf::RenderTarget* target)
{

}

/*PlayState::PlayState(sf::RenderWindow* window) {

}*/

//PlayState::~PlayState() ;


void PlayState::quit_state() {

}

PlayState::PlayState(sf::RenderWindow *window)
    : State(window){

}

PlayState::~PlayState() = default;
