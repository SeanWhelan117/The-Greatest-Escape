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

	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS]; // buttons array for menu buttons

};

