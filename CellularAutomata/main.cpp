#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameOfLife.h"

static constexpr int ScreenWidth = 400;
static constexpr int ScreenHeight = 400;
static constexpr float CellSize = 10;

void drawGrid(sf::RenderWindow &window, const GameOfLife &game);

int main()
{
	sf::String("Please");
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Cellular Automata");
	GameOfLife game(ScreenWidth / static_cast<int>(CellSize), ScreenHeight / static_cast<int>(CellSize));

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

        window.clear(sf::Color::Black);
		drawGrid(window, game);
        window.display();
    }

    return 0;
}

void drawGrid(sf::RenderWindow &window, const GameOfLife &game)
{
	for (auto x = 0; x < game.width(); x++)
	{
		for (auto y = 0; y < game.height(); y++)
		{
			sf::RectangleShape square(sf::Vector2f(CellSize, CellSize));
			square.setPosition(x * CellSize, y * CellSize);
			if (game[x][y] == Cell::Alive)
			{
				square.setFillColor(sf::Color::Blue);
			}
			else
			{
				square.setFillColor(sf::Color::White);
			}

			window.draw(square);
		}
	}
}