#include "Player.h"

Player::Player()
{

	loadAssets();

	m_player.setTexture(m_playerTexture);

	m_player.setPosition(200, 200);
	m_player.setOrigin((m_player.getGlobalBounds().width / 2), (m_player.getGlobalBounds().height / 2));
	m_player.setScale(0.1, 0.1);
	//std::cout << "player created" <<std::to_string(m_player.getOrigin().x) << " " << std::to_string(m_player.getOrigin().y) << std::endl;
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
	checkForPlayerMovement();

}

void Player::render(sf::RenderWindow& t_window)
{

	t_window.draw(m_player);
}

void Player::rotatePlayer(sf::Vector2i t_mousePos)
{
	//sf::Vector2f bounds = m_player.getOrigin();
	sf::Vector2f playerPos = m_player.getPosition();

	//playerPos.x += bounds.x / 2;
	//playerPos.y += bounds.y / 2;

	//double mouseAngle = -atan2((t_mousePos.x - playerPos.x), t_mousePos.y - playerPos.y) * 180.0f / 3.14159; //angle in degrees of rotation for sprite

	//m_player.setRotation(mouseAngle);

	float dx = playerPos.x - t_mousePos.x;
	float dy = playerPos.y - t_mousePos.y;

	float rotation = (-atan2(dx,dy)) * 180 / PI;

	m_player.setRotation(rotation + 180);

}

void Player::checkForPlayerMovement()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player.move(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.move(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.move(0, speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.move(speed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		speed = 1;
	}
	else
	{
		speed = 0.5;
	}

}

