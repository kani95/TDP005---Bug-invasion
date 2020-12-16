// #include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game game{};

    while (game.window_status())
    {

        game.update();

        game.render();

    }

    return 0;
}
