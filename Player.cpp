#include "Player.h"
#include <iostream>

Player::Player(std::string const& text, std::string const& shot_text,
               sf::Vector2f const& pos, sf::Vector2f const& dir,
               sf::Vector2f const& dim, float const movespeed,
               int const hp, int const att_timer, sf::Vector2f const& shot_dim,
               sf::Vector2f const& shot_dir)
        :Character(text, pos, dir, dim, movespeed, hp), att_timer{att_timer}, timer{},
         timer_dmg{}, shot_dim{shot_dim}, shot_dir{shot_dir}, shot_text{shot_text}
{}


void Player::update_input(float const frame_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-1.f, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0.f, 1.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0.f, -1);
    }
}


void Player::update(sf::Sprite const& box,
                    std::vector<Shot> & player_shots, float const frame_time)
{
    if (clock.getElapsedTime().asSeconds() >= 0.3)
    {
        shape.setColor(sf::Color::White);
    }

    update_input(frame_time);

    check_inside_leaf(box);

    if (timer < att_timer) {
        ++timer;
    }

    //TAKE DAMAGE TIMER
    if(timer_dmg < 35) {
        ++timer_dmg;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer >= att_timer)
    {
        add_shot(player_shots);
        timer = 0;
    }

    for (size_t i{0}; i < player_shots.size(); ++i)
    {
        player_shots.at(i).move(shot_dir.x, shot_dir.y);
        if (player_shots.at(i).check_is_dead())
        {
            player_shots.erase(player_shots.begin() + i);
        }
    }

  //  std::cout << player_shots.size();
  //  std::cout << "HP: " << hp << " ";
}


void Player::move(float const dirx, float const diry)
{
    shape.setPosition(shape.getPosition().x + (dirx * movespeed),
                      shape.getPosition().y + (diry * movespeed));
}


void Player::add_shot(std::vector<Shot> & player_shots)
{
    Shot new_shot{shot_text, shot_dim};
    new_shot.shape.setPosition(get_dirx() + (shape.getGlobalBounds().width / 2), get_diry());
    player_shots.push_back(new_shot);
}

void Player::check_inside_leaf(sf::Sprite const& box) {

    // LEFT
    if (shape.getGlobalBounds().left <= box.getGlobalBounds().left)
    {
        shape.setPosition(box.getGlobalBounds().left, shape.getGlobalBounds().top);
    }
    // RIGHT
    if ((shape.getPosition().x + shape.getGlobalBounds().width >= box.getGlobalBounds().width + box.getPosition().x))
    {
        shape.setPosition(box.getGlobalBounds().width + box.getPosition().x - shape.getGlobalBounds().width,
                          shape.getGlobalBounds().top);
    }
    // UP
    if (shape.getGlobalBounds().top <= box.getGlobalBounds().top)
    {
       shape.setPosition(shape.getGlobalBounds().left, box.getGlobalBounds().top);
    }
    // DOWN
    if (shape.getGlobalBounds().height + shape.getPosition().y >= box.getPosition().y + box.getGlobalBounds().height)
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

void Player::take_damage()
{
    shape.setColor(sf::Color::Red);
    clock.restart().asSeconds();

    if (hp == 3 && timer_dmg >= 35)
    {
        hp = 2;
        timer_dmg = 0;

    }
    else if (hp == 2 && timer_dmg >= 35)
    {
        hp = 1;
        timer_dmg = 0;
    }
    else if (hp == 1 && timer_dmg >= 35)
    {
        hp = 0;
        timer_dmg = 0;
    }
}

