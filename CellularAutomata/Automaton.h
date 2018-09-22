#pragma once
#include <vector>
#include "Cell.h"
#include <SFML/Graphics/Color.hpp>


/// <summary>
/// Defines a basic template for a cellular automaton.
/// </summary>
class Automaton
{
public:
	static constexpr int DefaultSize = 20;
    
    using GridRow = std::vector<cell_t>;
    using Grid = std::vector<GridRow>;

private:
    int _width;
    int _height;
    Grid _grid{};

protected:
    /// <summary>
    /// Returns the next state for a particular cell based on the existing state.
    /// </summary>
    virtual cell_t nextCellState(int x, int y) const = 0;

	/// <summary>
	/// Returns the number of cells surrounding the given cell with the given cell type.
	/// </summary>
	int getNeighborCountWithType(int x, int y, cell_t cellType) const;

public:
    /// <summary>
    /// Creates an automaton with a width and height of Automaton::DefaultSize.
    /// <summary>
    Automaton();

    /// <summary>
    /// Creates an automaton of the specified width and height.
    /// </summary>
    Automaton(int width, int height);

    // Define a virtual destructor because this class is polymorphic
    virtual ~Automaton() noexcept = default;

    // Redefine copy and move constructors - removed by destructor
    Automaton(const Automaton &) = default;
    Automaton(Automaton &&) = default;
    Automaton &operator=(const Automaton &) = default;
    Automaton &operator=(Automaton &&) = default;

    /// <summary>
    /// Replaces the grid with a new grid representing the next state of the automaton.
    /// </summary>
    virtual void update();

    /// <summary>
    /// Prints information helpful for debugging.
    /// </summary>
    virtual void printDebugInfoFor(int x, int y) const;

    /// <summary>
    /// Returns the color for the given cell.
    /// </summary>
	virtual const sf::Color &getColorForCell(int x, int y) const = 0;

	virtual void cycleNext(int x, int y) = 0;
	virtual void cyclePrev(int x, int y) = 0;

    // mutator/accessor methods
public:
    int width() const;
    int height() const;
    const GridRow &operator[](int x) const;
    GridRow &operator[](int x);

protected:
	Grid &grid();
	const Grid &grid() const;
};
