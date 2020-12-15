#include "Ant.h"


Ant::Ant(std::string const& text,
         std::string const& shot_text,
         sf::Vector2f const& shot_dim,
         int const score, int const hp, int const att_timer)
:Enemy(score, hp), shot_dim{shot_dim}, att_timer{att_timer}, shot_text{shot_text}
{
    init_texture(text);
    clock.restart().asSeconds();
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

/*    if(shot.get_right() >= shape.getGlobalBounds().width + shape.getPosition().x
       && shot.get_top() <= shape.getGlobalBounds().top
       && shot.get_bot() >= shape.getPosition().y + shape.getGlobalBounds().height
       && shot.get_left() <= shape.getGlobalBounds().left)*/
    if(shot.shape.getGlobalBounds().intersects(shape.getGlobalBounds()))
    {
        return true;
    }
    return false;
}


bool Ant::check_collison_player_shots(std::vector<Shot> & player_shots)
{
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

        if (player -> check_enemy_coll(shot.shape))
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


bool Ant::can_shoot()
{
    int value{(std::rand() % att_timer) + 1};
    if (value == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Ant::update(std::vector<Shot> & player_shots,
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
        new_shot.shape.setPosition(shape.getPosition().x + (shape.getGlobalBounds().width / 2), shape.getPosition().y);
        ant_shots.push_back(new_shot);
    }

}

