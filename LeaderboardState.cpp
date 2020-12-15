#include "LeaderboardState.h"

LeaderboardState::LeaderboardState(sf::RenderWindow * window)
        :State(window), v_score{},score_text{},
        font{}, back_button{}, top_score_text{}
{
    // load font should be defined in state
    score_text.setCharacterSize(21);
    load_font("ARCADECLASSIC.TTF");
    load_scores("Leaderboard.txt");
    sort_scores(v_score);
    set_ui(window);
}


void LeaderboardState::load_font(std::string const& font_name)
{
    if (!font.loadFromFile(font_name))
    {
        std::cerr << "Failed to load font in PlayState.";
    }

    score_text.setFont(font);
    top_score_text.setFont(font);
    back_button.setFont(font);
}


void LeaderboardState::load_scores(std::string const& file_name)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        std::string line{};
        while (std::getline(file, line))
        {
            v_score.push_back(std::stol(line));
        }
        file.close();
    }
}


void LeaderboardState::sort_scores(std::vector<unsigned long int> & v_scores)
{
    std::sort(v_scores.begin(), v_scores.end(), std::greater<>());
}


void LeaderboardState::set_ui(sf::RenderTarget* target)
{
    top_score_text.setCharacterSize(56);
    top_score_text.setString("TOP SCORES");
    top_score_text.setPosition(sf::Vector2f(
            target -> getSize().x / 2.f - top_score_text.getCharacterSize() * 2.5,
            10));

    back_button.setCharacterSize(31);
    back_button.setString("ESC   TO   BACK");
    back_button.setPosition(0,0);
}


void LeaderboardState::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        is_done = true;
    }
}


void LeaderboardState::update(const float &frame_time)
{
    input();
}


void LeaderboardState::render_scores(std::vector<unsigned long> const& vector_scores, sf::RenderTarget* target)
{

    // std::cout << target -> getSize().x << std::endl;
    // crash if file doesnt have 10 rows
    for (int i{}; i < 11; i++)
    {
        std::string curr{std::to_string(vector_scores.at(i))};

        score_text.setString(std::to_string(i) + " " + curr);
        score_text.setPosition(sf::Vector2f(
                target -> getSize().x / 2.f - 70.f,
                target -> getSize().y / (18.f) * ((float)i + 4.f)));

        target -> draw(score_text);
    }
}


void LeaderboardState::render(sf::RenderTarget *target)
{
    target -> draw(top_score_text);
    target -> draw(back_button);
    render_scores(v_score, target);
}


void LeaderboardState::quit_state()
{

}
