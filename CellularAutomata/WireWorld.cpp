#include "stdafx.h"
#include "WireWorld.h"
#include <iostream>

std::string WireWorld::Cell::toString(cell_t cell)
{
	switch (cell)
	{
	case Cell::Empty:
		return "Empty";
	case Cell::ElectronHead:
		return "Electron Head";
	case Cell::ElectronTail:
		return "Electron Tail";
	case Cell::Wire:
		return "Wire";
	default:
		throw std::invalid_argument("Unexpected cell type");
	}
}

WireWorld::WireWorld() = default;

WireWorld::WireWorld(int width, int height) : Automaton(width, height)
{
}

cell_t WireWorld::nextCellState(int x, int y) const
{
	auto cell = (*this)[x][y];
	switch (cell)
	{
	case Cell::Empty:
		return Cell::Empty;
	case Cell::ElectronHead:
		return Cell::ElectronTail;
	case Cell::ElectronTail:
		return Cell::Wire;
	case Cell::Wire: 
	{
		auto neighborCount = getNeighborCountWithType(x, y, Cell::ElectronHead);
		if (neighborCount >= 1 && neighborCount <= 2)
			return Cell::ElectronHead;
		return Cell::Wire;
	}
	default:
		throw std::invalid_argument("Unexpected cell type");
	}
}

void WireWorld::printDebugInfoFor(int x, int y) const
{
	auto cell = (*this)[x][y];
	std::cout << "grid[" << x << "][" << y << "] ";
	std::cout << "type=" << Cell::toString(cell) << " ";
	//std::cout << "neighbors=" << getCellNeighborCount(x, y) << " ";
	std::cout << "next cell=" << Cell::toString(nextCellState(x, y)) << " ";
	std::cout << std::endl;
}

const sf::Color &WireWorld::getColorForCell(int x, int y) const
{
	auto cell = (*this)[x][y];
	switch (cell)
	{
	case Cell::Empty:
		return sf::Color::White;
	case Cell::ElectronHead:
		return sf::Color::Yellow;
	case Cell::ElectronTail:
		return sf::Color::Red;
	case Cell::Wire:
		return sf::Color::Black;
	default:
		throw std::invalid_argument("Unexpected cell type");
	}
}

void WireWorld::cycleNext(int x, int y)
{
	auto &cell = (*this)[x][y];
	switch (cell)
	{
	case Cell::Empty:
		cell = Cell::Wire;
		break;
	case Cell::Wire:
		cell = Cell::ElectronHead;
        break;
	case Cell::ElectronHead:
		cell = Cell::ElectronTail;
		break;
	case Cell::ElectronTail:
		cell = Cell::Empty;
        break;
	default:
		throw std::logic_error("Invalid cell type");
	}
}

void WireWorld::cyclePrev(int x, int y)
{
	auto &cell = (*this)[x][y];
	switch (cell)
	{
	case Cell::Empty:
		cell = Cell::ElectronHead;
		break;
	case Cell::Wire:
		cell = Cell::Empty;
		break;
	case Cell::ElectronHead:
		cell = Cell::Wire;
	    break;
	case Cell::ElectronTail:
		cell = Cell::ElectronHead;
		break;
	default:
		throw std::logic_error("Invalid cell type");
	}
}