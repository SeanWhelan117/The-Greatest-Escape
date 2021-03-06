#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

#include "GameState.h"
#include "Animation.h"
#include "Globals.h"

class MainMenu
{
public:
	Animation anim;
	
	MainMenu();
	void loadAssets();

	void update(GameState& t_gameState, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);


private:

	void setupButtonText(); // setups font colour all that stuff for the button text

	void mouseButtonCollision(sf::Vector2i t_mousePos, GameState& t_gameState); // checks for collision with the mouse and buttons.
	//if the mouse is hovering changes that specific button
	//resets changes when it leaves that button
	//checks for that buttons click aswell

	void resetButtons(); //small function which is called to reset buttons after they are not being hoverd over anymore

	void setupBackgroundImage(); //sets up the position and scale of the background image

	static const int MAX_BUTTONS = 4;
	sf::RectangleShape buttons[MAX_BUTTONS]; // buttons array for menu buttons

	sf::Font m_font; // arial.ttf font

	//text for each button stating what they are

	//just sf texts for the buttons
	sf::Text m_buttonOneText;
	sf::Text m_buttonTwoText;
	sf::Text m_buttonThreeText;
	sf::Text m_buttonFourText;

	sf::Vector2i mousePos; // mouses current position

	sf::Sprite m_backgroundImage;
	sf::Texture backgroundTexture;

	sf::Sprite m_playerForMenuImage;
	sf::Texture playerTexture;

	sf::IntRect textureRect;
	
	float spriteX = 0; //the x and y size of every specific sprite in the spritesheet 
	float spriteY = 0;


};

