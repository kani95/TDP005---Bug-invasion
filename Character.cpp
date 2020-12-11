#include "Character.h"


Character::Character()
    :Object(), hp{3}, status{true}, can_shoot{}, score{}, movespeed{1.f}
{}

void Character::take_damage()
{
    hp -= 1;
    shake_shape();
}

int Character::get_hp()
{
    return hp;
}

void Character::shake_shape()
{
    if (!status)
    {
        // shape.setOutlineColor(sf::Color::Transparent);
        shape.setScale(2, 2);
        status = true;
    }
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


bool Character::check_enemy_coll(sf::RectangleShape const& enemy)
{
    if (shape.getPosition().x + shape.getSize().x > enemy.getPosition().x &&
        shape.getPosition().y < enemy.getPosition().y + enemy.getSize().y &&
        shape.getPosition().y + shape.getSize().y > enemy.getPosition().y &&
        shape.getPosition().x < enemy.getPosition().x + enemy.getSize().x) {
        //shape.setPosition(30, 30);
        return true;
    }
    return false;
}