#pragma once
#include "GameOfLife.h"
#include <SFML/Graphics.hpp>
#include <memory>

/// <summary>
/// Controls the game progression and UI elements.
/// </summary>
class GameWindow
{
public:
    /// <summary>
    /// The default size of the viewport before being resized.
    /// </summary>
    static constexpr unsigned int DefaultScreenSize = 400;

    /// <summary>
    /// The number of milliseconds between each update.
    /// </summary>
    static constexpr int UpdateIntervalMs = 200;

private:
	std::shared_ptr<Automaton> _automatonPtr;
	sf::RenderWindow _window;
	unsigned int _initialScreenWidth{ DefaultScreenSize };
	unsigned int _initialScreenHeight{ DefaultScreenSize };
    sf::Clock _clock{};
    bool _gamePaused{true};

    /// <summary>
    /// Handles a single SFML event.
    /// </summary>
    void handleEvent(sf::Event &event);

    /// <summary>
    /// Draws the representation of the automaton.
    /// </summary>
    void drawGrid();

    /// <summary>
    /// Updates the automaton to the next state.
    /// </summary>
    void updateAutomaton();

public:
    /// <summary>
    /// Constructs a new GameWindow.
    /// </summary>
    /// <param name="automatonPtr">A pointer to the automaton to be used.</param>
    /// <param name="screenWidth">The initial screen width in pixels.</param>
	/// <param name="screenHeight">The initial screen height in pixels.</param>
	/// <param name="title">The name of the viewport.</param>
	GameWindow(std::shared_ptr<Automaton> automatonPtr, unsigned int screenWidth, unsigned int screenHeight, const sf::String &title);

    /// <summary>
    /// Starts the main game loop.
    /// </summary>
    void start();
};
