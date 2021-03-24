#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "GameObject.h"
#include "Wall.h"
#include "Grass.h"
#include "Player.h"
#include "Ring.h"
#include "Candy.h"
#include"Fly.h"
#include "Bee.h"
#include "StaticGameObject.h"
#include "DynamicGameObject.h"
#include "Collectable.h"

class StageLoader
{
public:
	StageLoader();
	
	void LoadMap(const std::string & namefile, std::shared_ptr <Player>& m_player,
		std::vector < std::vector < std::unique_ptr<StaticGameObject> >  > * m_static_object,
		std::vector < std::unique_ptr<Enemy> > * m_enemy, sf::RenderWindow&,
		std::vector < std::unique_ptr<Collectable> >*  m_collectable);
	void DrawMap(sf::RenderWindow & window,  std::vector < std::vector < std::unique_ptr<StaticGameObject> >  > * m_static_object,
		std::vector < std::unique_ptr<Enemy> >* m_enemy, std::vector < std::unique_ptr<Collectable> >*  m_collectable);
	int GetNumRows() const;
	int GetNumCols() const;
	int GetLevelCandys() const;
	~StageLoader();

private:
	
	
	int m_level_candys;

	int m_stage_x, //(y) cols
		m_stage_y; //(x) rows
	sf::Sprite m_background;
};

