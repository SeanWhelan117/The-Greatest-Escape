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

	static const int NUM_OF_WALLS = 350; // An amount of walls that makes up the levels design
	sf::Sprite m_walls[NUM_OF_WALLS]; //An array of wall sprites NUM_OF_WALLS long

private:

	sf::Texture wallTexture;
	//function to place all of the walls on the map.
	//currently this is being used to hard code all of the walls locations.
	//In later sprints though we will hopefully read in the sprites for multiple levels via text files.
	void placeWalls(); 
};

