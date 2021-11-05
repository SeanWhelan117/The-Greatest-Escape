#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();

	sf::IntRect animate(sf::Texture t_texture, int t_numOfFrames, int t_frameWidth, int t_frameHeight, int t_cols, int t_rows);


private:

	int animationFrame = 0; 
	int totalElapsed = 0;
	sf::IntRect rectSourceSprite;

};

