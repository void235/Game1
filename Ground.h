#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Ground
{
	private:
		Player player;
	public:
		sf::RectangleShape m_Ground;
		sf::Texture m_GroundTexture;

		Ground(sf::RenderWindow* window);
		~Ground();

		float m_Gravity;

		void InitGround(sf::RenderWindow* window);
		void Making_player_stand_on_ground();
		void InitGravity();
		void UpdateGravity();
		void InitVariables();

		void Render(sf::RenderWindow* window);

		
};

