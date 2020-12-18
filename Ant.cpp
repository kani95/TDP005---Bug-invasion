#include "Ant.h"


Ant::Ant(std::string const& text,
         std::string const& shot_text,
         sf::Vector2f const& shot_dim,
         int const score, int const hp, int const att_timer)
:Enemy(score, hp), att_timer{att_timer}, shot_dim{shot_dim}, shot_text{shot_text}
{
    init_texture(text);
    clock.restart().asSeconds();
}


void Ant::move(float const x, float const y)
{
    shape.move(x, y);
}


// UPDATE HELPER FUNCTIONS
bool Ant::check_collison_player_shots(std::vector<Shot> & player_shots)
{
    /// Return true if player shot collides with ant
    /// Remove the player shot from the vector

    for(unsigned int i{0}; i < player_shots.size(); ++i)
    {
        Shot & shot{player_shots.at(i)};
        if (check_coll(shot.get_sprite()))
        {
            player_shots.erase(begin(player_shots) + i);
            return true;
        }
    }
    return false;
}


bool Ant::check_collison_ant_shots(std::vector<Shot> & ant_shots, Character * player)
{
    /// Return true if player collides with ant shots
    /// Player takes damage, shot is removed

    for(unsigned int i{0}; i < ant_shots.size(); ++i)
    {
        Shot & shot{ant_shots.at(i)};

        if (player -> check_coll(shot.get_sprite()))
        {
            ant_shots.erase(begin(ant_shots) + i);
            return true;
        }
        else if(shot.check_is_dead())
        {
            ant_shots.erase(begin(ant_shots) + i);
        }
    }
    return false;
}


bool Ant::can_shoot() const
{
    int value{(std::rand() % att_timer) + 1};
    if (value < 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Ant::update(float const,
        std::vector<Shot> & player_shots,
        std::vector<Shot> & ant_shots,
        Character* player)
{
    if(clock.getElapsedTime().asSeconds() >= 0.3)
    {
        shape.setColor(sf::Color::White);
    }

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
        Shot new_shot{shot_text, shot_dim};
        sf::Vector2f pos{get_left() + ((get_right() - get_left()) / 2 ) -
                         (new_shot.get_right() - new_shot.get_left()) / 2,
                         get_top()};
        new_shot.set_position(pos);
        ant_shots.push_back(new_shot);
    }
}
