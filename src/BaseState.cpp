#include "../include/BaseState.hpp"
#include "../include/Game.hpp"
#include "../include/BaseStateMachine.hpp"

BaseState::BaseState(Game* game, BaseStateMachine* stateMachine) : m_game(game), m_stateMachine(stateMachine)
{
}

BaseState::~BaseState()
{
	delete m_game;

	m_game = nullptr;
}
