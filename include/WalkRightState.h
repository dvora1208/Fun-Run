#pragma once
#include "PlayerState.h"
#include "StandingState.h"

class Player;

class WalkRightState :
	public PlayerState
{
public:
	WalkRightState();
	std::unique_ptr<PlayerState> handleInput(Input input);
	void enter(Player& player);
	~WalkRightState() {};
};

