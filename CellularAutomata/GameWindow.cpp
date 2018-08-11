#include "stdafx.h"
#include "GameWindow.h"

void GameWindow::start()
{
	_clock.restart();
    while (_window.isOpen())
    {
		sf::Event event;
		while (_window.pollEvent(event))
			handleEvent(event);

		_window.clear(sf::Color::Black);
		if (!_gamePaused)
			updateAutomaton();
		drawGrid();
        _window.display();
    }
}

void GameWindow::handleEvent(sf::Event &event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
	{
		_window.close();
		break;
	}
	case sf::Event::KeyPressed:
	{
		// toggle game progression
		if (event.key.code == sf::Keyboard::Space)
			_gamePaused = !_gamePaused;
		break;
	}
	case sf::Event::MouseButtonPressed:
	{
		// convert window coordinates to grid coordinates
		auto x = event.mouseButton.x * _automatonPtr->width() / _window.getSize().x;
		auto y = event.mouseButton.y * _automatonPtr->height() / _window.getSize().y;

		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			_automatonPtr->grid()[x][y] = Cell::Alive;
			break;
		case sf::Mouse::Right:
			_automatonPtr->grid()[x][y] = Cell::Dead;
			break;
		case sf::Mouse::Middle:
#ifdef _DEBUG
			_automatonPtr->printDebugInfoFor(x, y);
#endif
			break;
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}

void GameWindow::drawGrid()
{
    for (auto x = 0; x < _automatonPtr->width(); x++)
    {
        for (auto y = 0; y < _automatonPtr->height(); y++)
        {
			// create a square for each cell. it's color is determined by its state.    
			auto width = static_cast<float>(InitialScreenWidth / _automatonPtr->width());
			auto height = static_cast<float>(InitialScreenHeight / _automatonPtr->height());

			sf::RectangleShape square(sf::Vector2f(width, height));
			square.setPosition(x * width, y * height);
			if (_automatonPtr->grid()[x][y] == Cell::Alive)
				square.setFillColor(sf::Color::Blue);
			else
				square.setFillColor(sf::Color::White);

			_window.draw(square);
        }
    }
}

void GameWindow::updateAutomaton()
{
    // wait 100ms before updating
	if (_clock.getElapsedTime().asMilliseconds() <= UpdateIntervalMs) return;
	_clock.restart();
	_automatonPtr->update();
}

GameWindow::GameWindow(std::shared_ptr<Automaton> automatonPtr) : _automatonPtr(automatonPtr)
{
}
