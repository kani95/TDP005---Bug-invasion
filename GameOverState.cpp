#include "GameOverState.h"


GameOverState::GameOverState(sf::RenderWindow *window, bool is_game_won,
                             unsigned long int total_score)
        :MenuState(window), game_over{}, is_game_won{is_game_won}, total_score{total_score}
{

    score = total_score;
    set_ui();
    set_choices();
    write_score_to_file("Leaderboard.txt");
}

void GameOverState::set_choices()
{
    // THIS IS TERRIBLE
    sf::Text text;
    choices.push_back(text);
    choices.push_back(text);
    choices.push_back(text);
    choices[0].setString("Retry");
    choices[1].setString("Leaderboard");
    choices[2].setString("Exit");
}

void GameOverState::set_ui()
{
    game_over.setFont(font);

    game_over.setCharacterSize(99);

    if(!is_game_won)
    {
        game_over.setString("GAME OVER!");
        game_over.setFillColor(sf::Color::Red);

        game_over.setPosition(sf::Vector2f(
                (window -> getSize().x / 2.f) - (game_over.getGlobalBounds().width / 2),
                10));
    }
    else
    {
        game_over.setString("YOU WIN!");
        game_over.setFillColor(sf::Color::Green);
        game_over.setPosition(sf::Vector2f(
                (window -> getSize().x / 2.f) - (game_over.getGlobalBounds().width / 2),
                10));
    }
}

void GameOverState::update(const float &frame_time)
{
    MenuState::update(frame_time);

}

void GameOverState::render()
{
    MenuState::render();
    window -> draw(game_over);

}


void GameOverState::write_score_to_file(std::string file) const
{
    std::ofstream leaderboard;
    leaderboard.open(file,  std::ios::out | std::ios::app);

    if (!leaderboard.is_open())
    {
        std::cerr << "FAILED TO OPEN LEADERBOARD.TXT IN GAMEOVERSTATE"
                  << std::endl;
    }
    leaderboard << std::to_string(score) << "\n";
    leaderboard.close();
}

