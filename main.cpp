#include <SFML/Graphics.hpp>
#include "Game.cpp"


int main()
{
    //sf::RenderWindow window{sf::VideoMode(1024, 768), "Hello World!"};
    //sf::RenderWindow window(sf::VideoMode(width, height), "Game");
    //window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(120);
    Game game{};

    while (game.window_status())
    {
        game.update();

        game.render();

    }

    return 0;
}
