#include "Player.h"
#include <iostream>



Player::Player()
    :Character(), timer{70}, immunity{false}
{
    shape.setPosition(position);
    shape.setPosition(300.f,450.f);
}

void Player::update(sf::RectangleShape const& box,
                    std::vector<sf::RectangleShape> const& all_spiders,
                    std::vector<sf::RectangleShape> const& all_ants)
{
    if (check_inside_leaf(box)) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            move(0.f, -1.f);
            // position.y += -2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-1.f, 0.f);
            // position.x += -2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            move(0.f, 1.f);
            // position.y += 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(1.f, 0.f);
            // position.x += 2;
        }
    }
    if (timer < 70) {
        ++timer;
        ++timer_dmg;
    }
    //TAKE DAMAGE TIMER
    if(timer_dmg < 30) {
        ++ timer_dmg;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer >= 70)
    {
        add_shot();
        timer = 0;
    }

    check_coll(all_ants, all_spiders);

    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
       // std::cout << "SHOT_1  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;

       if (!player_shots.at(i).check_coll(all_spiders) && !player_shots.at(i).check_coll(all_ants))
           player_shots.at(i).move(0.f, -6.5f);
       else
            player_shots.erase(begin(player_shots) + i);
        //std::cout << player_shots.size();
       // std::cout << "SHOT_2  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
    }
}

void Player::check_coll(std::vector<sf::RectangleShape> const& all_ants,
                              std::vector<sf::RectangleShape> const& all_spiders)
{
    for (auto & spider : all_spiders)
    {
       // std::cout << "HP, before: " << hp;
        if (check_enemy_coll(spider))
        {
            // HUR UTFÖRA EN OPERATION PER GAMELOOP???
             if (hp == 3 && timer_dmg >= 30)
             {
                 hp = 2;
                 timer_dmg = 0;

             }
             else if (hp == 2 && timer_dmg >= 30)
             {
                 hp = 1;
                 timer_dmg = 0;
             }
             else if (hp == 1 && timer_dmg >= 30)
             {
                 hp = 0;
                 timer_dmg = 0;
             }
        }

    }

  //  std::cout << " HP, after: " << hp;
}



void Player::move(float const dirx, float const diry)
{
   // sf::Clock clock;
   // float delta_time = clock.restart().asSeconds();
    shape.setPosition(shape.getPosition().x + (dirx * movespeed), shape.getPosition().y + (diry * movespeed));
    //shape.setPosition(shape.getPosition().x + (delta_time * movespeed), shape.getPosition().y + (movespeed*delta_time));
    //std::cout << shape.getPosition().x << " " << shape.getPosition().y << std::endl;

}


void Player::add_shot()
{
    Shot new_shot{};
    new_shot.shape.setPosition(get_dirx(),get_diry());
    player_shots.push_back(new_shot);
}

std::vector<Shot> & Player::get_player_shots()
{
    return player_shots;
}


bool Player::check_inside_leaf(sf::RectangleShape const& box) {


    bool right = (shape.getPosition().x + shape.getSize().x > (box.getPosition().x + box.getSize().x));
    bool left = (shape.getPosition().x < box.getPosition().x);
    bool down = (shape.getPosition().y + shape.getSize().y > (box.getPosition().y + box.getSize().y));
    bool up = (shape.getPosition().y < box.getPosition().y);

    if (right)
    {
        shape.setPosition(shape.getPosition().x - (movespeed), shape.getPosition().y);
        return false;
    }
    else if (left)
    {
        shape.setPosition(shape.getPosition().x + (movespeed), shape.getPosition().y);
        return false;
    }
    else if (down)
    {
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - (movespeed));
        return false;
    }
    else if (up)
    {
        shape.setPosition(shape.getPosition().x, shape.getPosition().y + (movespeed));
        return false;
    }

    return true;
}

float Player::get_dirx()
{
    return shape.getPosition().x;
}

float Player::get_diry()
{
    return shape.getPosition().y;
}

void Player::draw(sf::RenderWindow & window)
{
    window.draw(shape);
}

bool Player::check_enemy_coll(sf::RectangleShape const& enemy) {
    if (shape.getPosition().x + shape.getSize().x > enemy.getPosition().x &&
        shape.getPosition().y < enemy.getPosition().y + enemy.getSize().y &&
        shape.getPosition().y + shape.getSize().y > enemy.getPosition().y &&
        shape.getPosition().x < enemy.getPosition().x + enemy.getSize().x) {
        //shape.setPosition(30, 30);
        return true;
    }
    return false;
}
/*
int Player::take_damage()
{
     return hp - 1 ;
}*/
