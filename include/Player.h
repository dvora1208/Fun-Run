#pragma once
#include "Character.h"
#include "PlayerState.h"
#include "StandingState.h"
#include <math.h>
#include "Constants.h"


class Wall;


class Player : public Character
{
public:
	Player(sf::Vector2f pos, sf::RenderWindow &);
	void draw(sf::RenderWindow &);
	sf::Vector2f get_position() const;
	const sf::Sprite &get_pic() const;
	void SetPlayerPos(const sf::Vector2f &pos);
	void HandleInput(Input input);
	void PlayerMoveRight();
	void PlayerMoveLeft();
	void PlayerJump();
	void animate();

	void SetPreviousPosition(sf::Vector2f);
	sf::Vector2f GetPreviousPosition() const;
	float Get_Mass()const;
	float Get_JumpHeight()const;
	void SetSpeedValue(float new_speed);
	void SetFallSpeedValue(float new_speed);
	void set_face(bool);
	void falling();
	void flip_pic_left();
	void flip_pic_right();
	void load_stand_image();
	void move_in_jump();
	void SetWhileJump(const bool);
	bool GetWhileJump() const;
	void set_delta_time(float new_time); 
	 int GetLife() const;
	 void SetLife(int);
	 int GetEatenCandys()const;
	 void SetEatenCandys(int);
	 int GetScore()const;
	 void SetScore(int);
	 bool GetHit() const;
	 void SetHit(bool);
	 void InStrike();
	~Player();

private:
	bool faceright;  // check which sidec the player face 
	bool m_while_jump; // check if the player jumping
	float m_delta_time;// in order to calculte the movement
	int m_index_jump_animation; // store the index in animation vector
	std::unique_ptr <PlayerState> m_state; // according the design pattren state
	sf::RenderWindow & m_window; 
	std::vector< std::unique_ptr<sf::Texture> > m_jumping_animation;
	float m_jump_height; // for the calculation of the jump
	float m_gravity_acceleration; // for the calculation of the jump
	float m_mass, // for the calculation of the jump
		m_speed_value, // for the calculation of the jump
		m_fall_speed_value, // for the calculation of the gravity
		m_acceleration_value;
	int m_eaten_candys; // the number of eaten candys
	int m_player_score; // player score
	bool m_hit; // check if the player got hit by enemy
	sf::Clock m_HitClock; // clock for the player flashing
	void strike(); // in charge of making the player flash
	
};

