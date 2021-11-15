#include "Options.h"

Options::Options()
{

	loadAssets();
	m_optionsText.setFont(m_font);

	m_optionsText.Bold;
	m_optionsText.setFont(m_font);
	m_optionsText.setCharacterSize(32u);
	m_optionsText.setPosition(300, 300);;
	m_optionsText.setFillColor(sf::Color::Black);
	m_optionsText.setString("This is where the player will see the options for the game. \nEventually, all of the levels will be shown here \nThey will be greyed out at first but as the player finishes them \nthey will become  coloured, basically they are available to be played");

}

void Options::loadAssets()
{

	if (!m_font.loadFromFile("./ASSETS/FONTS/arial.ttf"))
	{
		std::cout << "Error loading font..." << std::endl;
	}


}

void Options::update()
{
}

void Options::render(sf::RenderWindow& t_window)
{
	t_window.clear(sf::Color::Magenta);
	t_window.draw(m_optionsText);
}
