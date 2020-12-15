#ifndef GAME_H_MENUSTATE_H
#define GAME_H_MENUSTATE_H
#include "State.h"
#include <iostream>

//#define MAX_NUMBER_OF_ITEMS 3

class MenuState : public State
{
public:

    explicit MenuState(sf::RenderWindow* window);
    ~MenuState() override;

    void update(float const& frame_time, sf::Event & event) override;
    void render() override;

protected:
    int selected_choice;
   // sf::Text choices[MAX_NUMBER_OF_ITEMS];

    std::vector<sf::Text> choices;

    void init_menu();
    // void input();
    void poll_events(sf::Event & event) override;
    virtual void set_choices();
    void move_up();
    void move_down();
    int get_selected_choice() const;

};


#endif //GAME_H_MENUSTATE_H
