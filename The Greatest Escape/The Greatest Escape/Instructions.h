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
};

