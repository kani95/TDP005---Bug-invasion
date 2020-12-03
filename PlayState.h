#ifndef MAIN_CPP_PLAYSTATE_H
#define MAIN_CPP_PLAYSTATE_H
#include "State.h"


class PlayState : public State {
private:

public:
    explicit PlayState(sf::RenderWindow* window);
    ~PlayState() override;

    void quit_state();
    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target = nullptr) override;

};


#endif //MAIN_CPP_PLAYSTATE_H
