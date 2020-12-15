#ifndef ANT_CPP_GAMEOVERSTATE_H
#define ANT_CPP_GAMEOVERSTATE_H
#include "MenuState.h"
#include <iostream>
#include <fstream>

#define MAX_NUMBER_OF_ITEMS 3

class GameOverState : public MenuState{
public:
    explicit GameOverState(sf::RenderWindow * window, bool is_game_won,
                           unsigned long int score);

    void set_choices() override;

    void set_ui();

    void update(float const& frame_time, sf::Event & event) override;
    void render() override;
    void write_score_to_file(std::string const& file) const;

private:
    sf::Text game_over;
    bool is_game_won;
    unsigned long int total_score;
};


#endif //ANT_CPP_GAMEOVERSTATE_H
