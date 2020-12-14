#include "MenuState.h"
#include <iostream>


MenuState::MenuState(sf::RenderWindow *window)
           : State{window}, selected_choice{}, font{}, choices{}, event{}
{
    init_menu(window);
}

MenuState::~MenuState() = default;


void MenuState::init_menu(sf::RenderWindow* window)
{
    if (!font.loadFromFile("ARCADECLASSIC.TTF"))
    {
        std::cerr << "Failed to load font in MenuState" << std::endl;
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

        choices[i].setPosition(sf::Vector2f(
                window -> getSize().x / 2.f - 70.f,
                (window -> getSize().y / (MAX_NUMBER_OF_ITEMS + 1.f) * (i + 1.f))));
    }

    choices[0].setString("New game");
    choices[1].setString("Leaderboard");
    choices[2].setString("Exit");
}


void MenuState::input()
{
    // when selecting leaderboard this will become true forever
    // mean that when trying to exit leaderboard, leadearboard status will still be true
    leaderboard_status = false;
    // event keypressed
/*    while (window -> pollEvent(event))
    {
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Down)
            {
                move_down();
                std::cout << "das" << std::endl;
            }
        }
    }*/

    sf::Text text1;
    text1.setCharacterSize(50);
    text1.setString("sfasdfasfdsf");
    text1.setFillColor(sf::Color::White);
    text1.setPosition(sf::Vector2f(0, 0));
    window -> draw(text1);


/*    while (window -> pollEvent(event))
    {
        std::cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwsdfjas" << std::endl;
        switch (event.type)
        {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Down:
                        std::cout << "s1dfjas" << std::endl;
                        move_down();
                        break;
                    default:
                        break;
                }
            default:
                break;
        }

    }*/

/*    sf::Keyboard::Key

    switch (key) {
        case sf::Keyboard::Down:
            move_down();
            break;
        case sf::Keyboard::Up:
            move_up();
            break;
        case sf::Keyboard::Return:
            if (get_selected_choice() == 0)
            {
                is_done = true;
            }
            else if (get_selected_choice() == 1)
            {
                leaderboard_status = true;
            }
            else if (get_selected_choice() == 2)
            {
                exit_status = true;
            }
        default:
            break;
    }*/


    // https://www.sfml-dev.org/tutorials/2.5/window-events.php

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move_down();
        sf::sleep(sf::milliseconds(150));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move_up();
        sf::sleep(sf::milliseconds(150));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (get_selected_choice() == 0)
        {
            is_done = true;
        }
        else if (get_selected_choice() == 1)
        {
            leaderboard_status = true;
        }
        else if (get_selected_choice() == 2)
        {
            exit_status = true;
        }
    }
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

int MenuState::get_selected_choice() const
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
