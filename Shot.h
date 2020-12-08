#ifndef GAME_H_SHOT_H
#define GAME_H_SHOT_H
#include "Object.h"
#include <vector>
//#include "Spider.h"


class Shot : public Object
{
public:
    Shot();
    void move(float x, float y);

    float get_right();
    float get_left();
    float get_top();
    float get_bot();

   bool check_coll(std::vector<sf::RectangleShape> all_spiders);
   //bool check_coll_screen();

    //void render(sf::RenderTarget* & window);
    //void update(Shot & new_shot);

protected:

};


#endif //GAME_H_SHOT_H
