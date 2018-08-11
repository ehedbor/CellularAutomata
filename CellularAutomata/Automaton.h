#pragma once
#include <vector>
#include "Cell.h"


/**
 * Defines a basic template for a cellular automaton.
 */
class Automaton
{
public:
	static constexpr int DefaultSize = 20;
	using GridRow = std::vector<Cell>;
	using Grid = std::vector<GridRow>;

private:
	int _width;
	int _height;
	Grid _grid{};

protected:

    /**
     * Convenience function that returns the number of living cells surrounding the given cell.
     */
    int getCellNeighborCount(int x, int y) const;

    /**
     * Returns the next state for a particular cell based on the existing state.
     */
    virtual Cell nextCellState(int x, int y) const = 0;

public:
    /**
     * Creates an empty automaton (width and height of 0).
     */
	Automaton();

    /**
     * Creates an automaton of the specified width and height.
     */
	Automaton(int width, int height);

	virtual ~Automaton() noexcept = default;

    /**
     * Replaces the old grid with a new grid representing the next state of the automaton.
     */
	virtual void update();

    /**
     * Prints information helpful for debugging.
     */
    virtual void printDebugInfoFor(int x, int y) const;

	int width() const;
	int height() const;
	Grid &grid();
	const Grid &grid() const;
    const GridRow &operator[](int x) const;
	GridRow &operator[](int x);

};
