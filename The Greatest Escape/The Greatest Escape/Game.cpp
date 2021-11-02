#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

//updates per milliseconds
static double const MS_PER_UPDATE = 10.0;


Game::Game()
	: m_window(sf::VideoMode(1440, 900, 32), "SFML Playground", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);

	if (!m_font.loadFromFile("./ASSETS/FONTS/arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}

}



////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		//processGameEvents(event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{

	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;

		default:
			break;
		}
	}
}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	if (gameState == GameState::mainmenu)
	{
		menu.update(gameState);
	}


	if (gameState == GameState::endGame)
	{
		m_window.close();
	}

	if (gameState != GameState::mainmenu && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		gameState = GameState::mainmenu;
	}

	if (gameState == GameState::gameplay)
	{
		player.update();
	}
}

////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color::Blue);


	if (gameState == GameState::mainmenu)
	{
		menu.render(m_window);
	}

	if (gameState == GameState::gameplay)
	{
		m_window.clear(sf::Color(0,75,21,255));
		player.render(m_window);
	}

	if (gameState == GameState::instructions)
	{
		m_window.clear(sf::Color::Red);
	}

	if (gameState == GameState::options)
	{
		m_window.clear(sf::Color::Magenta);
	}

	m_window.display();
}

