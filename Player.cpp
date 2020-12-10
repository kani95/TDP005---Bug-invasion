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
                    std::vector<Shot> const& ant_shots,
                    std::vector<Shot> & player_shots)
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
        add_shot(player_shots);
        timer = 0;
    }

 //   check_coll(ant_shots, all_spiders);
   // check_player_shots_coll(all_spiders,all_ants, player_shots);
    for (size_t i{0}; i < player_shots.size(); ++i)
    {
        player_shots.at(i).move(0.f, -6.5f);

        if (player_shots.at(i).check_is_dead())
        {
            player_shots.erase(begin(player_shots) + i);
        }
    }
  //  std::cout << player_shots.size();
  std::cout << hp;
}

/*bool Player::check_ant_shots_coll(Shot & shot)
{
    //std::cout << "HP, before: " << hp;
    if (check_enemy_coll(shot.shape)) {
        take_damage();
        return true;
    }
    //std::cout << " HP, after: " << hp;
    return false;

}*/

/*bool Player::check_spider_coll(Spider & spider)
{
    std::cout << "HP, before: " << hp;
    if (check_enemy_coll(spider.shape))
    {
        take_damage();
        return true;
    }
    std::cout << " HP, after: " << hp;
    return false;
}*/


void Player::move(float const dirx, float const diry)
{
   // sf::Clock clock;
   // float delta_time = clock.restart().asSeconds();
    shape.setPosition(shape.getPosition().x + (dirx * movespeed),
                      shape.getPosition().y + (diry * movespeed));
    //shape.setPosition(shape.getPosition().x + (delta_time * movespeed), shape.getPosition().y + (movespeed*delta_time));
    //std::cout << shape.getPosition().x << " " << shape.getPosition().y << std::endl;

}


void Player::add_shot(std::vector<Shot> & player_shots)
{
    Shot new_shot{};
    new_shot.shape.setPosition(get_dirx(),get_diry());
    player_shots.push_back(new_shot);
}


/*
std::vector<Shot> & Player::get_player_shots()
{
    std::cout << "PLayer size" << player_shots.size() << std::endl;
    return player_shots;
}
*/


void Player::check_inside_leaf(sf::RectangleShape const& box) {

    // LEFT
    if (shape.getGlobalBounds().left <= box.getGlobalBounds().left)
    {
        shape.setPosition(box.getGlobalBounds().left, shape.getGlobalBounds().top);
    }
    // RIGHT
    if ((shape.getPosition().x + shape.getSize().x >= (box.getPosition().x + box.getSize().x)))
    {
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
        shape.setPosition(shape.getPosition().x, box.getGlobalBounds().height + box.getGlobalBounds().top - shape.getGlobalBounds().height);
    }
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

// skicka in player referens till antswarm och spiderswarm.


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
