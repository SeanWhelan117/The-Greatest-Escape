#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "GameState.h"
#include "MainMenu.h"
#include "Player.h"
#include "MazeGenerator.h"
#include "Globals.h"


class Game
{
public:

	Game();
	void run();

	MainMenu menu;
	Player player;
	MazeGenerator maze;

protected:

	GameState gameState{ GameState::mainmenu };


	sf::Font m_font;
	sf::Text m_gameText;
	
	//function thats used to check for collisions between the wall and the player
	void checkCollisions();

	void update(double dt);
	void render();
	void processEvents();

	/// <summary>
	/// @brief Handles all user input.
	/// </summary>
	/// <param name="event">system event</param>
	void processGameEvents(sf::Event&);

	// main window
	sf::RenderWindow m_window;

};

