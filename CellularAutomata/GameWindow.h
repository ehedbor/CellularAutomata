#pragma once
#include "GameOfLife.h"
#include <SFML/Graphics.hpp>
#include <memory>

/**
 * Controls the game progression and UI elements.
 */
class GameWindow
{
public:
	static constexpr unsigned int InitialScreenWidth = 400;
	static constexpr unsigned int InitialScreenHeight = 400;
	static constexpr int UpdateIntervalMs = 200;

private:
	std::shared_ptr<Automaton> _automatonPtr;
	sf::RenderWindow _window{ sf::VideoMode{InitialScreenWidth, InitialScreenHeight}, "Cellular Automata" };
	sf::Clock _clock{};
	bool _gamePaused{ true };

	/**
	 * Handles a single SFML event.
	 */
	void handleEvent(sf::Event &event);

	/**
	 * Draws the grid representation.
	 */
	void drawGrid();

	/**
	 * Updates the automaton to the next state.
	 */
	void updateAutomaton();

public:
	explicit GameWindow(std::shared_ptr<Automaton> automatonPtr);

	/**
	 * Starts the main game loop.
	 */
	void start();
};

