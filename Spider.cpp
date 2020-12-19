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
        : Enemy(score,hp)
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

    std::uniform_real_distribution dis_x(lmt_x.x, lmt_x.y) ;
    std::uniform_real_distribution dis_y(lmt_y.x, lmt_y.y);

    float start_x {dis_x(gen)};
    float start_y {dis_y(gen)};

    shape.setPosition(start_x,start_y);
}


void Spider::move(float const dirx, float const diry)
{
    shape.move(dirx,diry);
}


void Spider::keep_inside_screen(float const frame_time)
{

    if (get_left() < 0)
    {
        direction.x *= -1;
        move( direction.x * frame_time, direction.y * frame_time);
    }
        // RIGHT
    else if ((get_right() > 1920))
    {
        direction.x *= -1;
        direction.y *= -1;
        move( direction.x * frame_time,  direction.y * frame_time);
    }
        // UP
    else if (get_top() < 540)
    {

        direction.y *= -1;
        move(  direction.x * frame_time,  direction.y * frame_time);
    }
        // DOWN
    else if (get_bot() > 1080)
    {
        direction.y *= -1;
        move( direction.x * frame_time,  direction.y * frame_time);
    }
}


void Spider::collision_player(std::vector<Shot> & player_shots,
                                     Character * player)
{
    /*!
     * Check collision with players_shots if true take damage
     * Check if spider collides with player entity if true
     * Player takes damage.
     */

    for (size_t i{0}; i < player_shots.size(); ++i)
    {
        Shot & shot{player_shots.at(i)};

        if (check_coll(shot.get_sprite()))
        {
            player_shots.erase(begin(player_shots) + i);
            take_damage();
        }

    }
    if (check_coll(player -> get_sprite()))
    {
        player -> take_damage();
    }
}


void Spider::update(float const frame_time,
        std::vector<Shot> & player_shots,
        std::vector<Shot> &,
        Character* player)
{
    move(direction.x * frame_time, direction.y * frame_time);

    keep_inside_screen(frame_time);

    collision_player(player_shots, player);
}
