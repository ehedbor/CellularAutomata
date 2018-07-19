#include "stdafx.h"
#include "Cell.h"

Cell::Cell(const sf::Color &color) : _color(color)
{
}

const sf::Color &Cell::color() const
{
	return _color;
}

const Cell Cell::Alive = Cell{ sf::Color::Blue };