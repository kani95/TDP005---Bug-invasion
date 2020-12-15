#include "LeaderboardState.h"

LeaderboardState::LeaderboardState(sf::RenderWindow * window)
        :State(window), v_scores{},score_text{},
        font{}, back_button{}, top_score_text{}
{
    // load font should be defined in state
    score_text.setCharacterSize(21);
    load_font("ARCADECLASSIC.TTF");
    load_scores("Leaderboard.txt");
    sort_scores();
    if (v_scores.size() > 50) {
        overwrite_file("Leaderboard.txt");
    }
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
            try
            {
                v_scores.push_back(std::stol(line));
            }
            catch (std::invalid_argument & arg)
            {
                std::cerr << "Empty leaderboard or couldn't translate character to long int\n";
            }
        }

        file.close();
    }
}


void LeaderboardState::sort_scores()
{
    std::sort(v_scores.begin(), v_scores.end(), std::greater<>());
}

void LeaderboardState::overwrite_file(std::string const& filename)
{
    while(v_scores.size() > 50)
    {
        v_scores.pop_back();
    }

    std::ofstream outfile{filename, std::ios::trunc};

    for (size_t i{}; i < v_scores.size(); ++i)
    {
        outfile << std::to_string(v_scores.at(i));

        if (i != v_scores.size() - 1)
        {
            outfile << '\n';
        }
    }

    outfile.close();
}

void LeaderboardState::set_ui(sf::RenderWindow* target)
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


void LeaderboardState::poll_events(sf::Event &event)
{
    while (window -> pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                exit_status = true;
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        is_done = true;
                        break;
                }
        }
    }
}

void LeaderboardState::input()
{/*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        is_done = true;
    }*/
}


void LeaderboardState::update(const float &frame_time)
{
   // input();
}


void LeaderboardState::render_scores()
{
    size_t max_ten{};

    if (v_scores.size() < 10)
    {
        max_ten = v_scores.size();
    }
    else
    {
        max_ten = 10;
    }

    // crash if file doesnt have 10 rows

    for (int i{}; i < max_ten; i++)
    {
        std::string curr{std::to_string(v_scores.at(i))};

        score_text.setString(std::to_string(i+1) + '\t' + curr);
        score_text.setPosition(sf::Vector2f(
                window -> getSize().x / 2.f - 70.f,
                window -> getSize().y / (18.f) * ((float)i + 4.f)));

        window -> draw(score_text);
    }
}


void LeaderboardState::render()
{
    window -> draw(top_score_text);
    window -> draw(back_button);
    render_scores();
}


void LeaderboardState::quit_state()
{

}
