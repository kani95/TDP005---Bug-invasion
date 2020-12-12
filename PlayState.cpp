#include "PlayState.h"


void PlayState::update(float const& frame_time)
{
    player -> update(leaf -> shape, player_shots);
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

    sf::Sprite sprite;

    sprite.setTexture(texture);

    sprite.setScale(300,300);
    sprite.setPosition(100,100);

    target -> draw(sprite);*/


    target -> draw(leaf -> shape);

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
}


void PlayState::quit_state() {

}

bool PlayState::get_is_done()
{
    return is_done;
}

PlayState::PlayState(sf::RenderWindow *window, std::string const& filename)
    : State(window)
    {
        read_lvl(filename);
    }


void PlayState::read_lvl(std::string const& filename)
{
// IN FILE TYPE:
// PLAYER:
// Object type|pos.x|pos.y|dir.x|dir.y|size.x|size.y|Movespd|hp|attack_tmr|
// |shot_dim.x|shot_dim.y|shot_dir.x|shot_dim.y|

// LEAF:
// Object type|pos.x|pos.y|size.x|size.y|

// ANTSWARM:
// Object type|pos.x|pos.y|size.x|size.y|dist.x|dist.y|dir.x|dir.y|shot_dir.x|
// |shot_dir.y|shot_dim.x|shot_dir.y|number_of_ants|number_of_rows|score|hp|attack_tmr|

// SPIDERSWARM:
// |dim.x|dim.y|dir.x|dir.y|spw_lim_x.x|spw_lim_x.y|spw_lim_y.x|spw_lim_y.y|
// |spw_timer|score|hp|

    std::ifstream infile{filename};
    std::string object{};

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
           infile >> pos.x >> pos.y >> direction.x >> direction.y >>
           dimensions.x >> dimensions.y >> movespeed >> hp >> att_timer
           >> shot_dim.x >> shot_dim.y >> shot_dir.x >> shot_dir.y;

           player = new Player{pos, direction, dimensions, movespeed,
                           hp, att_timer, shot_dim, shot_dir};
          // player = t_player;
           infile.ignore(1000, '\n');
       }
       if (object == "Leaf")
       {
           infile >> pos.x >> pos.y >> dimensions.x
           >> dimensions.y;

          // Leaf t_leaf{pos, dimensions};
           leaf =  new Leaf{pos,dimensions};
           infile.ignore(1000, '\n');
       }
       if (object == "AntSwarm")
       {
           infile >> pos.x >> pos.y >> dimensions.x >> dimensions.y >>
           distance.x >> distance.y >> direction.x >> direction.y >>
           shot_dir.x >> shot_dir.y >> shot_dim.x >> shot_dim.y >>
           number_of_ants >> number_of_rows >> score >> hp >> att_timer;

           AntSwarm t_antswarm{pos,dimensions, distance, direction,
                               shot_dir, shot_dim,
                               number_of_ants, number_of_rows, score, hp,
                               att_timer};
           ant_swarm = t_antswarm;
           infile.ignore(1000, '\n');
       }
       if (object == "SpiderSwarm")
       {
           sf::Vector2f spawn_limit_x{};
           sf::Vector2f spawn_limit_y{};

           infile >> dimensions.x >> dimensions.y >> direction.x >> direction.y
           >> spawn_limit_x.x >> spawn_limit_x.y >> spawn_limit_y.x
           >> spawn_limit_y.y >> spawn_timer >> score >> hp;

           SpiderSwarm t_spiderswarm{dimensions, direction, spawn_limit_x, spawn_limit_y,
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
}

bool PlayState::get_exit_status()
{
    return exit_status;
}


