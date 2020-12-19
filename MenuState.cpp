#include "MenuState.h"


MenuState::MenuState(sf::RenderWindow *window)
        : State{window}, selected_choice{}, choices{}
{
    init_menu();
}


MenuState::~MenuState() = default;


void MenuState::init_menu()
{
    set_choices();

    for (size_t i{}; i < choices.size(); ++i)
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
                (window -> getSize().x / 2.f) -
                (choices[i].getGlobalBounds().width / 2),
                (window -> getSize().y / (choices.size() +
                                          1.f) * (i + 1.f))));
    }
}


void MenuState::set_choices()
{
    sf::Text text{};

    choices.push_back(text);
    choices.push_back(text);
    choices.push_back(text);

    choices[0].setString("New game");
    choices[1].setString("Leaderboard");
    choices[2].setString("Exit");
}


void MenuState::update(float const, sf::Event & event)
{
    poll_events(event);
}


void MenuState::poll_events(sf::Event & event)
{
    // when selecting leaderboard this will become true forever
    // means that when trying to exit leaderboard, leadearboard status will still be true
    leaderboard_status = false;

    while (window -> pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                exit_status = true;
                break;
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::Down:
                        move_down();
                        break;
                    case sf::Keyboard::Up:
                        move_up();
                        break;
                    case sf::Keyboard::Escape:
                        exit_status = true;
                        break;
                    case sf::Keyboard::Return:
                        if (get_selected_choice() == 0)
                        {
                            playstate_status = true;
                        }
                        else if (get_selected_choice() == 1)
                        {
                            leaderboard_status = true;
                        }
                        else if (get_selected_choice() == 2)
                        {
                            exit_status = true;
                        }
                        break;
                    default:
                        break;
                }
        }
    }
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
    if (selected_choice + 1 < (int)choices.size())
    {
        choices[selected_choice].setFillColor(sf::Color::Green);
        ++selected_choice;
        choices[selected_choice].setFillColor(sf::Color::Red);
    }
}


int MenuState::get_selected_choice() const
{
    return selected_choice;
}


void MenuState::render()
{
    for (size_t i{}; i < choices.size(); ++i)
    {
        window -> draw(choices[i]);
    }
}
