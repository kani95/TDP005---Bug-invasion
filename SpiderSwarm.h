#ifndef GAME_H_SPIDERSWARM_H
#define GAME_H_SPIDERSWARM_H
#include "Spider.h"

class SpiderSwarm{
public:
    SpiderSwarm(std::string const& text,
                sf::Vector2f const& dim,
                sf::Vector2f const& dir,
                sf::Vector2f const& spawn_limit_x,
                sf::Vector2f const& spawn_limit_y,
                int const spawn_timer,
                int const score,
                int const hp);

    void update(float const frame_time,
                std::vector<Shot> & player_shots,
                std::vector<Shot> & ant_shots,
                Character* player);

    void render(sf::RenderWindow* window);
    int get_size_swarm() const;


private:
    int timer;
    int spawn_timer;
    int score;
    int hp;

    std::string text;
    sf::Vector2f dir;
    sf::Vector2f dim;
    sf::Vector2f spawn_limit_y;
    sf::Vector2f spawn_limit_x;


    std::vector<Spider> all_spiders;

    void add_second();
    void spawn_spider(Character* player);
};
#endif //GAME_H_SPIDERSWARM_H
