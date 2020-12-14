// #include <SFML/Graphics.hpp>
#include "Game.h"

// 1. vad gör vi fel med cmake?
// 2. rörelse med player hackigt varför
// 3. hur kan vi tänka att avgöra gränserna för bladet, hur kan vi mäta det


int main()
{
    //sf::RenderWindow window{sf::VideoMode(1024, 768), "Hello World!"};
    //sf::RenderWindow window(sf::VideoMode(width, height), "Game");
    //window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(120);
    Game game{};

    while (game.window_status())
    {
        game.update_tick();

        game.update();

        game.render();

    }

    return 0;
}
