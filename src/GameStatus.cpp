#include "GameStatus.h"



GameStatus::GameStatus()
	:m_lives(5), m_score(0), m_candys(0)
{
}


GameStatus::~GameStatus()
{
}

// gets score 
int GameStatus::get_score()
{
	return m_score;
}
// sets score
void GameStatus::set_score(int score)
{
	m_score = score;
}
// this function in charge of preseting the game status on the screen
void GameStatus::draw(std::shared_ptr <Player> & player, sf::RenderWindow & window, sf::Vector2f center_of_view, int candys_in_levels, int level)
{
	sf::Vector2f UpLeftCorner;
	UpLeftCorner.y = center_of_view.y - 270;
	UpLeftCorner.x = center_of_view.x - 320;
	

	m_lives = player->GetLife();
	m_candys = player->GetEatenCandys();
	m_score = player->GetScore();

	std::ostringstream os_score,
		os_lives, os_candys;

	sf::Text game_score,
		lives,
		candys;

	os_score << "Level: " << level << "  Score: " << m_score;
	os_lives << "Lives: " << m_lives;
	os_candys << "My Candys: " << m_candys <<"/" << candys_in_levels;

	lives.setCharacterSize(25);   
	game_score.setCharacterSize(25);
	candys.setCharacterSize(25);

	game_score.setPosition(UpLeftCorner);
	lives.setPosition({ UpLeftCorner.x, UpLeftCorner.y + 30 });
	candys.setPosition({ UpLeftCorner.x, UpLeftCorner.y + 60 });

	game_score.setFont(ResourceManager::instance().GetFont());
	lives.setFont(ResourceManager::instance().GetFont());
	candys.setFont(ResourceManager::instance().GetFont());

	game_score.setFillColor(sf::Color::White);
	lives.setFillColor(sf::Color::White);
	candys.setFillColor(sf::Color::White);

	game_score.setString(os_score.str());
	lives.setString(os_lives.str());
	candys.setString(os_candys.str());


	window.draw(game_score);
	window.draw(lives);
	window.draw(candys);

}
