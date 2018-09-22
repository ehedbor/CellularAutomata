#pragma once
#include <random>
#include "Cell.h"
#include "Automaton.h"
#include <SFML/Graphics/Color.hpp>
#include <string>

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
public:
    struct Cell
    {
		Cell() = delete;
		~Cell() = delete;
		Cell(const Cell &) = delete;
		Cell &operator=(const Cell &) = delete;
		Cell(Cell &&) = delete;
		Cell &operator=(Cell &&) = delete;

		static constexpr cell_t Dead = 0;
		static constexpr cell_t Alive = 1;

		static std::string toString(cell_t cell);
    };

private:
    std::mt19937 _random{std::random_device()()};

    /// <summary>
    /// Initializes each value in the grid to a random cell.
    /// </summary>
    void generateGrid();

protected:
    cell_t nextCellState(int x, int y) const override;

public:
    GameOfLife();
    GameOfLife(int width, int height);

    void update() override;

    void printDebugInfoFor(int x, int y) const override;

    const sf::Color &getColorForCell(int x, int y) const override;

    void cycleNext(int x, int y) override;
    void cyclePrev(int x, int y) override;
};
