#include "SpiderSwarm.h"
#include <iostream>

SpiderSwarm::SpiderSwarm()
        : all_spiders{}, timer{}
{
    /*Spider spider{};
    all_spiders.push_back(spider);*/
}

void SpiderSwarm::update(const sf::RenderTarget* window,
                         std::vector<Shot> & player_shots,
                         Character* player)
{
    if (timer >= 700)
    {
        Spider spider{};
        spider.set_start_pos();
        all_spiders.push_back(spider);
        timer = 0;
    }


    for (size_t i{}; i < all_spiders.size(); ++i) {
        Spider &spider{all_spiders.at(i)};

        spider.update(window, player_shots, player);
        if (!spider.status)
        {
            all_spiders.erase(begin(all_spiders) + i);
        }
    }
    add_second();
}


void SpiderSwarm::add_second()
{
    ++timer;
}

std::vector<Spider>& SpiderSwarm::get_all_spiders()
{
    return all_spiders;
}