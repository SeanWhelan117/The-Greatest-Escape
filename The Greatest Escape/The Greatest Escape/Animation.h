#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();

	/// <summary>
	/// ANimation funtion used for animating a spritesheet
	/// </summary>
	/// <param name="t_texture"></param>
	/// <param name="t_numOfFrames"></param>
	/// <param name="t_frameWidth"></param>
	/// <param name="t_frameHeight"></param>
	/// <param name="t_cols"></param>
	/// <param name="t_rows"></param>
	/// <returns></returns>
	sf::IntRect animate(sf::Texture t_texture, int t_numOfFrames, int t_frameWidth, int t_frameHeight, int t_cols, int t_rows);


private:

	int animationFrame = 0;  //number of animation frames in the sprite sheet
	int totalElapsed = 0; //total elapsed is the speed at which you would like the animation to got at
	// higher the total elapsed the more time on each frame

	sf::IntRect rectSourceSprite; //the intrect of the current frame of the spritesheet.
	//This is set to the background sprites texture

};

