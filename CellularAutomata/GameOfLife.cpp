#include "stdafx.h"
#include "GameOfLife.h"

GameOfLife::GameOfLife(int width, int height) : 
    _width(width), 
    _height(height),
	_grid(width, GridRow(height))
{
	std::uniform_int_distribution<std::underlying_type<Cell>::type> dist(0, 1);
    for (auto &row : _grid)
    {
        for (auto &cell : row)
		{
			cell = static_cast<Cell>(dist(_random));
        }
    }
}

int GameOfLife::width() const
{
	return _width;
}

int GameOfLife::height() const
{
	return _height;
}


const GameOfLife::GridRow & GameOfLife::operator[](int x) const
{
	return _grid[x];
}

GameOfLife::GridRow &GameOfLife::operator[](int x)
{
	return _grid[x];
}
