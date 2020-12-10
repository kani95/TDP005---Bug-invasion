#include "MenuState.h"
#include <iostream>


MenuState::MenuState(sf::RenderWindow *window)
           : State(window), selected_choice{}, font{}, choices{}, is_done{false},
             exit_status{false}
{
    init_menu(window);
}

MenuState::~MenuState() = default;


void MenuState::init_menu(sf::RenderWindow* window)
{
    if (!font.loadFromFile("ARCADECLASSIC.TTF"))
    {
        // Handle error
    }

    for (size_t i{}; i < MAX_NUMBER_OF_ITEMS; ++i)
    {
        if (i == 0)
        {
            choices[i].setFillColor(sf::Color::Red);
        }
        else
        {
            choices[i].setFillColor(sf::Color::Green);
        }

        choices[i].setFont(font);

        choices[i].setPosition(sf::Vector2f(window -> getSize().x / 2 - 70,
                                            (window -> getSize().y /
                                             (MAX_NUMBER_OF_ITEMS + 1) * (i + 1))));
    }

    choices[0].setString("New game");
    // choices[1].setString("Leaderboard");
    choices[1].setString("Exit");
}


void MenuState::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move_down();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move_up();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (get_selected_choice() == 0)
        {
            is_done = true;
        }
        else if (get_selected_choice() == 1)
        {
            exit_status = true;
        }
    }
}

bool MenuState::get_is_done()
{
    return is_done;
}

bool MenuState::get_exit_status()
{
    return exit_status;
}


void MenuState::update(float const& frame_time)
{
   input();
}


void MenuState::render(sf::RenderTarget*  target)
{
    for (size_t i{}; i < MAX_NUMBER_OF_ITEMS; ++i)
    {
        target -> draw(choices[i]);
    }
}

int MenuState::get_selected_choice()
{
    return selected_choice;
}


void MenuState::quit_state()
{

}

void MenuState::move_up()
{
    if (selected_choice - 1 >= 0)
    {
        choices[selected_choice].setFillColor(sf::Color::Green);
        --selected_choice;
        choices[selected_choice].setFillColor(sf::Color::Red);
    }
}

void MenuState::move_down()
{
    if (selected_choice + 1 < MAX_NUMBER_OF_ITEMS)
    {
        choices[selected_choice].setFillColor(sf::Color::Green);
        ++selected_choice;
        choices[selected_choice].setFillColor(sf::Color::Red);
    }
}