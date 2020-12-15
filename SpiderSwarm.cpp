#include "SpiderSwarm.h"
#include <iostream>

SpiderSwarm::SpiderSwarm(std::string const& text,
                         sf::Vector2f const& dim,
                         sf::Vector2f const& dir,
                         sf::Vector2f const& spawn_limit_x,
                         sf::Vector2f const& spawn_limit_y,
                         int const spawn_timer,
                         int const score,
                         int const hp)
        : all_spiders{}, timer{}, spawn_timer{spawn_timer}, score{score},
          hp{hp}, dir{dir}, dim{dim}, spawn_limit_y{spawn_limit_y}, spawn_limit_x{spawn_limit_x},
          text{text}
{}

void SpiderSwarm::update(std::vector<Shot> & player_shots,
                         std::vector<Shot> & ant_shots,
                         Character* player)
{
    if (timer >= spawn_timer)
    {
        // std::unique_ptr<Spider> spider(std::make_unique<Spider>(text, dim, dir, spawn_limit_x, spawn_limit_y, score, hp));
        Spider spider{text, dim, dir, spawn_limit_x, spawn_limit_y, score, hp};
        all_spiders.push_back(spider);
        timer = 0;
    }

    for (size_t i{}; i < all_spiders.size(); ++i)
    {
        Spider & spider{all_spiders.at(i)};

        spider.update(player_shots, ant_shots,player);

        if (!spider.status)
        {
            player -> increase_score(spider.get_score());
            all_spiders.erase(begin(all_spiders) + i);
        }
    }

    add_second();
}


void SpiderSwarm::add_second()
{
    ++timer;
}

/*std::vector<Spider>& SpiderSwarm::get_all_spiders()
{
    return all_spiders;
<<<<<<< HEAD
}*/

void SpiderSwarm::render(sf::RenderWindow* window)
{
    for (Spider & spider : all_spiders)
    {
        window -> draw(spider.shape);
    }
}


int SpiderSwarm::get_size_swarm()
{
    return all_spiders.size();
}

