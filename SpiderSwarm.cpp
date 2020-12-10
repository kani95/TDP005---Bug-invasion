#include "SpiderSwarm.h"
#include <iostream>

SpiderSwarm::SpiderSwarm()
        : all_spiders{}, timer{}
{
    /*Spider spider{};
    all_spiders.push_back(spider);*/
}

void SpiderSwarm::update(const sf::RenderTarget* window,
                         std::vector<Shot> & player_shots, Player & player)
{
    if (timer >= 700)
    {
        Spider spider{};
        spider.set_start_pos();
        all_spiders.push_back(spider);
        timer = 0;
    }

    for (size_t j{0}; j < player_shots.size(); ++j) {
        Shot &shot{player_shots.at(j)};

        for (size_t i{}; i < all_spiders.size(); ++i) {
            Spider &spider{all_spiders.at(i)};

            if (spider.check_coll(shot.shape)) {
                all_spiders.erase(begin(all_spiders) + i);
                player_shots.erase(begin(player_shots) + j);
            }
        }
    }

    for (size_t i{}; i < all_spiders.size(); ++i) {
        Spider &spider{all_spiders.at(i)};

        if (spider.check_coll(player.shape)) {
            player.take_damage();
        }

        spider.check_coll_screen();
        spider.update(window);
    }
  /*  if (player_shots.size() == 0)
    {
        for (Spider & spider : all_spiders)
        {
            //player.check_spider_coll(spider);
            if (spider.check_coll(player.shape))
            {
                player.take_damage();
            }
            spider.check_coll_screen();
            spider.update(window);
        }
    }
    else {
        //for (Shot shot : player_shots)
        for (size_t j{0}; j < player_shots.size(); ++j) {
            Shot &shot{player_shots.at(j)};
            //std::cout << player_shots.size();
            for (size_t i{}; i < all_spiders.size(); ++i) {
                Spider &spider{all_spiders.at(i)};

                if (spider.check_coll(shot.shape)) {
                    all_spiders.erase(begin(all_spiders) + i);
                    player_shots.erase(begin(player_shots) + j);
                } else if (spider.check_coll(player.shape)) {
                    player.take_damage();
                } else {
                    spider.check_coll_screen();
                    spider.update(window);
                }
            }
        }
    }*/
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