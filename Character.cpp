#include "Character.h"


Character::Character(int const hp)
        : Object(), hp{hp}
{
    clock.restart().asSeconds();
}

Character::Character(std::string const& text, sf::Vector2f const& pos,
                     sf::Vector2f const& dir,
                     sf::Vector2f const& dim,
                     float const movespeed,
                     int const hp)
        : Object(text, pos, dir, dim),
          score{0}, movespeed{movespeed}, hp{hp}
{}

void Character::take_damage()
{
    hp -= 1;
    shape.setColor(sf::Color::Red);
    clock.restart().asSeconds();
}


void Character::increase_score(long unsigned int plus_score)
{
    //if (game_)
    score += plus_score;
}


void Character::set_score(int new_score)
{
    score = new_score;
}


int Character::get_hp()
{

    return hp;
}


bool Character::is_dead()
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


/*bool Character::check_enemy_coll(sf::Sprite const& enemy)
{
    *//*if (shape.getPosition().x + shape.getScale().x > enemy.getPosition().x
        && shape.getPosition().y < enemy.getPosition().y + shape.getScale().y
        && shape.getPosition().y + shape.getScale().y > enemy.getPosition().y
        && shape.getPosition().x < enemy.getPosition().x + shape.getScale().x)*//*
    if(shape.getGlobalBounds().intersects(enemy.getGlobalBounds())){
        //shape.setPosition(30, 30);
        return true;
    }
    return false;
}*/

unsigned long int Character::get_score()
{
    return score;
}

