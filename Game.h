#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H
#include "Object.h"
#include "Player.h"
#include "Leaf.h"
// run game engine class

class Game{
private:
    sf::RenderWindow* window{};
    sf::VideoMode video_mode;
    sf::Event event{};

    void init_vars();
    void init_window();

    //Player* player = new Player{};
     Player player;
     Leaf leaf;


public:
    Game();
    virtual ~Game();

    [[nodiscard]] bool window_status() const;
    void poll_events();
    void update();
    void render();
};


#endif //MAIN_CPP_GAME_H
