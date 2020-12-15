#include "Spider.h"
#include <iostream>
#include <random>


Spider::Spider(std::string const& text,
               sf::Vector2f const& dim,
               sf::Vector2f const& dir,
               sf::Vector2f const& spawn_limit_x,
               sf::Vector2f const& spawn_limit_y,
               int const score,
               int const hp)
        : Enemy(score,hp), spw_lmt_x{spawn_limit_x}, spw_lmt_y{spawn_limit_y}
{
    init_texture(text);

    direction.x = dir.x;
    direction.y = dir.y;
    shape.setScale(dim);

    set_start_pos(spawn_limit_x, spawn_limit_y);
}



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
}


void Spider::check_coll_screen()
{
    bool right = (shape.getPosition().x + shape.getScale().x > (spw_lmt_x.y));
    bool left = (shape.getPosition().x < spw_lmt_x.x);
    bool down = (shape.getPosition().y + shape.getScale().y > (spw_lmt_y.y));
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
    }
    else if (up)
    {
        direction.x = -1 * direction.x;
        direction.y = -1 * direction.y;
    }
}


void Spider::move( float const dirx, float const diry)
{
    shape.move(dirx,diry);
}


void Spider::check_coll_player_shots(std::vector<Shot> & player_shots, Character * player)
{
    for (size_t i{0}; i < player_shots.size(); ++i)
    {
        Shot & shot{player_shots.at(i)};

        if (check_coll(shot.get_sprite()))
        {
            player_shots.erase(begin(player_shots) + i);
            take_damage();
        }

    }
    if (check_coll(player ->get_sprite()))
    {
        player -> take_damage();
    }
}


void Spider::update(std::vector<Shot> & player_shots,
                    std::vector<Shot> & ant_shots,
                    Character* player)
{
    check_coll_screen();
    move(direction.x, direction.y);
    check_coll_player_shots(player_shots, player);
}






