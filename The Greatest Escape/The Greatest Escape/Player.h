#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class Player
{
public:
	Player();

	void loadAssets();

	void update();
	void render(sf::RenderWindow& t_window);

private:
	sf::Sprite m_player;


};

