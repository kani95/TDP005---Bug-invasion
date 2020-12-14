#include "PlayState.h"


void PlayState::update(float const& frame_time)
{

    player -> update(leaf -> shape, player_shots);
    update_total_score();

    // player_shots = player.get_player_shots();
    // send in a player reference to swarm, if it takes dmg call player take dmg

   spider_swarm.update(window, player_shots, ant_shots, player);

    // !!! The update call should be made by each ant individually much more cleaner so
    ant_swarm.update(window, player_shots, ant_shots, player);
}


void PlayState::render(sf::RenderTarget* target)
{
    //ant_shots = ant_swarm.get_ant_shots();
    all_spiders = spider_swarm.get_all_spiders();
    all_ants = ant_swarm.get_all_ants();

   /* sf::Texture texture;
    texture.loadFromFile("leaf.jpg");

<<<<<<< HEAD
    sf::Sprite sprite;

    sprite.setTexture(texture);

    sprite.setScale(300,300);
    sprite.setPosition(100,100);

    target -> draw(sprite);*/


    target -> draw(leaf -> shape);
/*=======

    target -> draw(leaf.shape);
>>>>>>> 1262816645ea7bbeb819e06c3e4794d52e86516d*/

    for (auto & shot_ : player_shots)
    {
        target -> draw(shot_.shape);
    }

    ant_swarm.render(target);

    for (auto & ant_shot : ant_shots)
    {
        target -> draw(ant_shot.shape);
    }


    target -> draw(player -> shape);
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


/*
PlayState::PlayState(sf::RenderWindow *window, std::string const& filename)
    : State(window)
    {
        read_lvl(filename);
    }
*/

PlayState::PlayState(sf::RenderWindow *window, std::string const& filename)
        : State{window}, game_clock{}, total_score{}, font{}, score_text{}
{

    if (!font.loadFromFile("ARCADECLASSIC.TTF"))
    {
        std::cerr << "Failed to load font in PlayState.";
    };

    score_text.setFont(font);
    score_text.setCharacterSize(23);
    score_text.setFillColor(sf::Color::White);
    score_text.setString("SCORE");

    read_lvl(filename);
}

//PlayState::~PlayState() = default;

void PlayState::read_lvl(std::string const& filename)
{
// IN FILE TYPE:
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
    std::string object{};
    std::string texture_file;
    std::string shot_texture;

    int border_limit_left{};
    int border_limit_right{};
    int spawn_timer{};
    int att_timer{};
    int score{};
    int hp{};
    unsigned short int number_of_ants{};
    int number_of_rows{};
    sf::Vector2f distance{};

    sf::Vector2f pos{};
    sf::Vector2f direction{};
    sf::Vector2f dimensions{};
    sf::Vector2f shot_dir{};
    sf::Vector2f shot_dim{};
    float movespeed{};


   /* bool status{};
    bool can_shot{};*/

    while(infile >> object)
    {
       if (object == "Player")
       {
           infile >> texture_file >> shot_texture >> pos.x >> pos.y >> direction.x >> direction.y >>
           dimensions.x >> dimensions.y >> movespeed >> hp >> att_timer
           >> shot_dim.x >> shot_dim.y >> shot_dir.x >> shot_dir.y;

           player = new Player{texture_file, shot_texture, pos, direction, dimensions, movespeed,
                           hp, att_timer, shot_dim, shot_dir};
          // player = t_player;
           infile.ignore(1000, '\n');
       }
       if (object == "Leaf")
       {
           infile >> texture_file >> pos.x >> pos.y >> dimensions.x
           >> dimensions.y;

          // Leaf t_leaf{pos, dimensions};
           leaf = new Leaf{texture_file,pos,dimensions};
           infile.ignore(1000, '\n');
       }
       if (object == "AntSwarm")
       {
           infile >> texture_file >> shot_texture >> pos.x >> pos.y >> dimensions.x >> dimensions.y >>
           distance.x >> distance.y >> direction.x >> direction.y >>
           shot_dir.x >> shot_dir.y >> shot_dim.x >> shot_dim.y >> border_limit_left >>
           border_limit_right  >> number_of_ants >> number_of_rows >> score >> hp >> att_timer;

           AntSwarm t_antswarm{texture_file, shot_texture, pos, dimensions, distance, direction,
                               shot_dir, shot_dim, border_limit_left, border_limit_right,
                               number_of_ants, number_of_rows, score, hp,
                               att_timer};
           ant_swarm = t_antswarm;
           infile.ignore(1000, '\n');
       }
       if (object == "SpiderSwarm")
       {
           sf::Vector2f spawn_limit_x{};
           sf::Vector2f spawn_limit_y{};

           infile >> texture_file >> dimensions.x >> dimensions.y >> direction.x >> direction.y
           >> spawn_limit_x.x >> spawn_limit_x.y >> spawn_limit_y.x
           >> spawn_limit_y.y >> spawn_timer >> score >> hp;

           SpiderSwarm t_spiderswarm{texture_file, dimensions, direction, spawn_limit_x, spawn_limit_y,
                                     spawn_timer, score, hp};

           spider_swarm = t_spiderswarm;
       }
    }

    infile.close();
}

PlayState::~PlayState()
{
   delete player;
   delete leaf;
  /*  for (Shot & shot : player_shots)
    {
        if(shot.remove_status)
        {
            delete &shot;
        }
    }*/
}

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

    total_score += player->get_score() * multiplier;
    player->set_score(0);
    score_text.setString("SCORE      "
                         +  std::to_string(total_score)
                         + "\nLIVES      "
                         + std::to_string(player->get_hp()));
}

bool PlayState::get_leaderboard_status() {
    return leader_board;
}

