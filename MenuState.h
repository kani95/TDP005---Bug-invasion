#ifndef GAME_H_MENUSTATE_H
#define GAME_H_MENUSTATE_H
#include "State.h"

//#define MAX_NUMBER_OF_ITEMS 3

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

    virtual void set_choices();

    void move_up();
    void move_down();

    int get_selected_choice() const;

protected:
    //static int max_number_of_items;
    int selected_choice;
    sf::Font font;
    //sf::Text choices[max_number_of_items];
    std::vector<sf::Text> choices;
    sf::Event event;
    //const sf::RenderTarget(*window);
};


#endif //GAME_H_MENUSTATE_H
