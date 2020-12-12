#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    update_total_score();
    std::cout << game_clock.getElapsedTime().asSeconds() << std::endl;
    std::cout << total_score << std::endl;
    player.update(leaf.shape, player_shots);
    // player_shots = player.get_player_shots();
    // send in a player reference to swarm, if it takes dmg call player take dmg

    spider_swarm.update(window, player_shots, ant_shots, &player);

    // !!! The update call should be made by each ant individually much more cleaner so
    ant_swarm.update(window, player_shots, ant_shots, &player);
}


void PlayState::render(sf::RenderTarget* target)
{
    //ant_shots = ant_swarm.get_ant_shots();
    all_spiders = spider_swarm.get_all_spiders();
    all_ants = ant_swarm.get_all_ants();


    target -> draw(leaf.shape);

    for (auto & shot_ : player_shots)
    {
        target -> draw(shot_.shape);
    }

    ant_swarm.render(target);

    for (auto & ant_shot : ant_shots)
    {
        target -> draw(ant_shot.shape);
    }


    target -> draw(player.shape);
    // target -> draw(ant.shape);
    for (auto & spi: all_spiders) {
        target -> draw(spi.shape);
    }

    target -> draw(score_text);
}


void PlayState::quit_state() {

}

bool PlayState::get_is_done()
{
    return is_done;
}

PlayState::PlayState(sf::RenderWindow *window)
    : State{window}, game_clock{}, total_score{}, font{}, score_text{}
    {

    if (font.loadFromFile("ARCADECLASSIC.TTF")) {
        std::cerr << "Failed to load font in PlayState.";
    };

    score_text.setFont(font);
    score_text.setCharacterSize(23);
    score_text.setFillColor(sf::Color::White);
    score_text.setString("SCORE");

}


PlayState::~PlayState() = default;


bool PlayState::get_exit_status()
{
    return exit_status;
}


void PlayState::update_total_score()
{
    int multiplier{1};
    if (game_clock.getElapsedTime().asSeconds() < 60)
    {
        multiplier = 3;
    }
    else if (game_clock.getElapsedTime().asSeconds() < 120)
    {
        multiplier = 2;
    }

    total_score += player.get_score() * multiplier;
    player.set_score(0);
    score_text.setString("SCORE      " + std::to_string(total_score));
}

