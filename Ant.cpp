#include "Ant.h"

Ant::Ant()
:Enemy(), score{}
{
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(220, 70);
    hp = 2;
}


int Ant::get_score() const
{
    return score;
}


void Ant::move(float const x, float const y)
{
    shape.move(x, y);
}


void Ant::render(sf::RenderTarget* target) const
{
    target -> draw(shape);
}


// UPDATE HELPER FUNCTIONS


bool Ant::check_coll(Shot & shot)
{
    if(shot.get_right() > shape.getPosition().x
       && shot.get_top() < shape.getPosition().y + shape.getSize().y
       && shot.get_bot() > shape.getPosition().y
       && shot.get_left() < shape.getPosition().x + shape.getSize().x)
    {
/*      std::cout << "i should be reset" << std::endl;
        shape.setPosition(0,0);*/
        return true;
    }
    return false;
}


bool Ant::check_collison_player_shots(std::vector<Shot> & player_shots)
{
    //for (auto & shot : player_shots)
    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        Shot & shot{player_shots.at(i)};
        if (check_coll(shot))
        {
            player_shots.erase(begin(player_shots) + i);
            return true;
        }
    }
    return false;
}


bool Ant::check_collison_ant_shots(std::vector<Shot> & ant_shots, Character * player)
{
    for(unsigned int i{0}; i < ant_shots.size(); ++i)
    {
        Shot & shot{ant_shots.at(i)};
        if (player -> check_enemy_coll(shot.shape) || shot.check_is_dead())
        {
            ant_shots.erase(begin(ant_shots) + i);
            return true;
        }
        else
        {
            shot.move(0.f, 0.3);
        }
    }
    return false;
}


bool Ant::can_shoot()
{
    int value{(std::rand() % 200) + 1};
    if (value == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Ant::update(const sf::RenderTarget* target,
                 std::vector<Shot> & player_shots,
                 std::vector<Shot> & ant_shots,
                 Character* player)
{
    if (check_collison_player_shots(player_shots))
    {
        take_damage();
    }

    if (check_collison_ant_shots(ant_shots, player))
    {
        player -> take_damage();
    }


    if (can_shoot())
    {
        Shot new_shot{};
        new_shot.shape.setPosition(shape.getPosition().x, shape.getPosition().y);
        ant_shots.push_back(new_shot);
    }
}



//Ant::~Ant() = default;
