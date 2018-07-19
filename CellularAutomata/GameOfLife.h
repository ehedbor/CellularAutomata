#pragma once
#include <vector>
#include <random>
#include "Cell.h"

class GameOfLife
{
public:
	using GridRow = std::vector<Cell>;
	using Grid = std::vector<GridRow>;

private:
	std::mt19937 _random{ std::random_device()() };

	int _width;
	int _height;
	Grid _grid;

public:
	GameOfLife() = delete;
	GameOfLife(int width, int height);

	int width() const;
	int height() const;
	const GridRow &operator[](int x) const;
	GridRow &operator[](int x);
};

