#pragma once
#include <vector>
#include "Cell.h"


/// <summary>
/// Defines a basic template for a cellular automaton.
/// </summary>
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

    /// <summary>
    /// Convenience function that returns the number of living cells surrounding the given cell.
    /// </summary>
    int getCellNeighborCount(int x, int y) const;

    /// <summary>
    /// Returns the next state for a particular cell based on the existing state.
    /// </summary>
    virtual Cell nextCellState(int x, int y) const = 0;

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


    // mutator/accessor methods
    int width() const;
    int height() const;
    Grid &grid();
    const Grid &grid() const;
    const GridRow &operator[](int x) const;
    GridRow &operator[](int x);
};
