#ifndef GAME_H_SHOT_H
#define GAME_H_SHOT_H
#include "Object.h"
#include <vector>
//#include "Spider.h"


class Shot : public Object
{
public:
    Shot(std::string const& text,sf::Vector2f const& shot_dim);
    void move(float x, float y);


    float get_right();
    float get_left();
    float get_top();
    float get_bot();

/*<<<<<<< HEAD
  // bool check_coll(std::vector<sf::RectangleShape> const& all_spiders);
=======
   bool check_coll(std::vector<sf::Sprite> const& all_spiders);
>>>>>>> 1262816645ea7bbeb819e06c3e4794d52e86516d*/
   //bool check_coll_screen();

   bool check_is_dead();
   //void render(sf::RenderWindow* window);
    //void update(Shot & new_shot);


private:
   // bool mark_for_delete;

};


#endif //GAME_H_SHOT_H
