#ifndef ANT_CPP_LEADERBOARDSTATE_H
#define ANT_CPP_LEADERBOARDSTATE_H
#include "State.h"
#include <fstream>

class LeaderboardState : public State
{
public:
    explicit LeaderboardState(sf::RenderWindow * window);

    void update(float const, sf::Event & event) override;
    void render() override;

private:
    std::vector<size_t> v_scores;
    sf::Text score_text;
    sf::Text back_button;
    sf::Text top_score_text;

    void set_font();
    void load_scores(std::string const& file_name);
    void sort_scores();
    void set_ui(sf::RenderWindow* target);
    void poll_events(sf::Event &event) override;
    void overwrite_file(std::string const& filename);
    void render_scores();
};


#endif //ANT_CPP_LEADERBOARDSTATE_H
