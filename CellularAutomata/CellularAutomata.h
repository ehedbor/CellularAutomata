#pragma once
#include <vector>
#include <random>
#include "Cell.h"



class CellularAutomata
{
private:
	std::mt19937 _engine{ std::random_device{}() };
	std::uniform_int_distribution<int> _dist{0, 1};

	int _width;
	int _height;
	Grid _grid;

public:
    CellularAutomata(int width, int height);
    explicit CellularAutomata(const Grid &grid);
	virtual ~CellularAutomata() = default;

	virtual void update() = 0;
};

