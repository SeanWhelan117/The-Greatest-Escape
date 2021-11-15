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

	void update(const sf::RenderWindow& t_window, bool  t_colliding);
	void render(sf::RenderWindow& t_window);

	sf::Sprite m_player;
	float speed = 0.5f; //speed which the player moves at 
private:
	sf::Texture m_playerTexture;

	sf::Vector2i mousePos; // mouses current position
	const double PI = 3.141592654;


	int m_playerHealth = 100; //players initial health

	// a function which follows the players mouse position and rotates the player based on that postion
	void rotatePlayer(sf::Vector2i t_mousePos); 

	// A function which checks for input from the player and moves the player based on this input.
	void checkForPlayerMovement(bool t_colliding);

	//increases the speed of the player 
	void sprint();

	//takes damage away from the players health when they get hit
	void takeDamage(int t_damageAmount);

	sf::Vector2f lastPos;

};

