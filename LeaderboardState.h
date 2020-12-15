#ifndef ANT_CPP_LEADERBOARDSTATE_H
#define ANT_CPP_LEADERBOARDSTATE_H
#include "State.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class LeaderboardState : public State{
public:
    explicit LeaderboardState(sf::RenderWindow * window);

    // Constructor functions
    void load_font(std::string const& font_name); // !! THIS CAN BE MOVED IN STATE.h
    void load_scores(std::string const& file_name);
    void sort_scores();
    void set_ui(sf::RenderWindow* target);
    void poll_events(sf::Event &event) override;
    void overwrite_file(std::string const& filename);

    // Update
    void input();
    void update(float const& frame_time, sf::Event & event) override;

    // Render
    void render_scores();
    void render() override;



private:

    std::vector<size_t> v_scores;
    sf::Font font;
    sf::Text score_text;
    sf::Text back_button;
    sf::Text top_score_text;
};


#endif //ANT_CPP_LEADERBOARDSTATE_H
