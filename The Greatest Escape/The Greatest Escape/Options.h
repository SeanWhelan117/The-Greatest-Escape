#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>


class Options
{
public:
	Options();

	void loadAssets();

	void update();
	void render(sf::RenderWindow& t_window);


private:

	sf::Font m_font; // arial.ttf font
	sf::Text m_optionsText;
};

