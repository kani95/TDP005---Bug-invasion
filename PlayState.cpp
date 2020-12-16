#include "PlayState.h"

PlayState::PlayState(sf::RenderWindow *window, std::string const& filename)
        : State{window}, game_clock{}, score_text{}
{
    score_text.setFont(font);
    score_text.setCharacterSize(23);
    score_text.setFillColor(sf::Color::White);
    score_text.setString("SCORE");

    read_lvl(filename);
}

void PlayState::read_lvl(std::string const& filename)
{
// IN FILE TYPE IN ORDER:

// PLAYER:
// Object type|texture_file|shot_texture|pos.x|pos.y|dir.x|dir.y|size.x|size.y|Movespd|hp|attack_tmr|
// |shot_dim.x|shot_dim.y|shot_dir.x|shot_dir.y|

// LEAF:
// Object type|texture_file|pos.x|pos.y|size.x|size.y|

// ANTSWARM:
// Object type|texture_file|shot_texture|pos.x|pos.y|size.x|size.y|dist.x|dist.y|dir.x|dir.y|shot_dir.x|
// |shot_dir.y|shot_dim.x|shot_dir.y|border_limit_left|border_limit_right|number_of_ants|number_of_rows|score|hp|attack_tmr|

// SPIDERSWARM:
// Object type|texture_file|dim.x|dim.y|dir.x|dir.y|spw_lim_x.x|spw_lim_x.y|spw_lim_y.x|spw_lim_y.y|
// |spw_timer|score|hp|

    std::ifstream infile{filename};
    if (!infile)
    {
        std::cerr << "The map-file could not be located" << std::endl;
    }

    std::string texture_file{};
    std::string shot_texture{};
    std::string object{};

    float movespeed{};

    unsigned short int number_of_ants{};
    int border_limit_left{};
    int border_limit_right{};
    int number_of_rows{};
    int spawn_timer{};
    int att_timer{};
    int score{};
    int hp{};

    sf::Vector2f dimensions{};
    sf::Vector2f direction{};
    sf::Vector2f distance{};
    sf::Vector2f shot_dir{};
    sf::Vector2f shot_dim{};
    sf::Vector2f pos{};

    while(infile >> object)
    {
        if (object == "Player")
        {
            infile >> texture_file >> shot_texture >> pos.x >> pos.y >> direction.x >>
                   direction.y >> dimensions.x >> dimensions.y >> movespeed >> hp >> att_timer
                   >> shot_dim.x >> shot_dim.y >> shot_dir.x >> shot_dir.y;

            player = new Player{texture_file, shot_texture, pos, direction,
                                dimensions, movespeed, hp, att_timer, shot_dim, shot_dir};

            infile.ignore(1000, '\n');
        }
        if (object == "Leaf")
        {
            infile >> texture_file >> pos.x >> pos.y >> dimensions.x
                   >> dimensions.y;

            leaf = new Leaf{texture_file,pos,dimensions};

            infile.ignore(1000, '\n');
        }
        if (object == "AntSwarm")
        {
            infile >> texture_file >> shot_texture >> pos.x >> pos.y >> dimensions.x >> dimensions.y >>
                   distance.x >> distance.y >> direction.x >> direction.y >>
                   shot_dir.x >> shot_dir.y >> shot_dim.x >> shot_dim.y >> border_limit_left >>
                   border_limit_right  >> number_of_ants >> number_of_rows >> score >> hp >> att_timer;

           /* AntSwarm t_antswarm{texture_file, shot_texture, pos, dimensions, distance, direction,
                                shot_dir, shot_dim, border_limit_left, border_limit_right,
                                number_of_ants, number_of_rows, score, hp,
                                att_timer};*/
           ant_swarm = new AntSwarm{texture_file, shot_texture, pos, dimensions, distance, direction,
                                    shot_dir, shot_dim, border_limit_left, border_limit_right,
                                    number_of_ants, number_of_rows, score, hp,
                                    att_timer};

           // ant_swarm = t_antswarm;
            infile.ignore(1000, '\n');
        }
        if (object == "SpiderSwarm")
        {
            sf::Vector2f spawn_limit_x{};
            sf::Vector2f spawn_limit_y{};

            infile >> texture_file >> dimensions.x >> dimensions.y >> direction.x >> direction.y
                   >> spawn_limit_x.x >> spawn_limit_x.y >> spawn_limit_y.x
                   >> spawn_limit_y.y >> spawn_timer >> score >> hp;

           /* SpiderSwarm t_spiderswarm{texture_file, dimensions, direction, spawn_limit_x, spawn_limit_y,
                                      spawn_timer, score, hp};*/

           // spider_swarm = t_spiderswarm;
           spider_swarm = new SpiderSwarm{texture_file, dimensions, direction, spawn_limit_x, spawn_limit_y,
                                          spawn_timer, score, hp};
        }
    }

    infile.close();
}


PlayState::~PlayState()
{
    delete player;
    delete leaf;
    delete spider_swarm;
    delete ant_swarm;

}


void PlayState::poll_events(sf::Event & event) {

    State::poll_events(event);

    /* while (window -> pollEvent(event)) {
         switch (event.type) {
             case sf::Event::Closed:
                 exit_status = true;
                 break;
             default:
                 break;
             case sf::Event::KeyReleased:
                 switch (event.key.code) {
                     case sf::Keyboard::Escape:
                         exit_status = true;
                         break;
                     default:
                         break;
                 }
         }
     }*/

}


void PlayState::update(float const& frame_time, sf::Event & event)
{
    poll_events(event);
    check_game_status();
    player -> update(leaf, player_shots, frame_time);
    update_total_score();

    // send in a player reference to swarm, if it takes dmg call player take dmg

    spider_swarm -> update(player_shots, ant_shots, player);

    // !!! The update call should be made by each ant individually much more cleaner so
    ant_swarm -> update(player_shots, ant_shots, player);
}


void PlayState::render()
{
    //ant_shots = ant_swarm.get_ant_shots();
    //all_spiders = spider_swarm.get_all_spiders();
    //all_ants = ant_swarm.get_all_ants();

    leaf->render(window);

    for (Shot & shot : player_shots)
    {
        shot.render(window);
    }

    ant_swarm -> render(window);

    for (Shot & ant_shot : ant_shots)
    {
        ant_shot.render(window);
    }

    player->render(window);

    spider_swarm -> render(window);

    window -> draw(score_text);

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

    score += player -> get_score() * multiplier;
    player->set_score(0);
    score_text.setString("SCORE      "
                         +  std::to_string(score)
                         + "\nLIVES      "
                         + std::to_string(player -> get_hp()));
}




bool PlayState::check_game_status()
{
    if (ant_swarm -> get_size_swarm() < 1 && spider_swarm -> get_size_swarm() < 1)
    {
        // WIN
        gameover_status = true;
        is_game_won = true;
        return true;
    }
    else if (player -> get_hp() < 1)
    {
        // LOSE
        gameover_status = true;
    }
    return false;
}

