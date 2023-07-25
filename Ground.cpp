#include "Ground.h"

Ground::Ground(sf::RenderWindow* window)
{
	InitGround(window);
	InitVariables();
}

void Ground::InitGround(sf::RenderWindow* window)
{
	m_GroundTexture.loadFromFile("textures/ground.png");
	m_Ground.setTexture(&m_GroundTexture);
	m_Ground.setSize(sf::Vector2f(1141, 281));
	
}

void Ground::Making_player_stand_on_ground()
{
	if (player.m_PlayerSprite.getGlobalBounds().intersects(m_Ground.getGlobalBounds()))
	{
		player.player_position.y = m_Ground.getSize().y - player.m_PlayerSprite.getSize().y;
		player.m_PlayerSprite.setPosition(player.player_position.x, player.player_position.y);
		std::cout << "PLAYER::INTERSECTING::GROUND" << std::endl;
	}
	else
		InitGravity();
}

void Ground::InitGravity()
{
	player.player_velocity.y += m_Gravity;
	player.m_PlayerSprite.move(player.player_velocity.x, player.player_velocity.y);
	std::cout << "PLAYER::FALLING" << std::endl;	
}

void Ground::UpdateGravity()
{
}

void Ground::Render(sf::RenderWindow* window)
{
	window->draw(m_Ground);
}

void Ground::InitVariables()
{
	m_Gravity = 10.0f;
}
