#include "MainMenu.h"

/// <summary>
/// Constructor function for the main menu
/// </summary>
MainMenu::MainMenu()
{
	std::cout << "Menu Created..." << std::endl;

	int buttonPosX = 600;
	int buttonPosY = 200;
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		buttons[i].setFillColor(sf::Color::Red);
		buttons[i].setSize(sf::Vector2f(200, 50));
		buttonPosY = buttonPosY + 120;
		buttons[i].setPosition(sf::Vector2f(buttonPosX, buttonPosY));

	}

	loadAssets();
	setupButtonText();
}

void MainMenu::loadAssets()
{
	if (!m_font.loadFromFile("./ASSETS/FONTS/arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

}

void MainMenu::update()
{
}

void MainMenu::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		t_window.draw(buttons[i]);
	}

	t_window.draw(m_buttonOneText);
	t_window.draw(m_buttonTwoText);
	t_window.draw(m_buttonThreeText);
	t_window.draw(m_buttonFourText);

}

void MainMenu::setupButtonText()
{
	m_buttonOneText.Bold;
	m_buttonOneText.setFont(m_font);
	m_buttonOneText.setCharacterSize(32u);
	m_buttonOneText.setPosition(buttons[0].getPosition().x + (buttons[0].getSize().x / 3), 320);
	m_buttonOneText.setFillColor(sf::Color::Black);
	m_buttonOneText.setString("Play");
	 
}
