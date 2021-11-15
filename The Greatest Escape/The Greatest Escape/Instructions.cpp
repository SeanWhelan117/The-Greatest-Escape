#include "Instructions.h"

Instructions::Instructions()
{
	loadAssets();
	m_instructionsText.setFont(m_font);

	m_instructionsText.Bold;
	m_instructionsText.setFont(m_font);
	m_instructionsText.setCharacterSize(32u);
	m_instructionsText.setPosition(300, 300);;
	m_instructionsText.setFillColor(sf::Color::Black);
	m_instructionsText.setString("This page will have instructions for the player. \nThey will include a short description of the game, as well as \na description of the controls the player needs etc");
}

void Instructions::loadAssets()
{

	if (!m_font.loadFromFile("./ASSETS/FONTS/arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

}

void Instructions::update()
{
}

void Instructions::render(sf::RenderWindow& t_window)
{
	t_window.clear(sf::Color::Red);
	t_window.draw(m_instructionsText);
}
