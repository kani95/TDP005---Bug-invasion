#include "LeaderboardState.h"


LeaderboardState::LeaderboardState(sf::RenderWindow * window)
        :State(window), v_scores{}, score_text{}, back_button{},
         top_score_text{}
{
    score_text.setCharacterSize(21);
    set_font();

    load_scores("Leaderboard.txt");
    sort_scores();

    // if there is more than 50 scores saved overwrite file and
    // remove the lowest scores.
    if (v_scores.size() > 50)
    {
        overwrite_file("Leaderboard.txt");
    }

    set_ui(window);
}


void LeaderboardState::set_font()
{
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
    /// After there is more than 50 scores saved in file then
    /// remove the ones that are the lowest.
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
    top_score_text.setCharacterSize(65);
    top_score_text.setString("TOP SCORES");
    top_score_text.setPosition(sf::Vector2f(target -> getSize().x / 2.f -
                                            top_score_text.getCharacterSize() * 2.5,10));

    back_button.setCharacterSize(40);
    back_button.setString("ESC   TO   BACK");
    back_button.setPosition(0,0);
}


void LeaderboardState::update(float const, sf::Event & event)
{
    poll_events(event);
}


void LeaderboardState::poll_events(sf::Event &event)
{
    while (window -> pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                exit_status = true;
                break;
            default:
                break;

            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        is_done = true;
                        break;
                    default:
                        break;
                }
        }
    }
}


void LeaderboardState::render()
{
    window -> draw(top_score_text);
    window -> draw(back_button);
    render_scores();
}


void LeaderboardState::render_scores()
{
    ///  print only ten or less scores
    size_t max_ten{};

    if (v_scores.size() < 10)
    {
        max_ten = v_scores.size();
    }
    else
    {
        max_ten = 10;
    }

    for (size_t i{}; i < max_ten; i++)
    {
        std::string curr{std::to_string(v_scores.at(i))};

        score_text.setCharacterSize(35);
        score_text.setString(std::to_string(i+1) + "\t\t" + curr);
        score_text.setPosition(sf::Vector2f(
                window -> getSize().x / 2.f - 70.f,
                window -> getSize().y / (18.f) * ((float)i + 4.f)));

        window -> draw(score_text);
    }
}

