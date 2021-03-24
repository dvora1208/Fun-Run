#pragma once
#include "PlayerState.h"
#include "StandingState.h"

class Player;


class WalkLeftState :
	public PlayerState
{
public:
	WalkLeftState();
	std::unique_ptr<PlayerState> handleInput(Input input);
	void enter(Player& player);
	~WalkLeftState() {};
};

