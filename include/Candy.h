#pragma once
#include "Collectable.h"
class Candy :
	public Collectable
{
public:
	Candy(sf::Vector2f pos);
	void draw(sf::RenderWindow&);
	sf::Vector2f get_position() const;


	~Candy();

private:
	

};

