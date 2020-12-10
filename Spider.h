#ifndef GAME_H_SPIDER_H
#define GAME_H_SPIDER_H
#include "Enemy.h"
#include <vector>
#include "Shot.h"

class Spider : public Enemy {
public:
    Spider();
    int get_score() const override;
    void move(float const, float const) override;
    void update(const sf::RenderTarget* window, Shot & shot) override;
    void set_start_pos();
    //void add_second();
    bool check_coll(sf::RectangleShape & enemy);
    void get_movement();


   void check_coll_screen();

    //std::vector<Spider>& get_all_spiders();
private:
    int score;
    //int timer;
   // std::vector<Spider> all_spiders;
};

#endif
