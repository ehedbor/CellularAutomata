#include "stdafx.h"
#include "CellularAutomata.h"

CellularAutomata::CellularAutomata(int width, int height)
	: _width(width), _height(height)
{
    for (auto x = 0; x < width; x++)
    {
		_grid.push_back(GridRow{});
        for (auto y = 0; y < height; y++)
        {
			auto cell = static_cast<Cell>(_dist(_engine));
			_grid[x].push_back(cell);
        }
    }
}

CellularAutomata::CellularAutomata(const Grid &grid)
    : _width(grid.size()), _height(grid[0].size()), _grid(grid)
{
}