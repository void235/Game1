#pragma once

#include "SFML/Graphics.hpp"

#include "Animation.h"
#include <iostream>

class Player
{
	private:
	public:
		Player();
		~Player();

		sf::RectangleShape m_PlayerSprite;
		sf::Texture m_PlayerTexture;

		Animation* animation;

		float m_DeltaTime;
		sf::Clock m_Clock;

		bool isIdle;
		sf::Vector2f player_position;
		sf::Vector2f player_velocity;

		float jump_speed;

		sf::Vector2f GetPosition();

		void InitVariables();
		void UpdateAnimation();
		void InitTextures();
		void InitAnimation();
		void Update();
		void Render(sf::RenderTarget* target);
};

