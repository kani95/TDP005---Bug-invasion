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
    void load_font(std::string const& font_name);
    void load_scores(std::string const& file_name);
    static void sort_scores(std::vector<unsigned long int> & vector_scores);
    void set_ui(sf::RenderTarget* target);

    // Update
    void input();
    void update(float const& frame_time) override;

    // Render
    void render_scores(std::vector<unsigned long int> const& vector_scores,
                       sf::RenderTarget* target);
    void render(sf::RenderTarget*  target) override;

    // MOVE TO STATE
    bool get_is_done() override;
    bool get_exit_status() override;
    bool get_leaderboard_status() override;
    void quit_state() override;


private:
    bool is_done;
    bool exit_status;
    bool leaderboard_status;
    std::vector<unsigned long int> v_score;
    sf::Font font;
    sf::Text score_text;
    sf::Text back_button;
    sf::Text top_score_text;
};


#endif //ANT_CPP_LEADERBOARDSTATE_H
