#include "MainMenu.h"

/// <summary>
/// Constructor function for the main menu
/// </summary>
MainMenu::MainMenu()
{

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

	//drawing buttons

	t_window.draw(m_buttonOneText);
	t_window.draw(m_buttonTwoText);
	t_window.draw(m_buttonThreeText);
	t_window.draw(m_buttonFourText);

}

void MainMenu::setupButtonText()
{
	//button 1 setup
	m_buttonOneText.Bold;
	m_buttonOneText.setFont(m_font);
	m_buttonOneText.setCharacterSize(32u);
	m_buttonOneText.setPosition(buttons[0].getPosition().x + (buttons[0].getSize().x / 3), 320);
	m_buttonOneText.setFillColor(sf::Color::Black);
	m_buttonOneText.setString("Play");

	//button 2 setup
	m_buttonTwoText.Bold;
	m_buttonTwoText.setFont(m_font);
	m_buttonTwoText.setCharacterSize(32u);
	m_buttonTwoText.setPosition(buttons[1].getPosition().x + (buttons[1].getSize().x / 10), 440);
	m_buttonTwoText.setFillColor(sf::Color::Black);
	m_buttonTwoText.setString("Instructions");


	//button 3 setup

	m_buttonThreeText.Bold;
	m_buttonThreeText.setFont(m_font);
	m_buttonThreeText.setCharacterSize(32u);
	m_buttonThreeText.setPosition(buttons[2].getPosition().x + (buttons[2].getSize().x / 4.5), 560);
	m_buttonThreeText.setFillColor(sf::Color::Black);
	m_buttonThreeText.setString("Options");

	
	//button 3 setup

	m_buttonFourText.Bold;
	m_buttonFourText.setFont(m_font);
	m_buttonFourText.setCharacterSize(32u);
	m_buttonFourText.setPosition(buttons[3].getPosition().x + (buttons[3].getSize().x / 7), 680);
	m_buttonFourText.setFillColor(sf::Color::Black);
	m_buttonFourText.setString("Exit Game");
	 
}
