#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class MainMenu
{
public:
	MainMenu();
	void loadAssets();

	void update();
	void render(sf::RenderWindow& t_window);




private:

	void setupButtonText();

	void mouseButtonCollision(sf::Vector2i t_mousePos);

	void resetButtons();

	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS]; // buttons array for menu buttons

	sf::Font m_font; // arial.ttf font

	//text for each button stating what they are

	sf::Text m_buttonOneText;
	sf::Text m_buttonTwoText;
	sf::Text m_buttonThreeText;
	sf::Text m_buttonFourText;

	sf::Vector2i mousePos; // mouses current position

};

