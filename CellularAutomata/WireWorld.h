#pragma once
#include "Automaton.h"
#include <SFML/Graphics/Color.hpp>
#include <string>

/// <summary>
/// An implementation of WireWorld.
/// </summary>
/// <remarks>
/// The full rules are as follows:
/// <list type="number">
///     <item>
///         <description>An empty cell stays as an empty cell.</description>
///     </item>
///     <item>
///        <description>An electron head becomes an electron tail.</description>
///     </item>
///     <item>
///         <description>An electron tail becomes a wire.</description>
///     </item>
///     <item>
///         <description>A wire becomes an electron head if and only if one or two of its neighbors are electron heads.</description>
///     </item>
/// </list>
/// </remarks>
class WireWorld : public Automaton
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

		static constexpr cell_t Empty = 0;
		static constexpr cell_t ElectronHead = 1;
		static constexpr cell_t ElectronTail = 2;
		static constexpr cell_t Wire = 3;

		static std::string toString(cell_t cell);
    };

protected:
    cell_t nextCellState(int x, int y) const override;

public:
	WireWorld();
	WireWorld(int width, int height);

    void printDebugInfoFor(int x, int y) const override;

    const sf::Color &getColorForCell(int x, int y) const override;

	void cycleNext(int x, int y) override;
	void cyclePrev(int x, int y) override;
};

