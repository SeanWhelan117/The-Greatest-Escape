#include "Player.h"

Player::Player()
{

	loadAssets();

	m_player.setTexture(m_playerTexture);

	m_player.setPosition(200, 200);
	m_player.setScale(0.1, 0.1);
	//m_player.setOrigin(m_player.g)
	//std::cout << "player created" << std::endl;
}

void Player::loadAssets()
{
	if (!m_playerTexture.loadFromFile("ASSETS/SPRITES/PLAYER/playerTest.png"))
	{
		std::cout << "Error with loading player texture file (playerTest)";
	}

}

void Player::update()
{
	mousePos = sf::Mouse::getPosition();
	rotatePlayer(mousePos);

}

void Player::render(sf::RenderWindow& t_window)
{

	t_window.draw(m_player);
}

void Player::rotatePlayer(sf::Vector2i t_mousePos)
{
	sf::Vector2f playerPos = m_player.getPosition();

	if (playerPos.x < t_mousePos.x)
	{
		m_player.rotate(5);
	}

}

