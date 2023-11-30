#include "../include/BaseStateManager.hpp"
#include "../include/BaseStateManager.hpp"

void BaseStateManager::SetState(BaseState* state)
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

void BaseStateManager::OnUpdate(sf::RenderWindow& window, float deltaTime)
{
	if (m_current_state != nullptr)
	{
		m_current_state->OnUpdate(window, deltaTime);
	}
}

void BaseStateManager::OnRender(sf::RenderWindow& window)
{
	if (m_current_state != nullptr)
	{
		m_current_state->OnRender(window);
	}
}
