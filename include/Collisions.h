#pragma once
#include <map>
#include "GameObject.h"
#include "Player.h"
#include "Wall.h"
#include "Grass.h"
#include <iostream>
#include "GameStatus.h"
#include "Fairy.h"
#include <exception>

class GameObject;
class Player;
class Wall;
class Grass;
class Spikes;
class Bee;
//-------------------------typedf-----------------------------------------
using HitFunctionPtr = void(*)(GameObject&, GameObject&);
using Key = std::pair<std::string, std::string >;
using HitMap = std::map<Key, HitFunctionPtr>;

//------------------------------protypes-------------------------------

void player_vs_wall(GameObject & player, GameObject& wall);
void player_vs_grass(GameObject & player, GameObject & grass);
void player_vs_Bee(GameObject & player, GameObject & Bee);
void player_vs_fly(GameObject & player, GameObject & fly);
void player_vs_candy(GameObject & player, GameObject & candy);
void player_vs_ring(GameObject & player, GameObject & ring);
void fly_vs_wall(GameObject & fly, GameObject & wall);
void Bee_vs_wall(GameObject & Bee, GameObject & wall);
void Bee_vs_grass(GameObject & Bee, GameObject & grass);
void fly_vs_grass(GameObject & fly, GameObject & grass);

void wall_vs_player(GameObject & wall, GameObject & player);
void grass_vs_player(GameObject & grass, GameObject & player);
void Bee_vs_player(GameObject & Bee, GameObject & player);
void fly_vs_player(GameObject & fly, GameObject & player);
void ring_vs_player(GameObject & ring, GameObject & player);
void candy_vs_player(GameObject & candy, GameObject & player);
void wall_vs_Bee(GameObject & wall, GameObject & Bee);
void wall_vs_fly(GameObject & wall, GameObject & fly);
void grass_vs_Bee(GameObject & grass, GameObject & Bee);
void grass_vs_fly(GameObject & grass, GameObject & fly);

void fairy_vs_grass(GameObject & fairy, GameObject & grass);
void grass_vs_fairy(GameObject & grass, GameObject & fairy);
void fairy_vs_wall(GameObject & fairy, GameObject & wall);
void wall_vs_fairy(GameObject & wall, GameObject & fairy);
void fairy_vs_player(GameObject & fairy, GameObject & player);
void player_vs_fairy(GameObject & player, GameObject & fairy);

void processCollision(GameObject& object1, GameObject& object2);
bool collide_with(GameObject& a, GameObject& b);

HitMap  initializeCollisionMap();
HitFunctionPtr lookup(const std::string& class1, const std::string& class2);

//-----------------------------------------------------------------------------

// this function lookup for collison function between two string which represent objects
HitFunctionPtr lookup(const std::string& class1, const std::string& class2)
{
	static HitMap collisionMap = initializeCollisionMap();
	auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
	if (mapEntry == collisionMap.end())
	{
		return nullptr;
	}
	return mapEntry->second;
}


// this function handle the collision between two game objects
void processCollision(GameObject& object1, GameObject& object2)
{

	auto phf = lookup(typeid(object1).name(), typeid(object2).name());
	if (!phf)
	{
		throw std::runtime_error("no collision function for the objects");
	}
	phf(object1, object2);

}



void fly_vs_wall(GameObject & fly, GameObject & wall)
{
	wall_vs_fly(wall, fly);

}


void Bee_vs_wall(GameObject & Bee, GameObject & wall)
{
	wall_vs_Bee(wall, Bee);

}

void Bee_vs_grass(GameObject & Bee, GameObject & grass)
{

	grass_vs_Bee(grass, Bee);
}

void fly_vs_grass(GameObject & fly, GameObject & grass)
{

	grass_vs_fly(grass, fly);
}



void player_vs_candy(GameObject & player, GameObject & candy)
{

	candy_vs_player(candy, player);

}


void player_vs_ring(GameObject & player, GameObject & ring)
{
	ring_vs_player(ring, player);
}


void player_vs_fly(GameObject & player, GameObject & fly)
{
	fly_vs_player(fly, player);
}

void player_vs_Bee(GameObject & player, GameObject & Bee)
{
	Bee_vs_player(Bee, player);
}

void player_vs_wall(GameObject & player, GameObject & wall)
{
	wall_vs_player(wall, player);
}

void player_vs_grass(GameObject & player, GameObject & grass)
{
	grass_vs_player(grass, player);
}


void wall_vs_player(GameObject & wall, GameObject & player)
{

	Player& the_player = dynamic_cast<Player&>(player);
	the_player.SetPlayerPos(the_player.GetPreviousPosition()); // replacing the player to previous position
}

void grass_vs_player(GameObject & grass, GameObject & player)
{
	
	Player& the_player = dynamic_cast<Player&>(player);
	the_player.SetPlayerPos(the_player.GetPreviousPosition()); // replacing the player to previous position

}


void Bee_vs_player(GameObject & bee, GameObject & player)
{
	Player& the_player = dynamic_cast<Player&>(player);
	Bee & the_bee = dynamic_cast< Bee &>(bee);

	if (the_player.GetWhileJump()) // check if in jump state
	{
		the_bee.SetLife(0);
	}
	else if(!the_player.GetHit()) // in order to make the player flashing awhen get hit
	{
		the_player.SetLife(the_player.GetLife()-1); 
		the_player.SetHit(true);
	}
}

void fly_vs_player(GameObject & fly, GameObject & player)
{
	Player& the_Player = dynamic_cast<Player&>(player);
	Fly & the_fly = dynamic_cast<Fly &>(fly);

	if (the_Player.GetWhileJump())// check if in jump state
	{
		the_fly.SetLife(0);
	}

	else if(!the_Player.GetHit())
	{
		the_Player.SetLife(the_Player.GetLife() - 1);
		the_Player.SetHit(true);
	}
}


void ring_vs_player(GameObject & ring, GameObject & player)
{
	
	Player& the_Player = dynamic_cast<Player&>(player);
	the_Player.SetScore(the_Player.GetScore()+100); // collision with ring gives the player score

	
}


void candy_vs_player(GameObject& candy, GameObject& player)
{
	
	Player& the_Player = dynamic_cast<Player&>(player);
	the_Player.SetEatenCandys(the_Player.GetEatenCandys()+1);
	the_Player.SetScore(the_Player.GetScore() + 1000); // collision with diamons gives the player score
}

void wall_vs_Bee(GameObject & wall, GameObject & bee)
{
	Bee& the_carb = dynamic_cast<Bee&>(bee);
	the_carb.SetPosition(the_carb.GetPreviousPos());


}

void wall_vs_fly(GameObject & wall, GameObject & fly)
{
	Fly & the_fly = dynamic_cast<Fly &>(fly);
	the_fly.SetPosition(the_fly.GetPreviousPos()); // relocate fly to previous position

}

void grass_vs_Bee(GameObject & grass, GameObject & bee)
{
	Bee & the_bee = dynamic_cast<Bee &>(bee);
	the_bee.SetPosition(the_bee.GetPreviousPos());  // relocate Bee to previous position

}

void grass_vs_fly(GameObject & grass, GameObject & fly )
{
	Fly & the_fly = dynamic_cast< Fly &>(fly);
	the_fly.SetPosition(the_fly.GetPreviousPos()); // relocateflye to previous position

}

void fairy_vs_grass(GameObject & fairy, GameObject & grass)
{
	grass_vs_fairy(grass, fairy);
}

void grass_vs_fairy(GameObject & grass, GameObject & fairy)
{
	
}

void fairy_vs_wall(GameObject & fairy, GameObject & wall)
{
	wall_vs_fairy(wall, fairy);
}

void wall_vs_fairy(GameObject & wall, GameObject & fairy)
{
	
}

void fairy_vs_player(GameObject & fairy, GameObject & player)
{
	player_vs_fairy(player, fairy);
}

void player_vs_fairy(GameObject & player, GameObject & fairy)
{
	Player& the_Player = dynamic_cast<Player&>(player);
	Fairy & the_fly = dynamic_cast<Fairy &>(fairy);

	if (the_Player.GetWhileJump())// check if in jump state
	{
		the_fly.SetLife(0);
	}
	else if (!the_Player.GetHit())
	{
		the_Player.SetLife(the_Player.GetLife() - 1);
		the_Player.SetHit(true);
	}
}

//initlize map

HitMap  initializeCollisionMap()
{
	HitMap phm;
	phm[Key(typeid(Wall).name(), typeid(Player).name())] = &wall_vs_player;
	phm[Key(typeid(Grass).name(), typeid(Player).name())] = &grass_vs_player;
	phm[Key(typeid(Player).name(), typeid(Wall).name())] = &player_vs_wall;
	phm[Key(typeid(Player).name(), typeid(Grass).name())] = &player_vs_grass;
	phm[Key(typeid(Player).name(), typeid(Bee).name())] = &player_vs_Bee;
	phm[Key(typeid(Bee).name(), typeid(Player).name())] = &Bee_vs_player;
	phm[Key(typeid(Player).name(), typeid(Fly).name())] = &player_vs_fly;
	phm[Key(typeid(Fly).name(), typeid(Player).name())] = &fly_vs_player;
	phm[Key(typeid(Ring).name(), typeid(Player).name())] = &ring_vs_player;
	phm[Key(typeid(Player).name(), typeid(Ring).name())] = &player_vs_ring;
	phm[Key(typeid(Player).name(), typeid(Candy).name())] = &player_vs_candy;
	phm[Key(typeid(Candy).name(), typeid(Player).name())] = &candy_vs_player;
	phm[Key(typeid(Bee).name(), typeid(Wall).name())] = &Bee_vs_wall;
	phm[Key(typeid(Wall).name(), typeid(Bee).name())] = &wall_vs_Bee;
	phm[Key(typeid(Fly).name(), typeid(Wall).name())] = &fly_vs_wall;
	phm[Key(typeid(Wall).name(), typeid(Fly).name())] = &wall_vs_fly;
	phm[Key(typeid(Bee).name(), typeid(Grass).name())] = &Bee_vs_grass;
	phm[Key(typeid(Grass).name(), typeid(Bee).name())] = &grass_vs_Bee;
	phm[Key(typeid(Fly).name(), typeid(Grass).name())] = &fly_vs_grass;
	phm[Key(typeid(Grass).name(), typeid(Fly).name())] = &grass_vs_fly;
	phm[Key(typeid(Fairy).name(), typeid(Grass).name())] = &fairy_vs_grass;
	phm[Key(typeid(Grass).name(), typeid(Fairy).name())] = &grass_vs_fairy;
	phm[Key(typeid(Fairy).name(), typeid(Wall).name())] = &fairy_vs_wall;
	phm[Key(typeid(Wall).name(), typeid(Fairy).name())] = &wall_vs_fairy;
	phm[Key(typeid(Fairy).name(), typeid(Player).name())] = &fairy_vs_player;
	phm[Key(typeid(Player).name(), typeid(Fairy).name())] = &player_vs_fairy;
	return phm;
}

// this function gets to game object and check if they overlap
bool collide_with(GameObject& a, GameObject& b)
{
	sf::FloatRect charater = a.get_pic().getGlobalBounds();
	sf::FloatRect wallRect = b.get_pic().getGlobalBounds();

	if (charater.left < (wallRect.left + wallRect.width) && charater.top < (wallRect.top + wallRect.height) &&
		wallRect.left < (charater.left + charater.width) && wallRect.top < (charater.top + charater.height))
	{
		return true;
	}
	return false;
}
