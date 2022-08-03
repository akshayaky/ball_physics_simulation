#include <iostream>
#include "Window.h"
#include "Game.h"
#include "EventManager.h"
int main()
{
	Game game;
	while (!game.GetWindow()->IsDone())
	{
		game.Update();
		game.Render();
		game.RestartClock();
	}
}
