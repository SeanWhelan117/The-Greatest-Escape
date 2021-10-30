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

	void setupButtonText(); // setups font colour all that stuff for the button text

	void mouseButtonCollision(sf::Vector2i t_mousePos); // checks for collision with the mouse and buttons.
	//if the mouse is hovering changes that specific button
	//resets changes when it leaves that button
	//checks for that buttons click aswell

	void resetButtons(); //small function which is called to reset buttons after they are not being hoverd over anymore

	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS]; // buttons array for menu buttons

	sf::Font m_font; // arial.ttf font

	//text for each button stating what they are

	//just sf texts for the buttons
	sf::Text m_buttonOneText;
	sf::Text m_buttonTwoText;
	sf::Text m_buttonThreeText;
	sf::Text m_buttonFourText;

	sf::Vector2i mousePos; // mouses current position

};

