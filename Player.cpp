#include "Player.h"


Player::Player(std::string const& text,
               std::string const& shot_text,
               sf::Vector2f const& pos,
               sf::Vector2f const& direction,
               sf::Vector2f const& dimension,
               float const movespeed,
               int const hp,
               int const att_timer,
               float const timer_dmg,
               sf::Vector2f const& shot_dim,
               sf::Vector2f const& shot_dir)
        :Character(text, pos, direction, dimension, movespeed, hp),
         att_timer{att_timer}, timer{}, timer_dmg{timer_dmg},
         shot_dim{shot_dim}, shot_dir{shot_dir}, shot_text{shot_text}
{}


void Player::update_position(float frame_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        frame_time = frame_time / 2;
    }
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        move(-120.f * frame_time, 0.f * frame_time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        move(120.f * frame_time, 0.f * frame_time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        move(0.f * frame_time, 120.f * frame_time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        move(0.f * frame_time, -120.f * frame_time);
    }
}


void Player::keep_inside_leaf(Leaf* box)
{
    /*!
     * If player is outside the box
     * move player inside the box
     */

    // LEFT
    if (get_left() <= box -> get_left())
    {
        shape.setPosition(box -> get_left(), get_top());
    }
    // RIGHT
    if ((get_right() >= box -> get_right()))
    {
        shape.setPosition(box -> get_right() -
                          (get_right() - get_left()),get_top());
    }
    // UP
    if (get_top() <= box -> get_top())
    {
        shape.setPosition(get_left(), box -> get_top());
    }
    // DOWN
    if (get_bot() >= box -> get_bot())
    {
        shape.setPosition(get_left(), box -> get_bot() -
                                      (get_bot() - get_top()));
    }
}


void Player::shooting(int const att_timer, float const frame_time,
                      std::vector<Shot> & player_shots)
{
    /*!
     * Method that take care of shooting for player
     * Updates the shot timer
     * Checks if player can shot
     * Add shot if player can shoot and space bar was pressed
     * Move all player shots and remove the shots out of range
     */

    if (timer < att_timer)
    {
        ++timer;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer >= att_timer)
    {
        add_shot(player_shots);
        timer = 0;
    }

    for (size_t i{0}; i < player_shots.size(); ++i)
    {
        player_shots.at(i).move(shot_dir.x * frame_time,
                                shot_dir.y * frame_time);
        if (player_shots.at(i).check_is_dead())
        {
            player_shots.erase(player_shots.begin() + i);
        }
    }
}


void Player::update(Leaf* box,
                    std::vector<Shot> & player_shots, float const frame_time)
{
    if (clock.getElapsedTime().asSeconds() >= 0.3)
    {
        shape.setColor(sf::Color::White);
    }

    update_position(frame_time);

    keep_inside_leaf(box);

    shooting(att_timer, frame_time, player_shots);
}


void Player::move(float const dirx, float const diry)
{
    shape.setPosition(shape.getPosition().x + (dirx * movespeed),
                      shape.getPosition().y + (diry * movespeed));
}


void Player::add_shot(std::vector<Shot> & player_shots)
{
    Shot new_shot{shot_text, shot_dim};
    sf::Vector2f pos{get_left() + ((get_right() - get_left()) / 2 ) -
                             (new_shot.get_right() - new_shot.get_left()) / 2,
                             get_top()};
    new_shot.set_position(pos);
    player_shots.push_back(new_shot);
}


void Player::take_damage()
{
    /*!
     * Flicker player red and reset the timer for
     * when player can turn back to it's original color
     *
     * Check if it has been longer then timer_dmg time
     * since player took damage.
     * Otherwise when player will collide with an enemy
     * player will drop to 0 hp instantly.
     */

    shape.setColor(sf::Color::Red);
    clock.restart().asSeconds();

    if ( last_hit.getElapsedTime().asSeconds() > timer_dmg ) {
        --hp;
        last_hit.restart().asSeconds();
    }
}
