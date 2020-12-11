#include "Player.h"
#include <iostream>

Player::Player()
    :Character(), timer{70}, immunity{false}, timer_dmg{}
{
    shape.setScale(10,40);
    shape.setPosition(position);
    shape.setPosition(0.f,0.f);
    shape.setColor(sf::Color::White);
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


void Player::update(sf::Sprite const& box,
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
  //std::cout << hp;
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


void Player::check_inside_leaf(sf::Sprite const& box) {

    // LEFT
    if (shape.getGlobalBounds().left <= box.getGlobalBounds().left)
    {
        shape.setPosition(box.getGlobalBounds().left, shape.getGlobalBounds().top);
    }
    // RIGHT
    if ((shape.getPosition().x + shape.getScale().x >= (box.getPosition().x + box.getScale().x)))
    {
        shape.setPosition(box.getScale().x + box.getPosition().x
        - shape.getGlobalBounds().width, shape.getGlobalBounds().top);
    }
    // UP
    if (shape.getGlobalBounds().top <= box.getGlobalBounds().top)
    {
       shape.setPosition(shape.getGlobalBounds().left, box.getGlobalBounds().top);
    }
    // DOWN
    if (shape.getPosition().y + shape.getScale().y >= (box.getPosition().y + box.getScale().y))
    {
        shape.setPosition(shape.getPosition().x, box.getGlobalBounds().height
        + box.getGlobalBounds().top - shape.getGlobalBounds().height);
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

bool Player::check_enemy_coll(const sf::Sprite & enemy)
{
    return false;
}
