#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

// run game engine class

class Game {
private:
    sf::RenderWindow* window;
    sf::VideoMode video_mode;
    sf::Event event;

    void init_vars();
    void init_window();
public:
    Game();
    virtual ~Game();

    const bool window_status() const;
    void poll_events();
    void update();
    void render();
};


#endif //MAIN_CPP_GAME_H
