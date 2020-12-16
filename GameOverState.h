#ifndef ANT_CPP_GAMEOVERSTATE_H
#define ANT_CPP_GAMEOVERSTATE_H

#include "MenuState.h"
#include <fstream>

class GameOverState : public MenuState
{
public:
    explicit GameOverState(sf::RenderWindow * window, bool is_game_won,
                           size_t total_score);

    void update(float const frame_time, sf::Event & event) override;
    void render() override;

private:
    sf::Text game_over;
    bool is_game_won;

    void set_ui();
    void set_choices() override;
    void write_score_to_file(std::string const& file) const;
};

#endif //ANT_CPP_GAMEOVERSTATE_H
