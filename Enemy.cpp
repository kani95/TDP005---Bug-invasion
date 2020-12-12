#include "Enemy.h"

Enemy::Enemy(int const score, int const hp)
    :Character(hp), score{score}
{}

int Enemy::get_score() const
{
    return score;
}