#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceManager.h"
class Player;
class Bee;
class Fly;
class Fairy;
class Fireball;
class Candy;
class Ring;
class Wall;

class DynamicGameObject;
class StaticGameObject;

class GameObject
{
public:
	GameObject(sf::Vector2f pos);
	
	virtual void draw(sf::RenderWindow &) = 0;
	virtual sf::Vector2f get_position() const = 0;
	virtual const sf::Sprite &get_pic() const =0;

	GameObject();

	
	~GameObject();

protected:
	sf::Vector2f m_position;
	
};

