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
        shape.setScale(100, 100);
    }
}