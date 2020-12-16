#include "GameOverState.h"


GameOverState::GameOverState(sf::RenderWindow *window, bool is_game_won,
                             size_t total_score)
        : MenuState(window), game_over{}, is_game_won{is_game_won}
{
    score = total_score;

    set_ui();

    set_choices();

    write_score_to_file("Leaderboard.txt");
}


void GameOverState::set_ui()
{
    game_over.setFont(font);
    game_over.setCharacterSize(99);

    if(!is_game_won)
    {
        game_over.setString("GAME OVER!");
        game_over.setFillColor(sf::Color::Red);

        game_over.setPosition(sf::Vector2f((window -> getSize().x / 2.f) -
                (game_over.getGlobalBounds().width / 2),10));
    }
    else
    {
        game_over.setString("YOU WIN!");
        game_over.setFillColor(sf::Color::Green);
        game_over.setPosition(sf::Vector2f(
                (window -> getSize().x / 2.f) -
                (game_over.getGlobalBounds().width / 2),10));
    }
}


void GameOverState::set_choices()
{
    // Inherent the rest options from MenuState
    choices[0].setString("Retry");
}


void GameOverState::write_score_to_file(std::string const& file) const
{
    std::ofstream leaderboard;
    leaderboard.open(file,  std::ios::out | std::ios::app);

    if (!leaderboard.is_open())
    {
        std::cerr << "FAILED TO OPEN LEADERBOARD.TXT IN GAMEOVERSTATE"
        << std::endl;
    }

    leaderboard << std::to_string(score) << '\n';

    leaderboard.close();
}


void GameOverState::update(float const frame_time, sf::Event & event)
{
    MenuState::update(frame_time, event);

}


void GameOverState::render()
{
    MenuState::render();
    window -> draw(game_over);
}