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
}

void MainMenu::loadAssets()
{
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

}
