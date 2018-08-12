#pragma once
#include <random>
#include "Cell.h"
#include "Automaton.h"

/// <summary>
/// An implementation of Conway's Game of Life.  
/// </summary>
/// <remarks>
/// The full rules are as follows:
/// <list type="number">
///     <item>
///         <description>Any live cell with fewer than two live neighbors dies.</description>
///     </item>
///     <item>
///        <description>Any live cell with two or three live neighbors lives.</description>
///     </item>
///     <item>
///         <description>Any live cell with more than three live neighbors dies.</description>
///     </item>
///     <item>
///         <description>Any dead cell with exactly three live neighbors becomes a live cell.</description>
///     </item>
/// </list>
/// </remarks>
class GameOfLife : public Automaton
{
private:
    std::mt19937 _random{std::random_device()()};

    /// <summary>
    /// Initializes each value in the grid to a random cell.
    /// </summary>
    void generateGrid();

protected:
    Cell nextCellState(int x, int y) const override;

public:
    GameOfLife();
    GameOfLife(int width, int height);

    void update() override;
};
