#include "Player.h"

Player::Player()
{

	loadAssets();

	m_player.setTexture(m_playerTexture);

	m_player.setPosition((Globals::SCREEN_X / 2), (Globals::SCREEN_Y - 150));
	m_player.setOrigin((m_player.getGlobalBounds().width / 2), (m_player.getGlobalBounds().height / 2));
	m_player.setScale(0.1f, 0.1f);
	//std::cout << "player created" <<std::to_string(m_player.getOrigin().x) << " " << std::to_string(m_player.getOrigin().y) << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::loadAssets()
{
	if (!m_playerTexture.loadFromFile("ASSETS/SPRITES/PLAYER/playerTest.png"))
	{
		std::cout << "Error with loading player texture file (playerTest)";
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::update(const sf::RenderWindow& t_window, bool t_colliding)
{
	mousePos = sf::Mouse::getPosition(t_window);
	rotatePlayer(mousePos);
	checkForPlayerMovement(t_colliding);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_player);
}

/// <summary>
/// Function rotates the player so they are always looking at where the mouse is 
/// </summary>
/// <param name="t_mousePos"></param>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::rotatePlayer(sf::Vector2i t_mousePos)
{
	sf::Vector2f playerPos = m_player.getPosition();

	float dx = playerPos.x - t_mousePos.x;
	float dy = playerPos.y - t_mousePos.y;

	double mouseAngle = static_cast<double>(-atan2(dx, dy)) * 180.0f / PI; //finding the angle that the mouse is at vs the players location

	m_player.setRotation(mouseAngle + 180.0f);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::checkForPlayerMovement(bool t_colliding)
{
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (t_colliding == false)
			{
				m_player.move(0, -speed);
			}
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (t_colliding == false)
			{
				m_player.move(-speed, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (t_colliding == false)
			{
				m_player.move(0, speed);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (t_colliding == false)
			{
				m_player.move(speed, 0);
			}
		}

	sprint();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::sprint()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) //doubling the speed when the user is sprinting
	{
		speed = 1;
	}
	else
	{
		speed = 0.5;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::takeDamage(int t_damageAmount)
{
	m_playerHealth -= t_damageAmount;
}
