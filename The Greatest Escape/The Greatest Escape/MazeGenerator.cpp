#include "MazeGenerator.h"

MazeGenerator::MazeGenerator()
{

	loadAssets();

	for (int i = 0; i < NUM_OF_WALLS; i++)
	{
		m_walls[i].setTexture(wallTexture);
		m_walls[i].setScale(0.1f, 0.1f);
	}

	placeWalls();
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

/// <summary>
/// In a later sprint the walls will be placed by reading positions from a file. This way we can have multiple files for different levels
/// and then when we decide which level to play the specific file will be opened and the vectors extracted
/// For now though, as we have just 1 level we are going to hardcode the positions of the mazes wall sections.
/// </summary>
void MazeGenerator::placeWalls()
{
	//position and rotation of every sprite.
	// screen size is 1400 by 900
	// player pos is 700, 800

	m_walls[0].setPosition(750, 750);
	m_walls[0].setRotation(0);

	


	for (int i = 1; i < 11; i++)
	{
		m_walls[i].setPosition(m_walls[i - 1].getPosition().x + m_walls[i].getGlobalBounds().width, 750);
	}


	m_walls[11].setPosition(m_walls[10].getPosition().x + m_walls[10].getGlobalBounds().width - m_walls[10].getGlobalBounds().height, m_walls[10].getPosition().y);
	m_walls[11].setRotation(-90);

	for (int j = 12; j < 23; j++)
	{
		m_walls[j].setPosition(m_walls[10].getPosition().x + m_walls[10].getGlobalBounds().width - m_walls[10].getGlobalBounds().height, 
			m_walls[j - 1].getPosition().y - m_walls[j - 1].getGlobalBounds().height);
		m_walls[j].setRotation(-90);
	}

	m_walls[23].setPosition(600, 750);
	m_walls[23].setRotation(0);

	for (int k = 24; k < 34; k++)
	{
		m_walls[k].setPosition(m_walls[k - 1].getPosition().x - m_walls[k].getGlobalBounds().width, 750);
	}

	m_walls[34].setPosition(m_walls[33].getPosition().x , m_walls[33].getPosition().y);
	m_walls[34].setRotation(-90);

	for (int q = 35; q < 46; q++)
	{
		m_walls[q].setPosition(m_walls[34].getPosition().x ,
			m_walls[q - 1].getPosition().y - m_walls[q - 1].getGlobalBounds().height);
		m_walls[q].setRotation(-90);
	}

}