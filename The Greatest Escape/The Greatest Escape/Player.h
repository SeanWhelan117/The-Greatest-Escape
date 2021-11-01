#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cmath>


class Player
{
public:
	Player();

	void loadAssets();

	void update();
	void render(sf::RenderWindow& t_window);

private:
	sf::Sprite m_player;
	sf::Texture m_playerTexture;

	sf::Vector2i mousePos; // mouses current position

	void rotatePlayer(sf::Vector2i t_mousePos);

	void checkForPlayerMovement();

};

