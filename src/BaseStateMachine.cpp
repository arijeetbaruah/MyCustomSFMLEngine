#include "../include/BaseStateMachine.hpp"

BaseStateMachine::BaseStateMachine(Game* game) : m_current_state(nullptr), m_game(game)
{
}

void BaseStateMachine::SetState(BaseState* state)
{
	if (m_current_state != nullptr)
	{
		m_current_state->OnExit();
	}

	m_current_state = state;

	if (m_current_state != nullptr)
	{
		m_current_state->OnStart();
	}
}

void BaseStateMachine::OnUpdate(sf::RenderWindow& window, float deltaTime)
{
	if (m_current_state != nullptr)
	{
		m_current_state->OnUpdate(window, deltaTime);
	}
}

void BaseStateMachine::OnRender(sf::RenderWindow& window)
{
	if (m_current_state != nullptr)
	{
		m_current_state->OnRender(window);
	}
}
