#ifndef GAME_H_MENUSTATE_H
#define GAME_H_MENUSTATE_H
#include "State.h"

#define MAX_NUMBER_OF_ITEMS 3

class MenuState : public State
{
public:
   // MenuState(float const height, float const weight);

    explicit MenuState(sf::RenderWindow* window);
    ~MenuState() override;

    void init_menu(sf::RenderWindow* window);
    void input();


    void update(float const& frame_time) override;
    void render(sf::RenderTarget* target) override;
    void quit_state() override;


    void move_up();
    void move_down();

    bool get_is_done() override;
    bool get_exit_status() override;
    bool get_leaderboard_status() override;

    int get_selected_choice() const;




private:
    int selected_choice;
    bool is_done;
    bool exit_status;
    sf::Font font;
    sf::Text choices[MAX_NUMBER_OF_ITEMS];
    bool leaderboard_status;
    sf::Event event;
    //const sf::RenderTarget(*window);
};


#endif //GAME_H_MENUSTATE_H
