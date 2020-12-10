#include "Spider.h"
#include <iostream>
#include <random>

Spider::Spider()
        : Enemy(), score{}
{
    shape.setFillColor(sf::Color::Blue);
   // shape.setPosition(300,200);
   speed.x = -0.5;
   speed.y = 0.1;
}


int Spider::get_score() const
{
 return score;
}

void Spider::move( float const dirx, float const diry)
{
    shape.move(dirx,diry);
}

void Spider::set_start_pos()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis_x(200,700);
    std::uniform_int_distribution dis_y(400,500);
    float start_x {static_cast<float>(dis_x(gen))};
    float start_y {static_cast<float>(dis_y(gen))};
    shape.setPosition(start_x,start_y);
   // std::cout << start_x << ":x " << start_y << ":y ";
}

void Spider::get_movement()
{

    /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(1,4);
    int start {(dis(gen))};
    //int start_y {(dis(gen))};
    if (start == 1) {
        speed.x = 1;
        speed.y = -1;
    }
    else if (start == 2)
    {
        speed.x = -1;
        speed.y = 1;
    }
    else if (start == 3)
    {
        speed.x = 0;
        speed.y = 1;
    }

    else if (start == 4)
    {
        speed.x = 1;
        speed.y = 0;
    }*/
}

void Spider::update(const sf::RenderTarget* window)
{
    get_movement();
    move(speed.x,speed.y);
    //std::cout << spider.shape.getPosition().x << "WWWWWWWWWWWWWWWWW2";

}

bool Spider::check_coll(sf::RectangleShape & enemy)
{
    if(shape.getPosition().x + shape.getSize().x > enemy.getPosition().x &&
       shape.getPosition().y < enemy.getPosition().y + enemy.getSize().y &&
       shape.getPosition().y + shape.getSize().y > enemy.getPosition().y &&
       shape.getPosition().x < enemy.getPosition().x + enemy.getSize().x)
    {
        //shape.setPosition(30,30);
        return true;
    }
    return false;
}

void Spider::check_coll_screen()
{
    bool right = (shape.getPosition().x + shape.getSize().x > (710));
    bool left = (shape.getPosition().x < 210);
    bool down = (shape.getPosition().y + shape.getSize().y > (600));
    bool up = (shape.getPosition().y < 300);

    if (right)
    {
        //shape.setPosition(shape.getPosition().x - (movespeed), shape.getPosition().y);
        speed.x = -1 * speed.x;
        speed.y += 1;
        move(speed.x, speed.y);
        speed.y -= 1;
      //  return true;
    }
    else if (left)
    {
        speed.x = -1 * speed.x;
        speed.y += 1;
        move(speed.x, speed.y);
        speed.y -= 1;
        // shape.setPosition(shape.getPosition().x + (movespeed), shape.getPosition().y);
     //   return true;
    }
    else if (down)
    {
        speed.x = -1 * speed.x;
        speed.y  = -1 * speed.y;
        move(speed.x, speed.y);
      //  speed.y -= 1;
     /*   speed.x = -1 * speed.x;
        speed.y = -1 * speed.y;
        move(speed.x, speed.y);*/
        // shape.setPosition(shape.getPosition().x, shape.getPosition().y - (movespeed));
    //    return true;
    }
    else if (up)
    {
        speed.x = -1 * speed.x;
        speed.y = -1 * speed.y;
        move(speed.x, speed.y);
      //  speed.y -= 1;
        /*speed.x = -1 * speed.x;
        speed.y = -1 * speed.y;
        move(speed.x, speed.y);*/
        // shape.setPosition(shape.getPosition().x, shape.getPosition().y + (movespeed));
      //  return true;
    }
   // return false;
}

