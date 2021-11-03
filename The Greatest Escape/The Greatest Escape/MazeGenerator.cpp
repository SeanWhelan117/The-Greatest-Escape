#include "MazeGenerator.h"

MazeGenerator::MazeGenerator()
{

	loadAssets();

	for (int i = 0; i < NUM_OF_WALLS; i++)
	{
		int randX = rand() % 1440 + 1;
		int randY = rand() % 900 + 1;
		m_walls[i].setTexture(wallTexture);
		m_walls[i].setPosition(randX, randY);
		m_walls[i].setScale(0.1f, 0.1f);
	}
}

void MazeGenerator::loadAssets()
{

	if (!wallTexture.loadFromFile("./ASSETS/SPRITES/WALLS/bush.png"))
	{
		std::cout << "Error loading the walls texture (bush.png)" << std::endl;
	}
}

void MazeGenerator::update()
{
	
}

void MazeGenerator::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < NUM_OF_WALLS; i++)
	{
		t_window.draw(m_walls[i]);
	}
}
