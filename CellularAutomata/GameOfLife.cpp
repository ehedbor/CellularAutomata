#include "stdafx.h"
#include "GameOfLife.h"
#include <iostream>

GameOfLife::GameOfLife()
{
	setupGrid();
}

GameOfLife::GameOfLife(int width, int height) : Automaton(width, height)
{
	setupGrid();
}

void GameOfLife::setupGrid()
{
	std::uniform_int_distribution<std::underlying_type<Cell>::type> dist(0, 1);
	for (auto &row : grid())
	{
		for (auto &cell : row)
		{
			cell = static_cast<Cell>(dist(_random));
		}
	}
}

void GameOfLife::update()
{ 
	auto newGrid = grid();
    for (auto x = 0; x < width(); x++)
    {
        for (auto y = 0; y < height(); y++)
        {
			newGrid[x][y] = nextCellState(x, y);
        }
    }
	grid() = std::move(newGrid);
}

Cell GameOfLife::nextCellState(int x, int y) const
{
    // Game of life rules:
	// 1. Any live cell with fewer than two live neighbors dies.
	// 2. Any live cell with two or three live neighbors lives.
	// 3. Any live cell with more than three live neighbors dies.
	// 4. Any dead cell with exactly three live neighbors becomes a live cell.

	auto neighbors = getCellNeighborCount(x, y);
    const auto& cell = grid()[x][y];
    if (cell == Cell::Alive)
    {
		if (neighbors == 2 || neighbors == 3) return Cell::Alive;
    }
    else if (cell == Cell::Dead)
	{
		if (neighbors == 3) return Cell::Alive;
	}
	return Cell::Dead;
}
