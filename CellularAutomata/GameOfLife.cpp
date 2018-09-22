#include "stdafx.h"
#include "GameOfLife.h"
#include <iostream>

std::string GameOfLife::Cell::toString(cell_t cell)
{
	switch (cell)
	{
	case Cell::Dead:
		return "Dead";
	case Cell::Alive:
		return "Alive";
	default:
		throw std::invalid_argument("Unexpected cell type");
	}
}

GameOfLife::GameOfLife()
{
	generateGrid();
}

GameOfLife::GameOfLife(int width, int height) : Automaton(width, height)
{
	generateGrid();
}

void GameOfLife::generateGrid()
{
	std::uniform_int_distribution<cell_t> dist(0, 1);
	for (auto &row : grid())
	{
		for (auto &cell : row)
		{
			cell = dist(_random);
		}
	}
}


cell_t GameOfLife::nextCellState(int x, int y) const
{
    // Game of life rules:
	// 1. Any live cell with fewer than two live neighbors dies.
	// 2. Any live cell with two or three live neighbors lives.
	// 3. Any live cell with more than three live neighbors dies.
	// 4. Any dead cell with exactly three live neighbors becomes a live cell.

	auto neighbors = getNeighborCountWithType(x, y, Cell::Alive);
    const auto &cell = (*this)[x][y];
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

void GameOfLife::printDebugInfoFor(int x, int y) const
{
	auto cell = (*this)[x][y];
	std::cout << "grid[" << x << "][" << y << "] ";
	std::cout << "type=" << Cell::toString(cell) << " ";
	std::cout << "neighbors=" << getNeighborCountWithType(x, y, Cell::Alive) << " ";
	std::cout << "next cell=" << Cell::toString(nextCellState(x, y)) << " ";
	std::cout << std::endl;
}

const sf::Color &GameOfLife::getColorForCell(int x, int y) const
{
	auto cell = (*this)[x][y];
	switch (cell)
	{
	case Cell::Dead:
		return sf::Color::White;
	case Cell::Alive:
		return sf::Color::Blue;
	default:
		throw std::invalid_argument("Unexpected cell type");
	}
}

void GameOfLife::cycleNext(int x, int y)
{
    // toggle the cell type.
	auto &cell = (*this)[x][y];
    switch (cell)
    {
	case Cell::Dead:
		cell = Cell::Alive;
		break;
	case Cell::Alive:
		cell = Cell::Dead;
		break;
	default:
		throw std::logic_error("Illegal cell type");
    }
}

void GameOfLife::cyclePrev(int x, int y)
{
	cycleNext(x, y);
}
