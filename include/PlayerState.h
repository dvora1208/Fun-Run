#pragma once
#include <memory>


class Player;

enum Input
{
	PRESS_UP,
	PRESS_DOWN,
	PRESS_LEFT,
	PRESS_RIGHT,
	PRESS_SPACE,
	END_OF_TIMER,
	RELEASE_DOWN,
	RELEASE_RIGHT,
	RELEASE_LEFT,
	RELEASE_UP
};


class PlayerState
{
public:
	
	virtual ~PlayerState() { }
	virtual std::unique_ptr<PlayerState>	handleInput(Input input) = 0;
	virtual void enter(Player& player) = 0;
	
};

