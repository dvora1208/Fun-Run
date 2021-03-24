#include "JumpState.h"
#include "Player.h"



JumpState::JumpState()
{
}

std::unique_ptr<PlayerState> JumpState::handleInput(Input input)
{
	// according the state diagram


	switch (input)
	{
	case PRESS_SPACE:
		return std::make_unique<JumpState>();
		break;
	case END_OF_TIMER:
		return std::make_unique<StandingState>();
		break;

	default:
		return std::make_unique<JumpState>();
		break;
	}



}

// this function in charge of loading the correct picture according the state
// and move the player

void JumpState::enter(Player& player)
{

	player.PlayerJump();
	player.animate();
}

