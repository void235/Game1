#include "Game.h"

Game::Game()
{
	InitWindow();
	InitVariables();
	InitView();
	InitGround();
	
}

Game::~Game()
{
}

void Game::Run()
{
	Update();
	Render();
}

void Game::InitWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(screen_width, screen_height), "Game", sf::Style::Close);
	window->setFramerateLimit(60);
}

void Game::InitView()
{
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(window->getSize().x, window->getSize().y));
}

void Game::InitVariables()
{
	VIEW_WIDTH = window->getSize().x;
	VIEW_HEIGHT = window->getSize().y;

	


}

void Game::InitGround()
{
	ground = new Ground(window);
}

void Game::PollEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
	}
	
}

void Game::Update()
{
	player.m_DeltaTime = player.m_Clock.restart().asSeconds();

	PollEvents();
	view->setCenter(player.GetPosition());
	player.Update();

	ground->Making_player_stand_on_ground();
}

void Game::Render()
{
	window->clear(sf::Color::Black);

	window->setView(*view);

	ground->Render(window);
	

	player.Render(window);

	window->display();
}
