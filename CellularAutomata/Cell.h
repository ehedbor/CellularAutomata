#pragma once
#include <SFML/Graphics/Color.hpp>

enum class Cell
{
    Dead = 0,
    Alive = 1
};

inline const sf::Color &getCellColor(Cell cell)
{
    if (cell == Cell::Dead) 
		return sf::Color::White;
    if (cell == Cell::Alive)
		return sf::Color::Blue;
    
	throw std::invalid_argument("Unexpected cell type");
}