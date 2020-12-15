#ifndef ANT_CPP_GAMEOVERSTATE_H
#define ANT_CPP_GAMEOVERSTATE_H
#include "MenuState.h"
#define MAX_NUMBER_OF_ITEMS 3

class GameOverState : public MenuState{
public:
    explicit GameOverState(sf::RenderWindow * window,
                           bool is_game_won);

    void set_choices() override;

    void set_ui(sf::RenderTarget * target);

    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target) override;

private:
    sf::Text game_over;
    bool is_game_won;
};


#endif //ANT_CPP_GAMEOVERSTATE_H
