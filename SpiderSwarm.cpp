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
        : timer{}, spawn_timer{spawn_timer}, score{score},
          hp{hp}, text{text},  dir{dir}, dim{dim}, spawn_limit_y{spawn_limit_y},
          spawn_limit_x{spawn_limit_x}, all_spiders{}
{}


void SpiderSwarm::spawn_spider(Character* player)
{
    if (timer >= spawn_timer)
    {
        // Max 6 spiders at the same time
        if (all_spiders.size() < 7)
        {
            Spider spider{text, dim, dir, spawn_limit_x,
                          spawn_limit_y, score, hp};

            //Spider cant collide with player when spawning
            if (!spider.check_coll(player -> get_sprite()))
            {
                all_spiders.push_back(spider);
            }
        }

        timer = 0;
    }
}


void SpiderSwarm::update(float const frame_time,
                         std::vector<Shot> & player_shots,
                         std::vector<Shot> & ant_shots,
                         Character* player)
{
    spawn_spider(player);

    for (size_t i{}; i < all_spiders.size(); ++i)
    {
        Spider & spider{all_spiders.at(i)};

        spider.update(frame_time, player_shots, ant_shots, player);

        if (spider.is_dead())
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


void SpiderSwarm::render(sf::RenderWindow* window)
{
    for (Spider & spider : all_spiders)
    {
        spider.render(window);
    }
}


int SpiderSwarm::get_size_swarm() const
{
    return all_spiders.size();
}
