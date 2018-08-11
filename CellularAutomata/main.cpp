#include "stdafx.h"
#include "GameWindow.h"
#include <memory>

int main()
{
	GameWindow gameWindow(std::make_shared<GameOfLife>());
	gameWindow.start();
	return 0;
}