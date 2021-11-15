#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>


class Instructions
{
public:
	Instructions();

	void loadAssets();

	void update();
	void render(sf::RenderWindow& t_window);

private:

	sf::Font m_font; // arial.ttf font

	sf::Text m_instructionsText;
};

