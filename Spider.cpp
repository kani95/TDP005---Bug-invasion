#include "Spider.h"
#include <iostream>
#include <random>

Spider::Spider(sf::Vector2f const& dim,
               sf::Vector2f const& dir,
               sf::Vector2f const& spawn_limit_x,
               sf::Vector2f const& spawn_limit_y,
               int const score,
               int const hp)
        : Enemy(score,hp), spw_lmt_x{spawn_limit_x}, spw_lmt_y{spawn_limit_y}
{
    shape.setFillColor(sf::Color::Blue);
   // shape.setPosition(300,200);
    direction.x = dir.x;
    direction.y = dir.y;
    shape.setSize(dim);

    set_start_pos(spawn_limit_x, spawn_limit_y);
}

/*
int Spider::get_score() const
{
 return score;
}*/

void Spider::set_start_pos(sf::Vector2f const& lmt_x,
                           sf::Vector2f const& lmt_y)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution dis_x(lmt_x.x, lmt_x.y);
    std::uniform_real_distribution dis_y(lmt_y.x, lmt_y.y - 10);

    float start_x {dis_x(gen)};
    float start_y {dis_y(gen)};

    shape.setPosition(start_x,start_y);

    //std::cout << start_x << ":x " << start_y << ":y ";
}


void Spider::check_coll_screen()
{
    bool right = (shape.getPosition().x + shape.getSize().x > (spw_lmt_x.y));
    bool left = (shape.getPosition().x < spw_lmt_x.x);
    bool down = (shape.getPosition().y + shape.getSize().y > (spw_lmt_y.y));
    bool up = (shape.getPosition().y < spw_lmt_y.x);

    if (right)
    {
        direction.x = -1 * direction.x;
        direction.y += 1;
        move(direction.x, direction.y);
        direction.y -= 1;
    }
    else if (left)
    {
        direction.x = -1 * direction.x;
        direction.y += 1;
        move(direction.x, direction.y);
        direction.y -= 1;
    }
    else if (down)
    {
        direction.x = -1 * direction.x;
        direction.y = -1 * direction.y;
       // move(direction.x, direction.y);
    }
    else if (up)
    {
        direction.x = -1 * direction.x;
        direction.y = -1 * direction.y;
        //move(direction.x, direction.y);
    }
}

void Spider::get_movement()
{

    /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(1,4);
    int start {(dis(gen))};
    //int start_y {(dis(gen))};
    if (start == 1) {
        speed.x = 1;
        speed.y = -1;
    }
    else if (start == 2)
    {
        speed.x = -1;
        speed.y = 1;
    }
    else if (start == 3)
    {
        speed.x = 0;
        speed.y = 1;
    }

    else if (start == 4)
    {
        speed.x = 1;
        speed.y = 0;
    }*/
}


void Spider::move( float const dirx, float const diry)
{
    shape.move(dirx,diry);
}


bool Spider::check_coll(sf::RectangleShape & enemy)
{
    if(shape.getPosition().x + shape.getSize().x > enemy.getPosition().x &&
       shape.getPosition().y < enemy.getPosition().y + enemy.getSize().y &&
       shape.getPosition().y + shape.getSize().y > enemy.getPosition().y &&
       shape.getPosition().x < enemy.getPosition().x + enemy.getSize().x)
    {
        //shape.setPosition(30,30);
        return true;
    }
    return false;
}


void Spider::check_coll_player_shots(std::vector<Shot> & player_shots, Character * player)
{
    for (size_t j{0}; j < player_shots.size(); ++j)
    {
        Shot & shot{player_shots.at(j)};

        if (check_coll(shot.shape))
        {
            // all_spiders.erase(begin(all_spiders) + i);
            player_shots.erase(begin(player_shots) + j);
            status = false;
            //delete this;
        }

    }
    if (check_coll(player -> shape))
    {
        player -> take_damage();
    }
}


void Spider::update(const sf::RenderTarget* window,
            std::vector<Shot> & player_shots,
            std::vector<Shot> & ant_shots,
            Character* player)
{
    check_coll_screen();
    //get_movement();
    move(direction.x, direction.y);
    check_coll_player_shots(player_shots, player);
}






