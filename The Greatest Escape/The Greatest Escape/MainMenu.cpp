#include "MainMenu.h"

/// <summary>
/// Constructor function for the main menu
/// </summary>
MainMenu::MainMenu()
{

	int buttonPosX = (Globals::SCREEN_X / 2) - 100;//600;
	int buttonPosY = (Globals::SCREEN_Y / 4) - 25;//200;

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		buttons[i].setFillColor(sf::Color(255, 255, 255, 128));

		buttons[i].setSize(sf::Vector2f(200, 50));
		buttonPosY = buttonPosY + 120;
		buttons[i].setPosition(sf::Vector2f(buttonPosX, buttonPosY));

	}

	loadAssets();
	setupButtonText();


	m_backgroundImage.setTexture(backgroundTexture);
	m_playerForMenuImage.setTexture(playerTexture);
	m_playerForMenuImage.setPosition(-80, 250);
	m_playerForMenuImage.setScale(0.6, 0.6);

	setupBackgroundImage();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::loadAssets()
{
	if (!m_font.loadFromFile("./ASSETS/FONTS/arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}

	if (!backgroundTexture.loadFromFile("./ASSETS/SPRITES/BACKGROUND/FinalSpriteSheet3.png"))
	{
		std::cout << "Error loading the menus background texture" << std::endl;
	}

	if (!playerTexture.loadFromFile("./ASSETS/SPRITES/BACKGROUND/playerForMenu.png"))
	{
		std::cout << "Error loading the player for menu texture" << std::endl;
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::update(GameState& t_gameState, sf::RenderWindow& t_window)
{
	mousePos = sf::Mouse::getPosition(t_window);

	//std::cout << "Mouse Position x = " << mousePos.x << " Mouse Position y = " << mousePos.y << std::endl;

	mouseButtonCollision(mousePos, t_gameState);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::render(sf::RenderWindow& t_window)
{

	textureRect = anim.animate(backgroundTexture, 11, spriteX, spriteY, 3, 4);
	m_backgroundImage.setTextureRect(textureRect);
	t_window.draw(m_backgroundImage);

	t_window.draw(m_playerForMenuImage);

	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		t_window.draw(buttons[i]);
	}

	//drawing buttons

	t_window.draw(m_buttonOneText);
	t_window.draw(m_buttonTwoText);
	t_window.draw(m_buttonThreeText);
	t_window.draw(m_buttonFourText);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::setupButtonText()
{
	//button 1 setup
	m_buttonOneText.Bold;
	m_buttonOneText.setFont(m_font);
	m_buttonOneText.setCharacterSize(32u);
	m_buttonOneText.setPosition(buttons[0].getPosition().x + (buttons[0].getSize().x / 3), 320);
	m_buttonOneText.setFillColor(sf::Color::Black);
	m_buttonOneText.setString("Play");

	//button 2 setup
	m_buttonTwoText.Bold;
	m_buttonTwoText.setFont(m_font);
	m_buttonTwoText.setCharacterSize(32u);
	m_buttonTwoText.setPosition(buttons[1].getPosition().x + (buttons[1].getSize().x / 10), 440);
	m_buttonTwoText.setFillColor(sf::Color::Black);
	m_buttonTwoText.setString("Instructions");


	//button 3 setup

	m_buttonThreeText.Bold;
	m_buttonThreeText.setFont(m_font);
	m_buttonThreeText.setCharacterSize(32u);
	m_buttonThreeText.setPosition(buttons[2].getPosition().x + (buttons[2].getSize().x / 4.5), 560);
	m_buttonThreeText.setFillColor(sf::Color::Black);
	m_buttonThreeText.setString("Options");

	
	//button 4 setup

	m_buttonFourText.Bold;
	m_buttonFourText.setFont(m_font);
	m_buttonFourText.setCharacterSize(32u);
	m_buttonFourText.setPosition(buttons[3].getPosition().x + (buttons[3].getSize().x / 7), 680);
	m_buttonFourText.setFillColor(sf::Color::Black);
	m_buttonFourText.setString("Exit Game");
	 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::mouseButtonCollision(sf::Vector2i t_mousePos, GameState& t_gameState)
{
	if (t_mousePos.x < buttons[0].getPosition().x + 200 && t_mousePos.x > buttons[0].getPosition().x) //just a check that the mouse is within the same x coords as all buttons
	{
		if (t_mousePos.y > buttons[0].getPosition().y && t_mousePos.y < buttons[0].getPosition().y + 50)
		{
			buttons[0].setFillColor(sf::Color::Yellow);
			buttons[0].setScale(1.25, 1.25);
			m_buttonOneText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Play pressed" << std::endl;
				t_gameState = GameState::gameplay;
			}
		}
		else if (t_mousePos.y > buttons[1].getPosition().y && t_mousePos.y < buttons[1].getPosition().y + 50)
		{
			buttons[1].setFillColor(sf::Color::Yellow);
			buttons[1].setScale(1.25, 1.25);
			m_buttonTwoText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Instructions pressed" << std::endl;
				t_gameState = GameState::instructions;
			}


		}
		else if (t_mousePos.y > buttons[2].getPosition().y && t_mousePos.y < buttons[2].getPosition().y + 50)
		{
			buttons[2].setFillColor(sf::Color::Yellow);
			buttons[2].setScale(1.25, 1.25);
			m_buttonThreeText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Options pressed" << std::endl;
				t_gameState = GameState::options;
			}

		}
		else if (t_mousePos.y > buttons[3].getPosition().y && t_mousePos.y < buttons[3].getPosition().y + 50)
		{
			buttons[3].setFillColor(sf::Color::Yellow);
			buttons[3].setScale(1.25, 1.25);
			m_buttonFourText.setScale(1.25, 1.25);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "End Game pressed" << std::endl;
				t_gameState = GameState::endGame;
			}
		}
		else
		{
			resetButtons();
		}

	}
	else
	{
		resetButtons();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::resetButtons()
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		//buttons[i].setFillColor(sf::Color::Red);
		buttons[i].setFillColor(sf::Color(255, 255, 255, 128));
		buttons[i].setScale(1, 1);
	}
	m_buttonOneText.setScale(1, 1);
	m_buttonTwoText.setScale(1, 1);
	m_buttonThreeText.setScale(1, 1);
	m_buttonFourText.setScale(1, 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainMenu::setupBackgroundImage()
{
	// Scale is screenX / imageSizeX, screenY / imageSizeY
	 spriteX = backgroundTexture.getSize().x / 3;
	 spriteY = backgroundTexture.getSize().y / 4;

	float xScale = Globals::SCREEN_X / spriteX;
	float yScale = Globals::SCREEN_Y / spriteY;

	std::cout << xScale << yScale << std::endl;

	m_backgroundImage.setScale(xScale, yScale);


	m_backgroundImage.setPosition(0, 0);

}

