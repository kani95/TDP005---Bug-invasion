#include "SpiderSwarm.h"

SpiderSwarm::SpiderSwarm()
        : all_spiders{}, timer{}
{
    /*Spider spider{};
    all_spiders.push_back(spider);*/
}

void SpiderSwarm::update(std::vector<Shot> & player_shots)
{
    if (timer >= 700)
    {
        Spider spider{};
        spider.set_start_pos();
        all_spiders.push_back(spider);
        //std::cout << all_spiders.size() << "SIZE";
        // std::cout << all_spiders.at(0).shape.getPosition().x << "WWWWWWWWWWWWWWWWW1";
        timer = 0;
    }

    if (player_shots.size() == 0)
    {
        for (Spider & spider : all_spiders)
        {
            spider.check_coll_screen();
            spider.update();
        }
    }

    for (Shot shot : player_shots) {
        for (size_t i{}; i < all_spiders.size(); ++i) {

            if (!all_spiders.at(i).check_coll(shot)) {
                all_spiders.at(i).check_coll_screen();
                all_spiders.at(i).update();
            } else {
                all_spiders.erase(begin(all_spiders) + i);
            }
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