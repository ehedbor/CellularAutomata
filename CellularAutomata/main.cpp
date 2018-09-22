#include "stdafx.h"
#include "GameWindow.h"
#include <memory>
#include "WireWorld.h"

int main()
{
    GameWindow gameWindow(std::make_shared<WireWorld>());
    gameWindow.start();
    return 0;
}
