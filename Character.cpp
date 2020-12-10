#include "Character.h"


Character::Character()
    :Object(), hp{3}, status{true}, can_shoot{}, score{}, movespeed{1.f}
{}

void Character::take_damage()
{
    hp -= 1;
}