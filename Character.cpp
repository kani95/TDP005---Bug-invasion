#include "Character.h"


Character::Character(int const hp)
        : Object(), hp{hp}
{
    clock.restart().asSeconds();
}


Character::Character(std::string const& text, sf::Vector2f const& pos,
                     sf::Vector2f const& direction,
                     sf::Vector2f const& dimention,
                     float const movespeed,
                     int const hp)
        : Object(text, pos, direction, dimention),
          score{0}, hp{hp}, movespeed{movespeed}
{}


void Character::take_damage()
{
    hp -= 1;
    shape.setColor(sf::Color::Red);
    clock.restart().asSeconds();
}


void Character::increase_score(long unsigned int plus_score)
{
    score += plus_score;
}


void Character::set_score(int new_score)
{
    score = new_score;
}


int Character::get_hp() const
{
    return hp;
}


bool Character::is_dead() const
{
    if (hp <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


unsigned long int Character::get_score() const
{
    return score;
}

Character::Character() = default;
