#include "Player.h"
#include <iostream>

/*Player::Player()
    :Character(), timer{70}, timer_dmg{}
{
    shape.setScale(10,40);
    shape.setPosition(position);
<<<<<<< HEAD
    shape.setPosition(300.f,450.f);
}*/


Player::Player(std::string const& text, std::string const& shot_text,
               sf::Vector2f const& pos, sf::Vector2f const& dir,
               sf::Vector2f const& dim, float const movespeed,
               int const hp, int const att_timer, sf::Vector2f const& shot_dim,
               sf::Vector2f const& shot_dir)
        :Character(text, pos, dir, dim, movespeed, hp), att_timer{att_timer}, timer{},
         timer_dmg{}, shot_dim{shot_dim}, shot_dir{shot_dir}, shot_text{shot_text}
{
   /* if(!texture.loadFromFile("player.png"))
    {
        std::cerr << "No load";
    }
    shape.setTexture(texture);*/
    //shape.setPosition(pos);
/*
    shape.setPosition(0.f,0.f);
    shape.setColor(sf::Color::White);*/

}


void Player::update_input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(-1.f, 0.f);
        // position.x += -2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(1.f, 0.f);
        // position.x += 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0.f, 1.f);
        // position.y += 2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0.f, -1.f);
        // position.y += -2;
    }
}


void Player::update(sf::Sprite const& box,
                    std::vector<Shot> & player_shots)
{
    if (clock.getElapsedTime().asSeconds() >= 0.3)
    {
        shape.setColor(sf::Color::White);
    }
    update_input();
    check_inside_leaf(box);

    if (timer < att_timer) {
        ++timer;
    }
    //TAKE DAMAGE TIMER
    if(timer_dmg < 35) {
        ++timer_dmg;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer >= att_timer)
    {
        add_shot(player_shots);
        timer = 0;
    }

 //   check_coll(ant_shots, all_spiders);
   // check_player_shots_coll(all_spiders,all_ants, player_shots);
    for (size_t i{0}; i < player_shots.size(); ++i)
    {
        player_shots.at(i).move(shot_dir.x, shot_dir.y);

        if (player_shots.at(i).check_is_dead())
        {
            //delete &player_shots.at(i);
          //  player_shots.at(i).remove_status = true;
         // shots_removed.emplace(shots_removed.begin() + i, std::move(&player_shots.at(i)));
          player_shots.erase(player_shots.begin() + i);
            //delete &player_shots.at(i);
            //!!!!!MEMORY LEAK!!!!!
            //player_shots.erase(begin(player_shots) + i);
        }
    }
  //  std::cout << player_shots.size();
 // std::cout << hp;

}


void Player::move(float const dirx, float const diry)
{
   // sf::Clock clock;
   // float delta_time = clock.restart().asSeconds();
    shape.setPosition(shape.getPosition().x + (dirx * movespeed),
                      shape.getPosition().y + (diry * movespeed));
    //shape.setPosition(shape.getPosition().x + (delta_time * movespeed), shape.getPosition().y + (movespeed*delta_time));
    //std::cout << shape.getPosition().x << " " << shape.getPosition().y << std::endl;

}


void Player::add_shot(std::vector<Shot> & player_shots)
{
   // std::unique_ptr<Shot> new_shot(std::make_unique<Shot>(shot_text,shot_dim));
    Shot new_shot{shot_text, shot_dim};
    //Shot* new_shot {new Shot{shot_text,shot_dim}};
    new_shot . shape.setPosition(get_dirx() + (shape.getGlobalBounds().width / 2), get_diry());
    player_shots.push_back(new_shot);
}


/*
std::vector<Shot> & Player::get_player_shots()
{
    std::cout << "PLayer size" << player_shots.size() << std::endl;
    return player_shots;
}
*/


void Player::check_inside_leaf(sf::Sprite const& box) {

    // LEFT
    if (shape.getGlobalBounds().left <= box.getGlobalBounds().left)
    {
        shape.setPosition(box.getGlobalBounds().left, shape.getGlobalBounds().top);
    }
    // RIGHT
    if ((shape.getPosition().x + shape.getGlobalBounds().width >= box.getGlobalBounds().width + box.getPosition().x))
    {
        shape.setPosition(box.getGlobalBounds().width + box.getPosition().x - shape.getGlobalBounds().width,
                          shape.getGlobalBounds().top);
    }
    // UP
    if (shape.getGlobalBounds().top <= box.getGlobalBounds().top)
    {
       shape.setPosition(shape.getGlobalBounds().left, box.getGlobalBounds().top);
    }
    // DOWN
    if (shape.getGlobalBounds().height + shape.getPosition().y >= box.getPosition().y + box.getGlobalBounds().height)
    {
        shape.setPosition(shape.getPosition().x, box.getGlobalBounds().height
        + box.getGlobalBounds().top - shape.getGlobalBounds().height);
    }
}

float Player::get_dirx()
{
    return shape.getPosition().x;
}


float Player::get_diry()
{
    return shape.getPosition().y;
}


void Player::draw(sf::RenderWindow & window)
{
    window.draw(shape);
}

// skicka in player referens till antswarm och spiderswarm.


void Player::take_damage()
{
    // HUR UTFÖRA EN OPERATION PER GAMELOOP???

    shape.setColor(sf::Color::Red);
    clock.restart().asSeconds();

    if (hp == 3 && timer_dmg >= 35)
    {
        hp = 2;
        timer_dmg = 0;

    }
    else if (hp == 2 && timer_dmg >= 35)
    {
        hp = 1;
        timer_dmg = 0;
    }
    else if (hp == 1 && timer_dmg >= 35)
    {
        hp = 0;
        timer_dmg = 0;
    }
}
//
//bool Player::check_enemy_coll(const sf::Sprite & enemy)
//{
//    return false;
//}
