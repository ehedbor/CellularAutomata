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
    /// The width of the viewport before being resized.
    /// </summary>
    static constexpr unsigned int InitialScreenWidth = 400;

    /// <summary>
    /// The height of the viewport before being resized.
    /// </summary>
    static constexpr unsigned int InitialScreenHeight = 400;

    /// <summary>
    /// The number of milliseconds between each update.
    /// </summary>
    static constexpr int UpdateIntervalMs = 200;

private:
    std::shared_ptr<Automaton> _automatonPtr;
    sf::RenderWindow _window{sf::VideoMode{InitialScreenWidth, InitialScreenHeight}, "Cellular Automata"};
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
    explicit GameWindow(std::shared_ptr<Automaton> automatonPtr);

    /// <summary>
    /// Starts the main game loop.
    /// </summary>
    void start();
};
