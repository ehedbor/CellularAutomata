#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "CellularAutomata.h"

static constexpr int ScreenWidth = 400;
static constexpr int ScreenHeight = 400;

int main()
{
	sf::String("Please");
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Cellular Automata");
	CellularAutomata automata;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}

