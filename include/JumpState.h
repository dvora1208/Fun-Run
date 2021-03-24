#pragma once
#include "PlayerState.h"
#include "StandingState.h"

class Player;

class JumpState :
	public PlayerState
{
public:
	JumpState();
	std::unique_ptr<PlayerState> handleInput(Input input);
	void enter(Player& player);
	~JumpState() {};


};

