#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Globals.h"
//#include <math.h>
//#include <cmath>


class Player
{
public:
	Player();

	void loadAssets();

	void update();
	void render(sf::RenderWindow& t_window);

	sf::Sprite m_player;
private:
	sf::Texture m_playerTexture;

	sf::Vector2i mousePos; // mouses current position
	const double PI = 3.141592654;

	float speed = 0.5f;

	int m_playerHealth = 100;

	void rotatePlayer(sf::Vector2i t_mousePos);

	void checkForPlayerMovement();

	void sprint();

	void takeDamage(int t_damageAmount);

};

