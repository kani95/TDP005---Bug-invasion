#ifndef GAME_H_SPIDER_H
#define GAME_H_SPIDER_H
#include "Enemy.h"
#include <vector>
#include "Shot.h"

class Spider : public Enemy {
public:
    Spider();
    int get_score() override;
    void move(float const, float const) override;
    void update() override;
    void set_start_pos();
    //void add_second();
    bool check_coll(Shot & shot);

    //std::vector<Spider>& get_all_spiders();
private:
    int score;
    //int timer;
   // std::vector<Spider> all_spiders;
};

#endif
