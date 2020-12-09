#include "Player.h"
#include <iostream>

Player::Player()
    :Character(), timer{70}, immunity{false}
{
    shape.setPosition(position);
    shape.setPosition(300.f,450.f);
}


void Player::update_input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-1.f, 0.f);
        // position.x += -2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(1.f, 0.f);
        // position.x += 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0.f, 1.f);
        // position.y += 2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0.f, -1.f);
        // position.y += -2;
    }
}


void Player::update(sf::RectangleShape const& box,
                    std::vector<sf::RectangleShape> const& all_spiders,
                    std::vector<sf::RectangleShape> const& all_ants,
                    std::vector<Shot> const& ant_shots)
{

    update_input();
    check_inside_leaf(box);

    if (timer < 70) {
        ++timer;
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

    check_coll(ant_shots, all_spiders);
    check_player_shots_coll(all_spiders,all_ants);

  /*  for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
       // std::cout << "SHOT_1  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;

       if (!player_shots.at(i).check_coll(all_spiders) && !player_shots.at(i).check_coll(all_ants))
           player_shots.at(i).move(0.f, -6.5f);
       else
            player_shots.erase(begin(player_shots) + i);
        //std::cout << player_shots.size();
       // std::cout << "SHOT_2  " << player_shots.at(i).shape.getPosition().x << " " << player_shots.at(i).shape.getPosition().y << std::endl;
    }*/
}

void Player::check_coll(std::vector<Shot> const& ant_shots,
                              std::vector<sf::RectangleShape> const& all_spiders)
{
    for (auto & spider : all_spiders)
    {
        std::cout << "HP, before: " << hp;
        if (check_enemy_coll(spider))
        {
           take_damage();
        }
    }

    for (auto const& shot : ant_shots)
    {
        if(check_enemy_coll(shot.shape))
        {
            take_damage();
        }
    }
    std::cout << " HP, after: " << hp;
}

void Player::move(float const dirx, float const diry)
{
   // sf::Clock clock;
   // float delta_time = clock.restart().asSeconds();
    shape.setPosition(shape.getPosition().x + (dirx * movespeed),
                      shape.getPosition().y + (diry * movespeed));
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


void Player::check_inside_leaf(sf::RectangleShape const& box) {

    //bool right = (shape.getPosition().x + shape.getSize().x > (box.getPosition().x + box.getSize().x));
    //bool left = (shape.getPosition().x < box.getPosition().x);
    //bool down = (shape.getPosition().y + shape.getSize().y > (box.getPosition().y + box.getSize().y));
    //bool up = (shape.getPosition().y < box.getPosition().y);

    // RIGHT
/*    if (shape.getPosition().x + shape.getSize().x >= (box.getPosition().x + box.getSize().x))
    {
        shape.setPosition(shape.getPosition().x - (movespeed), shape.getPosition().y);
        //shape.setPosition(box.getGlobalBounds().width - (shape.getSize().x), shape.getPosition().y);
    }
    // LEFT
    if (shape.getPosition().x <= box.getPosition().x)
    {
        shape.setPosition(shape.getPosition().x + (movespeed), shape.getPosition().y);
    }
    // DOWN
    if (shape.getPosition().y + shape.getSize().y >= (box.getPosition().y + box.getSize().y))
    {
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - (movespeed));
    }
    // UP
    if (shape.getPosition().y <= box.getPosition().y)
    {
        shape.setPosition(shape.getPosition().x, shape.getPosition().y + (movespeed));
    }*/



    //std::cout << shape.getPosition().x << " " << shape.getPosition().y << std::endl;
    //std::cout << box.getGlobalBounds().height << " " << box.getGlobalBounds().top << std::endl;
    // LEFT
    if (shape.getGlobalBounds().left <= box.getGlobalBounds().left)
    {
        shape.setPosition(box.getGlobalBounds().left, shape.getGlobalBounds().top);
    }
    // RIGHT
    //if (shape.getGlobalBounds().left + shape.getGlobalBounds().width >= box.getGlobalBounds().left + box.getGlobalBounds().width)
    if ((shape.getPosition().x + shape.getSize().x >= (box.getPosition().x + box.getSize().x)))
    {
        //shape.setPosition(box.getGlobalBounds().width - shape.getGlobalBounds().width, shape.getPosition().y);
        shape.setPosition(box.getSize().x + box.getPosition().x - shape.getGlobalBounds().width, shape.getGlobalBounds().top);
    }
    // UP
    if (shape.getGlobalBounds().top <= box.getGlobalBounds().top)
    {
       shape.setPosition(shape.getGlobalBounds().left, box.getGlobalBounds().top);
    }
    // DOWN
    if (shape.getPosition().y + shape.getSize().y >= (box.getPosition().y + box.getSize().y))
    {
     //   std::cout << "hereeeeeeeeeeeeee " << std::endl;
        shape.setPosition(shape.getPosition().x, box.getGlobalBounds().height + box.getGlobalBounds().top - shape.getGlobalBounds().height);
    }

    // DOWN
    //if(shape.getGlobalBounds().top + shape.getGlobalBounds().height >= box.getSize().y)
/*    if (shape.getPosition().y + shape.getSize().y >= (box.getPosition().y + box.getSize().y))
    {
        shape.setPosition(shape.getGlobalBounds().left, box.getGlobalBounds().height - shape.getGlobalBounds().height);
    }*/

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

void Player::check_player_shots_coll(std::vector<sf::RectangleShape> const& all_spiders,
                             std::vector<sf::RectangleShape> const& all_ants)
{
    for (unsigned int i{0}; i < player_shots.size(); ++i)
    {
        if (!player_shots.at(i).check_coll(all_spiders) &&
            !player_shots.at(i).check_coll(all_ants))
        {
            player_shots.at(i).move(0.f, -6.5f);
        }
        else
        {
            player_shots.erase(begin(player_shots) + i);
        }
        std::cout << player_shots.size();
    }
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

void Player::take_damage()
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
