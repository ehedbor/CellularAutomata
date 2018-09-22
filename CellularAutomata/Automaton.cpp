#include "stdafx.h"
#include "Automaton.h"
#include <iostream>

Automaton::Automaton() : Automaton(DefaultSize, DefaultSize)
{
}

Automaton::Automaton(int width, int height) :
    _width(width),
    _height(height),
    _grid(width, GridRow(height))
{
}

int Automaton::getNeighborCountWithType(int x, int y, cell_t cellType) const
{
	auto neighbors = 0;
	for (auto dx = -1; dx <= 1; dx++)
	{
		for (auto dy = -1; dy <= 1; dy++)
		{
			// skip the center cell; it cannot be a neighbor to itself
			if (dx == 0 && dy == 0) continue;

			auto nx = x + dx;
			auto ny = y + dy;
			// ensure neighbor exists
			if (nx >= 0 && nx < width() && ny >= 0 && ny < height())
			{
				// cell is a neighbor if it's type matches the given type
				auto isNeighbor = (*this)[nx][ny] == cellType;
				neighbors += isNeighbor ? 1 : 0;
			}
		}
	}

	return neighbors;
}

void Automaton::update()
{
    // make a copy of the old grid and modify it with new data
    auto newGrid = _grid;
    for (auto x = 0; x < width(); x++)
    {
        for (auto y = 0; y < height(); y++)
        {
            newGrid[x][y] = nextCellState(x, y);
        }
    }
    _grid = std::move(newGrid);
}


Automaton::Grid &Automaton::grid()
{
    return _grid;
}

const Automaton::Grid &Automaton::grid() const
{
    return _grid;
}

int Automaton::width() const
{
    return _width;
}

int Automaton::height() const
{
    return _height;
}

const Automaton::GridRow &Automaton::operator[](int x) const
{
    return _grid[x];
}

Automaton::GridRow &Automaton::operator[](int x)
{
    return _grid[x];
}

void Automaton::printDebugInfoFor(int x, int y) const
{
	std::cout << "grid[" << x << "][" << y << "] ";
	std::cout << std::endl;
}
