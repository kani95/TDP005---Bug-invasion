#include "Enemy.h"

Enemy::Enemy()
    :Character(), score{}
{}


int Enemy::get_score() const
{
    return score;
}
