#include "stdafx.h"
#include "GameWindow.h"
#include "WireWorld.h"
#include <memory>
#include <iostream>

std::shared_ptr<Automaton> selectAutomaton();

int main()
{
	auto automaton = selectAutomaton();
    GameWindow gameWindow(automaton, 400, 400, "Cellular Automata");
    gameWindow.start();
    return 0;
}

std::shared_ptr<Automaton> selectAutomaton()
{
	std::cout << "What type of automata would you like?" << std::endl;
	std::cout << "    1. Conway's Game of Life" << std::endl;
	std::cout << "    2. WireWorld" << std::endl;
	std::cout << std::endl;
	std::cout << "Choice: ";

	std::shared_ptr<Automaton> automaton;
	bool bad = true;
	while (bad)
	{
		// proceed on a successful read
		std::string choice;
		if (std::getline(std::cin, choice))
		{
			if (choice == "1")
			{
				bad = false;
				automaton = std::make_shared<GameOfLife>();
			}
			else if (choice == "2")
			{
				bad = false;
				automaton == std::make_shared<WireWorld>();
			}
		}

		if (bad)
		{
			std::cout << "Try again: ";
		}
	}

	return automaton;
}