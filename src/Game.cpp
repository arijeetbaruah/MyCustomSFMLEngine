#include "../include/Game.hpp"
#include "../include/SceneStateManager.hpp"

Game::Game()
{
	m_sceneStateManager = new SceneStateManager();
}

void Game::AddEntity(Entity* entity)
{
	m_entities.emplace(entity->GetID(), entity);
}

void Game::Update(sf::RenderWindow& window, float deltaTime)
{
	for (auto& entity : m_entities)
	{
		entity.second->Update(window, deltaTime);
	}

	m_sceneStateManager->OnUpdate(window, deltaTime);
}

void Game::Draw(sf::RenderWindow& window)
{
	for (auto& entity : m_entities)
	{
		entity.second->Render(window);
	}

	m_sceneStateManager->OnRender(window);
}
