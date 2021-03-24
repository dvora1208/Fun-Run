#pragma once
#include "PlayerState.h"
#include "WalkRightState.h"
#include "WalkLeftState.h"
#include "JumpState.h"

class Player;

class StandingState :
	public PlayerState
{
public:
	StandingState();
	std::unique_ptr<PlayerState> handleInput(Input input);
	void enter(Player& player);
	~StandingState() {};
};

