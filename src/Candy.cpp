#include "Candy.h"



Candy::Candy(sf::Vector2f pos)
	:Collectable(pos)
{
	m_pic.setTexture(ResourceManager::instance().GetTexture(CANDY)); // set picture
	m_pic.setPosition(pos); // set position
	m_pic.setOrigin(m_pic.getGlobalBounds().width / 2, m_pic.getGlobalBounds().height / 2); // center of pic
}

// draw pic
void Candy::draw(sf::RenderWindow & window)
{
	window.draw(m_pic);
}

// get position
sf::Vector2f Candy::get_position() const
{
	return m_position;
}


Candy::~Candy()
{
}
