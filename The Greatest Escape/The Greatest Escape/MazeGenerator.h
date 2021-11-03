#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class MazeGenerator
{
public:
	MazeGenerator();

	void loadAssets();

	void update();

	void render(sf::RenderWindow& t_window);
	static const int NUM_OF_WALLS = 50;
	sf::Sprite m_walls[NUM_OF_WALLS];

private:
	


	sf::Texture wallTexture;

};

