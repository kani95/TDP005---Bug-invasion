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
    void poll_events(sf::Event & event) override;


    void update(float const& frame_time) override;
    void render() override;
    void quit_state() override;


    void move_up();
    void move_down();

    int get_selected_choice() const;




private:
    int selected_choice;
    sf::Font font;
    sf::Text choices[MAX_NUMBER_OF_ITEMS];

    //const sf::RenderTarget(*window);
};


#endif //GAME_H_MENUSTATE_H
