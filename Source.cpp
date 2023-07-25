#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Animation.h"
#include "Player.h"

int main(void)
{
	Game game;

	while (game.window->isOpen())
	{
		game.Run();
	}

	return 0;
}