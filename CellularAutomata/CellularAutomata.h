#pragma once
#include <vector>
#include "Cell.h"
#include <functional>
#include <random>

using GridRow = std::vector<Cell>;
using Grid = std::vector<GridRow>;

class CellularAutomata
{
private:
	std::mt19937 _engine{ std::random_device()() };
	std::uniform_int_distribution<int> _dist{0, 1};

	int _width{};
	int _height{};
	Grid _grid{};

public:
	CellularAutomata(int width, int height);
    explicit CellularAutomata(const Grid &grid);

	void forEachCell(const std::function<void(int, int)> &callback) const;
};

