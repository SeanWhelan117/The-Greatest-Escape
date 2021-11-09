#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Globals.h"

class MazeGenerator
{
public:
	MazeGenerator();

	void loadAssets();

	void update();

	void render(sf::RenderWindow& t_window);
	static const int NUM_OF_WALLS = 350;
	sf::Sprite m_walls[NUM_OF_WALLS];

private:

	sf::Texture wallTexture;
	void placeWalls();
};

