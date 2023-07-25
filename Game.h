#pragma once

#include "SFML/Graphics.hpp"

#include "Player.h"
#include "Ground.h"

class Game
{
	private:

		const int screen_width = 640;
		const int screen_height = 480;

		int VIEW_WIDTH;
		int VIEW_HEIGHT;

		Player player;

	public:
		sf::RenderWindow* window;
		sf::Event event;
		sf::View* view;

		Ground* ground;

		Game();
		~Game();

		void Run();
		void InitWindow();
		void InitVariables();
		void InitGround();
		void InitView();
		void PollEvents();
		void Update();
		void Render();
};

